@echo off
setlocal enabledelayedexpansion

set "BUILD_DIR=build"

REM Clean option to remove old in-source CMake artifacts and build dir
if /I "%1"=="clean" (
  if exist "CMakeCache.txt" del /q "CMakeCache.txt"
  if exist "cmake_install.cmake" del /q "cmake_install.cmake"
  if exist "Makefile" del /q "Makefile"
  if exist "CMakeFiles" rmdir /s /q "CMakeFiles"
  if exist "!BUILD_DIR!" rmdir /s /q "!BUILD_DIR!"
  exit /b 0
)

if not exist "%BUILD_DIR%" mkdir "%BUILD_DIR%"

REM Configure out-of-source to avoid path/cache mismatches
cmake -S . -B "%BUILD_DIR%"
if errorlevel 1 exit /b %errorlevel%

REM Build the configured tree
cmake --build "%BUILD_DIR%" --parallel
exit /b %errorlevel%
