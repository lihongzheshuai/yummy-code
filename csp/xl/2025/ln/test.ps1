# Test script: Automatically test all test data files in the data folder
# Usage: Run in PowerShell: .\test.ps1 <program_directory> [source_file]
#   Example: .\test.ps1 count count-dad.cpp
#   If source_file is provided, the script will compile it first with C++11 and O2 optimization
#   If source_file is not provided, the script will look for executable files in the specified program directory

param(
    [Parameter(Mandatory=$true)]
    [string]$ProgramDirectory,
    
    [Parameter(Mandatory=$false)]
    [string]$SourceFile = ""
)

$ErrorActionPreference = "Stop"

# Get the script directory (ln directory)
$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $scriptDir

# Resolve program directory path
if ([System.IO.Path]::IsPathRooted($ProgramDirectory)) {
    # Absolute path
    $programDir = $ProgramDirectory
} else {
    # Relative path - make it relative to script directory
    $programDir = Join-Path $scriptDir $ProgramDirectory
}

# Normalize the path
$programDir = [System.IO.Path]::GetFullPath($programDir)

# Check if program directory exists
if (-not (Test-Path $programDir)) {
    Write-Host "Error: Program directory not found: $programDir" -ForegroundColor Red
    Write-Host "Usage: .\test.ps1 <program_directory> [source_file]" -ForegroundColor Yellow
    Write-Host "Example: .\test.ps1 count count-dad.cpp" -ForegroundColor Yellow
    exit 1
}

$exePath = $null

# If source file is provided, compile it first
if ($SourceFile -ne "") {
    # Resolve source file path
    if ([System.IO.Path]::IsPathRooted($SourceFile)) {
        $sourcePath = $SourceFile
    } else {
        # Relative path - make it relative to program directory
        $sourcePath = Join-Path $programDir $SourceFile
    }
    
    # Normalize the path
    $sourcePath = [System.IO.Path]::GetFullPath($sourcePath)
    
    # Check if source file exists
    if (-not (Test-Path $sourcePath)) {
        Write-Host "Error: Source file not found: $sourcePath" -ForegroundColor Red
        exit 1
    }
    
    Write-Host "Source file: $sourcePath" -ForegroundColor Cyan
    
    # Determine output executable name (remove extension and add .exe)
    $sourceName = [System.IO.Path]::GetFileNameWithoutExtension($sourcePath)
    $exePath = Join-Path $programDir "$sourceName.exe"
    
    # Find compiler (prefer g++, then cl.exe)
    $compiler = $null
    $compilerArgs = @()
    
    # Try g++ first
    $gpp = Get-Command "g++" -ErrorAction SilentlyContinue
    if ($gpp) {
        $compiler = "g++"
        $compilerArgs = @("-std=c++11", "-O2", "-o", $exePath, $sourcePath)
        Write-Host "Using compiler: g++" -ForegroundColor Cyan
    } else {
        # Try cl.exe (MSVC)
        $cl = Get-Command "cl" -ErrorAction SilentlyContinue
        if ($cl) {
            $compiler = "cl"
            $exePathWithoutExt = Join-Path $programDir $sourceName
            $compilerArgs = @("/std:c++11", "/O2", "/Fe:$exePathWithoutExt", $sourcePath)
            Write-Host "Using compiler: cl (MSVC)" -ForegroundColor Cyan
        }
    }
    
    if (-not $compiler) {
        Write-Host "Error: No C++ compiler found (g++ or cl.exe)" -ForegroundColor Red
        Write-Host "Please install g++ or Visual Studio with MSVC compiler" -ForegroundColor Yellow
        exit 1
    }
    
    # Compile the source file
    Write-Host "Compiling source file..." -ForegroundColor Yellow
    $compileProcess = Start-Process -FilePath $compiler -ArgumentList $compilerArgs -WorkingDirectory $programDir -Wait -NoNewWindow -PassThru
    
    if ($compileProcess.ExitCode -ne 0) {
        Write-Host "Error: Compilation failed with exit code $($compileProcess.ExitCode)" -ForegroundColor Red
        exit 1
    }
    
    # Check if executable was created
    if (-not (Test-Path $exePath)) {
        Write-Host "Error: Compilation succeeded but executable not found: $exePath" -ForegroundColor Red
        exit 1
    }
    
    Write-Host "Compilation successful: $exePath" -ForegroundColor Green
} else {
    # Try to find executable file in program directory
    # Common naming patterns: <dirname>-dad.exe, <dirname>.exe, or any .exe file
    $dirName = Split-Path -Leaf $programDir
    $possibleNames = @(
        "$dirName-dad.exe",
        "$dirName.exe",
        "*.exe"
    )
    
    foreach ($name in $possibleNames) {
        $searchPath = Join-Path $programDir $name
        $found = Get-ChildItem -Path $searchPath -ErrorAction SilentlyContinue | Select-Object -First 1
        if ($found) {
            $exePath = $found.FullName
            break
        }
    }
    
    # If still not found, try to find any .exe file in the directory
    if (-not $exePath) {
        $exeFiles = Get-ChildItem -Path $programDir -Filter "*.exe" -ErrorAction SilentlyContinue
        if ($exeFiles.Count -gt 0) {
            $exePath = $exeFiles[0].FullName
            if ($exeFiles.Count -gt 1) {
                Write-Host "Warning: Multiple .exe files found, using: $exePath" -ForegroundColor Yellow
            }
        }
    }
    
    # Check if executable was found
    if (-not $exePath -or -not (Test-Path $exePath)) {
        Write-Host "Error: No executable file found in program directory: $programDir" -ForegroundColor Red
        Write-Host "Please provide source file or compile the program first" -ForegroundColor Yellow
        Write-Host "Usage: .\test.ps1 <program_directory> [source_file]" -ForegroundColor Yellow
        exit 1
    }
}

