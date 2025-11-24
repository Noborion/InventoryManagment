# PowerShell script to compile and run the C test suite on Windows
# Requires: MinGW-w64 gcc (or another gcc available in PATH). If you have MSVC, compile manually.

$testsDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$projectRoot = Resolve-Path "$testsDir\.."

# Paths
$testFile = Join-Path $testsDir 'tests_gerenciador.c'
$outExe = Join-Path $testsDir 'tests_gerenciador.exe'

# Try to compile with gcc
Write-Host "Compiling tests..."
$gcc = Get-Command gcc -ErrorAction SilentlyContinue
if($null -ne $gcc){
    gcc -std=c11 -O2 -Wall -Wextra -I"$projectRoot\01_Codigo_Fonte" "$testFile" -o "$outExe"
    if($LASTEXITCODE -ne 0){
        Write-Error "Compilacao falhou. Veja as mensagens acima."
        exit 1
    }
    Write-Host "Execucao dos testes..."
    & "$outExe"
    exit $LASTEXITCODE
} else {
    Write-Warning "gcc nao encontrado no PATH. Se tiver MSVC, compile manualmente com cl.exe."
    Write-Host "Exemplo (MSVC Developer Prompt): cl /Fe:tests_gerenciador.exe $testFile"
    exit 2
}
