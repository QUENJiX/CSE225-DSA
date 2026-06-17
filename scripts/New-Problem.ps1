param(
    [Parameter(Mandatory = $true)]
    [string]$Name,

    [string]$Folder = "10_problem_solving/solved"
)

$ErrorActionPreference = "Stop"

$safeName = $Name.Trim().ToLower() -replace '[^a-z0-9_-]+', '_'
if ([string]::IsNullOrWhiteSpace($safeName)) {
    throw "Problem name must contain at least one letter or number."
}

$workspace = Split-Path -Parent $PSScriptRoot
$targetDir = Join-Path $workspace $Folder
$targetFile = Join-Path $targetDir "$safeName.cpp"
$template = Join-Path $workspace "templates/problem_template.cpp"

New-Item -ItemType Directory -Force -Path $targetDir | Out-Null

if (Test-Path $targetFile) {
    Write-Host "Already exists: $targetFile"
    exit 0
}

Copy-Item $template $targetFile
Write-Host "Created: $targetFile"