# Check if data folder exists in program directory
$dataDir = Join-Path $programDir "data"
if (-not (Test-Path $dataDir)) {
    Write-Host "Error: Data folder not found: $dataDir" -ForegroundColor Red
    exit 1
}

# Get all .in files
$inFiles = Get-ChildItem -Path $dataDir -Filter "*.in" | Sort-Object Name

if ($inFiles.Count -eq 0) {
    Write-Host "Error: No .in files found in data folder" -ForegroundColor Red
    exit 1
}

Write-Host "Program: $exePath" -ForegroundColor Cyan
Write-Host "Program directory: $programDir" -ForegroundColor Cyan
Write-Host "Data folder: $dataDir" -ForegroundColor Cyan
Write-Host "Found $($inFiles.Count) test data files" -ForegroundColor Green
Write-Host "Starting tests...`n" -ForegroundColor Green

# Test result statistics
$totalTests = 0
$passedTests = 0
$failedTests = 0
$results = @()

# Temporary file paths (must be in program directory because program uses freopen)
$tempInFile = Join-Path $programDir "count.in"
$tempOutFile = Join-Path $programDir "count.out"

foreach ($inFile in $inFiles) {
    $totalTests++
    $testName = $inFile.BaseName
    
    # Get corresponding .out file
    $outFile = Join-Path $dataDir "$testName.out"
    
    if (-not (Test-Path $outFile)) {
        Write-Host "[$testName] SKIPPED: Corresponding .out file not found" -ForegroundColor Yellow
        $results += @{
            Name = $testName
            Status = "SKIPPED"
            Reason = "No .out file found"
        }
        continue
    }
    
    try {
        # Copy .in file to program directory as count.in
        Copy-Item -Path $inFile.FullName -Destination $tempInFile -Force
        
        # Remove old output file if exists
        if (Test-Path $tempOutFile) {
            Remove-Item -Path $tempOutFile -Force
        }
        
        # Run the program (WorkingDirectory must be program directory so freopen can find count.in)
        $process = Start-Process -FilePath $exePath -WorkingDirectory $programDir -Wait -NoNewWindow -PassThru
        
        if ($process.ExitCode -ne 0) {
            Write-Host "[$testName] FAILED: Program execution error (Exit code: $($process.ExitCode))" -ForegroundColor Red
            $results += @{
                Name = $testName
                Status = "FAILED"
                Reason = "Program execution error"
            }
            $failedTests++
            continue
        }
        
        # Check if output file was generated
        if (-not (Test-Path $tempOutFile)) {
            Write-Host "[$testName] FAILED: Program did not generate output file" -ForegroundColor Red
            $results += @{
                Name = $testName
                Status = "FAILED"
                Reason = "No output file generated"
            }
            $failedTests++
            continue
        }
        
        # Read program output and expected output
        $programOutput = Get-Content -Path $tempOutFile -Raw
        $expectedOutput = Get-Content -Path $outFile -Raw
        
        # Normalize output (remove trailing whitespace, unify line endings)
        $crlf = [char]13 + [char]10
        $lf = [char]10
        $cr = [char]13
        $programOutput = $programOutput.TrimEnd() -replace $crlf, $lf -replace $cr, $lf
        $expectedOutput = $expectedOutput.TrimEnd() -replace $crlf, $lf -replace $cr, $lf
        
        # Compare outputs
        if ($programOutput -eq $expectedOutput) {
            Write-Host "[$testName] PASSED" -ForegroundColor Green
            $results += @{
                Name = $testName
                Status = "PASSED"
                Reason = ""
            }
            $passedTests++
        } else {
            Write-Host "[$testName] FAILED: Output mismatch" -ForegroundColor Red
            $results += @{
                Name = $testName
                Status = "FAILED"
                Reason = "Output mismatch"
            }
            $failedTests++
        }
    } catch {
        Write-Host "[$testName] ERROR: $_" -ForegroundColor Red
        $results += @{
            Name = $testName
            Status = "ERROR"
            Reason = $_.Exception.Message
        }
        $failedTests++
    } finally {
        # Clean up temporary files (optional, comment out if you want to keep them)
        # if (Test-Path $tempInFile) { Remove-Item -Path $tempInFile -Force }
        # if (Test-Path $tempOutFile) { Remove-Item -Path $tempOutFile -Force }
    }
}

# Output test result summary
Write-Host "`n" + ("=" * 50) -ForegroundColor Cyan
Write-Host "Test Result Summary" -ForegroundColor Cyan
Write-Host ("=" * 50) -ForegroundColor Cyan
Write-Host "Total tests: $totalTests" -ForegroundColor White
Write-Host "Passed: $passedTests" -ForegroundColor Green
Write-Host "Failed: $failedTests" -ForegroundColor Red
Write-Host ("=" * 50) -ForegroundColor Cyan

# Output detailed result list
Write-Host "`nDetailed Result List:" -ForegroundColor Cyan
Write-Host ("-" * 50) -ForegroundColor Cyan

foreach ($result in $results) {
    $statusColor = switch ($result.Status) {
        "PASSED" { "Green" }
        "FAILED" { "Red" }
        "ERROR" { "Red" }
        "SKIPPED" { "Yellow" }
        default { "White" }
    }
    
    $statusText = $result.Status
    if ($result.Reason) {
        $statusText += " - $($result.Reason)"
    }
    
    Write-Host "[$($result.Name)] $statusText" -ForegroundColor $statusColor
}

Write-Host ("-" * 50) -ForegroundColor Cyan

# Exit with code 1 if there are failed tests
if ($failedTests -gt 0) {
    exit 1
} else {
    exit 0
}

