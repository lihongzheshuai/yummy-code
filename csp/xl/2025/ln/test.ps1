# Test script: Automatically test all test data files for a given program name
# Usage: Run in PowerShell: .\test.ps1 <program_directory> [program_name] [source_file]
#   Example: .\test.ps1 count
#   Example: .\test.ps1 count count
#   Example: .\test.ps1 count count count-dad.cpp
#   The script will always try to compile source files first, then run tests
#   If source_file is provided, it will compile that file
#   If source_file is not provided, it will automatically find and compile .cpp files

param(
    [Parameter(Mandatory=$true)]
    [string]$ProgramDirectory,

    [Parameter(Mandatory=$false)]
    [string]$ProgramName = "",

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
    Write-Host "Usage: .\test.ps1 <program_directory> [program_name] [source_file]" -ForegroundColor Yellow
    Write-Host "Example 1: .\test.ps1 count" -ForegroundColor Yellow
    Write-Host "Example 2: .\test.ps1 count count" -ForegroundColor Yellow
    Write-Host "Example 3: .\test.ps1 count count count-dad.cpp" -ForegroundColor Yellow
    exit 1
}

$exePath = $null
$exeBase = $null

# Helper: strip extension from a filename
function Strip-Extension([string]$path) {
    return [System.IO.Path]::GetFileNameWithoutExtension($path)
}

# Helper: normalize base name by removing common suffixes like -dad, -yummy
function Normalize-Base([string]$name) {
    if (-not $name) { return $name }
    $n = $name
    foreach ($sfx in @("-dad", "-yummy")) {
        if ($n.EndsWith($sfx)) { $n = $n.Substring(0, $n.Length - $sfx.Length) }
    }
    return $n
}

# Helper: compile a source file
function Compile-SourceFile([string]$sourcePath, [string]$exePath, [string]$programDir) {
    Write-Host "Source file: $sourcePath" -ForegroundColor Cyan

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
            $exePathWithoutExt = [System.IO.Path]::ChangeExtension($exePath, "")
            if ($exePathWithoutExt.EndsWith(".")) {
                $exePathWithoutExt = $exePathWithoutExt.Substring(0, $exePathWithoutExt.Length - 1)
            }
            $compilerArgs = @("/std:c++11", "/O2", "/Fe:$exePathWithoutExt", $sourcePath)
            Write-Host "Using compiler: cl (MSVC)" -ForegroundColor Cyan
        }
    }

    if (-not $compiler) {
        Write-Host "Error: No C++ compiler found (g++ or cl.exe)" -ForegroundColor Red
        Write-Host "Please install g++ or Visual Studio with MSVC compiler" -ForegroundColor Yellow
        return $false
    }

    # Compile the source file
    Write-Host "Compiling source file..." -ForegroundColor Yellow
    $compileProcess = Start-Process -FilePath $compiler -ArgumentList $compilerArgs -WorkingDirectory $programDir -Wait -NoNewWindow -PassThru

    if ($compileProcess.ExitCode -ne 0) {
        Write-Host "Error: Compilation failed with exit code $($compileProcess.ExitCode)" -ForegroundColor Red
        return $false
    }

    # Check if executable was created
    if (-not (Test-Path $exePath)) {
        Write-Host "Error: Compilation succeeded but executable not found: $exePath" -ForegroundColor Red
        return $false
    }

    Write-Host "Compilation successful: $exePath" -ForegroundColor Green
    return $true
}

# Try to find and compile source file first
$sourcePath = $null
$exeBaseName = $null

# If source file is provided, use it
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
} else {
    # Try to automatically find source file in program directory
    # Common naming patterns: <program_name>-dad.cpp, <program_name>.cpp, <dirname>-dad.cpp, <dirname>.cpp, or any .cpp file
    $dirName = Split-Path -Leaf $programDir
    $nameHint = if ($ProgramName -ne "") { Strip-Extension $ProgramName } else { $dirName }
    $possibleSourceNames = @(
        "$nameHint-dad.cpp",
        "$nameHint.cpp",
        "$dirName-dad.cpp",
        "$dirName.cpp"
    )

    foreach ($name in $possibleSourceNames) {
        $searchPath = Join-Path $programDir $name
        if (Test-Path $searchPath) {
            $sourcePath = [System.IO.Path]::GetFullPath($searchPath)
            Write-Host "Auto-detected source file: $sourcePath" -ForegroundColor Cyan
            break
        }
    }

    # If still not found, try to find any .cpp file in the directory
    if (-not $sourcePath) {
        $cppFiles = Get-ChildItem -Path $programDir -Filter "*.cpp" -ErrorAction SilentlyContinue
        if ($cppFiles.Count -gt 0) {
            $sourcePath = $cppFiles[0].FullName
            if ($cppFiles.Count -gt 1) {
                Write-Host "Warning: Multiple .cpp files found, using: $sourcePath" -ForegroundColor Yellow
            }
            Write-Host "Auto-detected source file: $sourcePath" -ForegroundColor Cyan
        }
    }
}

