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

set "UNAME="
for /f "delims=" %%u in ('uname -a 2^>nul') do set "UNAME=%%u"

set "IS_DARWIN=0"
set "IS_MINGW=0"
if defined UNAME (
  echo(%UNAME%| findstr /i "Darwin" >nul && set "IS_DARWIN=1"
  echo(%UNAME%| findstr /i "MINGW" >nul && set "IS_MINGW=1"
)

if "%IS_DARWIN%"=="1" (
  cmake -S . -B build
) else (
  cmake --build .
)
set "ERR=%ERRORLEVEL%"
if not "%ERR%"=="0" goto finish

set "APP="
if "%IS_MINGW%"=="1" (
  if exist ".\ccpp.exe" set "APP=.\ccpp.exe"
)
if not defined APP if exist ".\build\ccpp.exe" set "APP=.\build\ccpp.exe"
if not defined APP if exist ".\ccpp" set "APP=.\ccpp"

if defined APP (
  "%APP%" < "%FILE%"
  set "ERR=%ERRORLEVEL%"
) else (
  echo Failed to locate executable.
  set "ERR=1"
)

:finish
popd >nul 2>&1
endlocal & exit /b %ERR%
