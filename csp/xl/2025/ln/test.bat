@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM Resolve the directory of this BAT file (same folder as test.ps1)
set "SCRIPT_DIR=%~dp0"

REM If no arguments, print usage
if "%~1"=="" (
  echo Usage: %~n0 ^<program_directory^> ^<program_name^> [source_file]
  echo.
  echo Example 1: %~n0 count count
  echo Example 2: %~n0 count count count-dad.cpp
  goto :eof
)

REM Forward all arguments to PowerShell script
powershell -NoProfile -ExecutionPolicy Bypass -File "%SCRIPT_DIR%test.ps1" %*

REM Preserve exit code from PowerShell
set "EXIT_CODE=%ERRORLEVEL%"
exit /b %EXIT_CODE%

