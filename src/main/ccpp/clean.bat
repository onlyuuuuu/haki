@echo off
setlocal

REM Clean existing ninja artifacts quietly; ignore failures if ninja is absent
ninja clean >nul 2>&1

REM Remove generated files
for %%F in (
  "CMakeCache.txt"
  "CMakeSettings.json"
  "ccpp"
  "ccpp.exe"
  "cmake_install.cmake"
  "Makefile"
) do (
  if exist %%~F del /f /q %%~F >nul 2>&1
)

REM Remove generated directories
for %%D in (
  "build"
  "target"
  "cmake-build-default"
  "cmake-build-debug"
  "CMakeFiles"
) do (
  if exist %%~D rmdir /s /q %%~D >nul 2>&1
)

cmake .
if errorlevel 1 goto finish

cmake --build . --target clean

:finish
set "ERR=%errorlevel%"
endlocal & exit /b %ERR%
