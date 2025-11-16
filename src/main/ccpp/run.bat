@echo off
setlocal

set "ERR=0"

pushd "%~dp0" >nul 2>&1

set "FILE=main/input.txt"
if not "%~1"=="" (
  set "FILE=main/input_%~1.txt"
)

call "%~dp0clean.bat"
set "ERR=%ERRORLEVEL%"
if not "%ERR%"=="0" goto finish

cmake -S . -B build -DCMAKE_RUNTIME_OUTPUT_DIRECTORY:PATH="%cd%"
set "ERR=%ERRORLEVEL%"
if not "%ERR%"=="0" goto finish

cmake --build build
set "ERR=%ERRORLEVEL%"
if not "%ERR%"=="0" goto finish

rem Move executable to ./ccpp.exe (Windows requires .exe extension)
if exist ".\Debug\ccpp.exe" (
  move /Y ".\Debug\ccpp.exe" ".\ccpp.exe" >nul
) else if exist ".\Release\ccpp.exe" (
  move /Y ".\Release\ccpp.exe" ".\ccpp.exe" >nul
)

.\ccpp.exe < "%FILE%"
set "ERR=%ERRORLEVEL%"

:finish
popd >nul 2>&1
endlocal & exit /b %ERR%
