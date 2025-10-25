@echo off
setlocal enabledelayedexpansion

call build.bat

set BENCHMARK_MODE=0
if "%1"=="--benchmark" set BENCHMARK_MODE=1
if "%1"=="-bm" set BENCHMARK_MODE=1
if "%1"=="-b" set BENCHMARK_MODE=1
if "%1"=="-v" set BENCHMARK_MODE=1

if %BENCHMARK_MODE%==1 (
    echo.
    echo EXECUTION WITH BENCHMARKING RESULT:
    echo.
    for /L %%i in (1,1,10) do (
        if exist main\input_%%i.txt (
            for /f "usebackq delims=" %%A in (`powershell -NoProfile -Command "Get-Content 'main/input_%%i.txt' -TotalCount 1"`) do set "first_line=%%A"
            if not "!first_line!"=="" if not "!first_line!"=="!IGNORE" (
                echo Running test %%i with timing...
                powershell -Command "Measure-Command { Get-Content main\input_%%i.txt | .\build\Debug\ccpp.exe } | Select-Object TotalMilliseconds"

                for /f "delims=" %%a in ('powershell -Command "Get-Content main\input_%%i.txt | Select-Object -Last 1"') do set expected=%%a
                for /f "delims=" %%a in ('type main\input_%%i.txt ^| build\Debug\ccpp.exe') do set actual=%%a

                if "!actual!"=="!expected!" (
                    echo TEST %%i PASSED!
                ) else (
                    echo TEST %%i FAILED! - WRONG ANSWER - EXPECTED: !expected!
                )
            )
        ) else (
            goto overall_test
        )
    )
)

:overall_test
echo.
echo OVERALL TEST RESULT:
echo.
for /L %%i in (1,1,10) do (
    if exist main\input_%%i.txt (
        for /f "usebackq delims=" %%A in (`powershell -NoProfile -Command "Get-Content 'main/input_%%i.txt' -TotalCount 1"`) do set "first_line=%%A"
        if not "!first_line!"=="" if not "!first_line!"=="!IGNORE" (
            for /f "delims=" %%a in ('powershell -Command "Get-Content main\input_%%i.txt | Select-Object -Last 1"') do set expected=%%a
            for /f "delims=" %%a in ('type main\input_%%i.txt ^| build\Debug\ccpp.exe') do set actual=%%a

            if "!actual!"=="!expected!" (
                echo TEST %%i PASSED!
            ) else (
                echo TEST %%i FAILED! - WRONG ANSWER - EXPECTED: !expected!
            )
        )
    ) else (
        goto end
    )
)

:end
endlocal