# Compile source file if found
if ($sourcePath) {
    # Determine output executable base name
    $exeBaseName = if ($ProgramName -ne "") { Strip-Extension $ProgramName } else { Strip-Extension $sourcePath }
    if (-not $exeBaseName) { $exeBaseName = Split-Path -Leaf $programDir }
    $exePath = Join-Path $programDir ("$exeBaseName.exe")

    # Compile the source file
    if (-not (Compile-SourceFile -sourcePath $sourcePath -exePath $exePath -programDir $programDir)) {
        exit 1
    }

    $exeBase = $exeBaseName
} else {
    # No source file found, try to find existing executable
    Write-Host "No source file found, looking for existing executable..." -ForegroundColor Yellow

    $dirName = Split-Path -Leaf $programDir
    $nameHint = if ($ProgramName -ne "") { Strip-Extension $ProgramName } else { $dirName }
    $possibleNames = @(
        "$nameHint-dad.exe",
        "$nameHint.exe",
        "$dirName-dad.exe",
        "$dirName.exe"
    )

    foreach ($name in $possibleNames) {
        $searchPath = Join-Path $programDir $name
        if (Test-Path $searchPath) {
            $exePath = [System.IO.Path]::GetFullPath($searchPath)
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
        Write-Host "Error: No source file or executable found in program directory: $programDir" -ForegroundColor Red
        Write-Host "Please provide source file or ensure a .cpp file exists in the directory" -ForegroundColor Yellow
        Write-Host "Usage: .\test.ps1 <program_directory> [program_name] [source_file]" -ForegroundColor Yellow
        exit 1
    }

    Write-Host "Using existing executable: $exePath" -ForegroundColor Cyan
    $exeBase = Strip-Extension ([System.IO.Path]::GetFileName($exePath))
}

# Resolve data location (support both programDir\data and programDir)
$dataDirCandidate = Join-Path $programDir "data"
$dataDir = if (Test-Path $dataDirCandidate) { $dataDirCandidate } else { $programDir }

# Get all .in files (prefer <ProgramName>*.in, fallback to *.in)
$inFiles = Get-ChildItem -Path $dataDir -Filter ("$ProgramName*.in") -ErrorAction SilentlyContinue | Sort-Object Name
if ($inFiles.Count -eq 0) {
    $inFiles = Get-ChildItem -Path $dataDir -Filter "*.in" -ErrorAction SilentlyContinue | Sort-Object Name
}

if ($inFiles.Count -eq 0) {
    Write-Host "Error: No .in files found in data folder" -ForegroundColor Red
    exit 1
}

Write-Host "Program: $exePath" -ForegroundColor Cyan
Write-Host "Program directory: $programDir" -ForegroundColor Cyan
Write-Host "Data folder: $dataDir" -ForegroundColor Cyan
Write-Host "Executable: $([System.IO.Path]::GetFileName($exePath))" -ForegroundColor Cyan
Write-Host "Found $($inFiles.Count) test data files" -ForegroundColor Green
Write-Host "Starting tests...`n" -ForegroundColor Green

# Test result statistics
$totalTests = 0
$passedTests = 0
$failedTests = 0
$results = @()

# Decide IO base name used by the program (e.g., count, points)
$dirName = Split-Path -Leaf $programDir
$programHint = if ($ProgramName -ne "") { [System.IO.Path]::GetFileNameWithoutExtension($ProgramName) } else { "" }
$normalizedExeBase = Normalize-Base ([System.IO.Path]::GetFileNameWithoutExtension($exePath))

# Candidate order: normalized exe base, directory name, program hint, raw exe base
$ioBaseCandidates = @()
if ($normalizedExeBase) { $ioBaseCandidates += $normalizedExeBase }
if ($dirName) { $ioBaseCandidates += $dirName }
if ($programHint) { $ioBaseCandidates += $programHint }
if ($exeBase) { $ioBaseCandidates += $exeBase }

# Deduplicate preserving order
$seen = @{}
$ioBaseCandidates = $ioBaseCandidates | Where-Object { if ($seen.ContainsKey($_)) { $false } else { $seen[$_] = $true; $true } }

$ioBase = $ioBaseCandidates[0]

Write-Host "IO base name: $ioBase (.in/.out)" -ForegroundColor Cyan

# Temporary file paths (must be in program directory because program uses freopen)
$tempInFile = Join-Path $programDir ("$ioBase.in")
$tempOutFile = Join-Path $programDir ("$ioBase.out")

foreach ($inFile in $inFiles) {
    $totalTests++
    $testName = $inFile.BaseName

    # Get corresponding expected output file (.out preferred, then .ans)
    $outFile = Join-Path $dataDir ("$testName.out")
    if (-not (Test-Path $outFile)) {
        $outFile = Join-Path $dataDir ("$testName.ans")
    }

    if (-not (Test-Path $outFile)) {
        Write-Host "[$testName] SKIPPED: Corresponding .out/.ans file not found" -ForegroundColor Yellow
        $results += @{
            Name = $testName
            Status = "SKIPPED"
            Reason = "No .out/.ans file found"
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

