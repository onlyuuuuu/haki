@echo off
setlocal

REM Remove directories (quietly, recursively)
for %%D in (
  ".cmake"
  "cmake-build-debug"
  "CMakeFiles"
  "Testing"
  "sandbox"
) do (
  if exist "%%~D" rmdir /s /q "%%~D"
)

REM Remove files
for %%F in (
  "ccpp.exe"
  "ccpp"
  "cmake_install.cmake"
  "CMakeCache.txt"
  "Makefile"
) do (
  if exist "%%~F" del /f /q "%%~F"
)

REM Remove any *.dSYM directories (macOS artifacts checked in accidentally)
for /d %%G in ("*.dSYM") do (
  if exist "%%~G" rmdir /s /q "%%~G"
)

endlocal
