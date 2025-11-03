@echo off
setlocal EnableExtensions

cmake .
cmake --build . --target clean

set "RUN_BENCHMARK=0"
set "arg=%~1"
if /I "%arg%"=="--benchmark" set "RUN_BENCHMARK=1"
if /I "%arg%"=="-bm" set "RUN_BENCHMARK=1"
if /I "%arg%"=="-b" set "RUN_BENCHMARK=1"
if /I "%arg%"=="-v" set "RUN_BENCHMARK=1"

powershell -NoLogo -NoProfile -ExecutionPolicy Bypass -Command ^
  "& { $ErrorActionPreference = 'Stop'; $benchmark = $env:RUN_BENCHMARK -eq '1'; $maxTests = 10; $exePath = Join-Path (Get-Location) 'ccpp.exe'; function Get-FirstLine([string]$path) { $reader = [System.IO.File]::OpenText($path); try { return $reader.ReadLine() } finally { $reader.Dispose() } }; function Get-LastLine([string]$path) { $tail = Get-Content -Tail 1 -Encoding UTF8 -ErrorAction Stop $path; if ($null -eq $tail) { return '' } else { return ($tail | Select-Object -Last 1) } }; function NormalizeLastLine([string]$text) { if ($null -eq $text) { return '' }; $normalized = ($text -replace \"`r`n\", \"`n\"); $normalized = $normalized.TrimEnd(\"`n\", \"`r\"); if ($normalized.Length -eq 0 -and $text.Length -gt 0) { return '' }; $parts = $normalized -split \"`n\"; return $parts[$parts.Length - 1] }; function Invoke-Program([string]$inputPath) { $psi = New-Object System.Diagnostics.ProcessStartInfo; $psi.FileName = $exePath; $psi.UseShellExecute = $false; $psi.RedirectStandardInput = $true; $psi.RedirectStandardOutput = $true; $psi.RedirectStandardError = $true; $psi.CreateNoWindow = $true; $process = New-Object System.Diagnostics.Process; $process.StartInfo = $psi; $inputData = [System.IO.File]::ReadAllText($inputPath); $process.Start() | Out-Null; $sw = [System.Diagnostics.Stopwatch]::StartNew(); $process.StandardInput.Write($inputData); $process.StandardInput.Close(); $output = $process.StandardOutput.ReadToEnd(); $process.WaitForExit(); $sw.Stop(); return [PSCustomObject]@{ Output = $output; Duration = $sw.Elapsed; ExitCode = $process.ExitCode } }; function Run-Test([int]$index, [bool]$showTiming) { $inputPath = [System.IO.Path]::Combine('main', \"input_$index.txt\"); if (-not (Test-Path $inputPath)) { return $false }; $firstLine = Get-FirstLine $inputPath; if ($firstLine -eq $null) { return $false }; if ($firstLine.Length -eq 0 -or $firstLine -eq '!IGNORE') { return $false }; $expected = Get-LastLine $inputPath; if ($expected -eq $null) { $expected = '' }; $result = Invoke-Program $inputPath; if ($showTiming) { if ($result.Output.Length -gt 0) { [Console]::Write($result.Output); if (-not $result.Output.EndsWith(\"`n\")) { [Console]::WriteLine() } }; Write-Host ('Elapsed: {0:N3} ms' -f $result.Duration.TotalMilliseconds) }; $actualLine = NormalizeLastLine $result.Output; if ($actualLine -ceq $expected) { Write-Host ('TEST {0} PASSED!' -f $index) } else { Write-Host ('TEST {0} FAILED! - WRONG ANSWER' -f $index); Write-Host ('  Expected: {0}' -f $expected); Write-Host ('  Actual:   {0}' -f $actualLine) }; return $true }; if ($benchmark) { Write-Host ''; Write-Host 'EXECUTION WITH BENCHMARKING RESULT:'; Write-Host ''; for ($i = 1; $i -le $maxTests; $i++) { if (-not (Run-Test -index $i -showTiming $true)) { break } } }; Write-Host ''; Write-Host 'OVERALL TEST RESULT:'; Write-Host ''; for ($i = 1; $i -le $maxTests; $i++) { if (-not (Run-Test -index $i -showTiming $false)) { break } } }"

endlocal
