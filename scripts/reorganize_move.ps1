# Reorganize script - moves original files into build\backup_before_move and keeps copies in new layout
# Run from repository root (Estrutura) in PowerShell: .\scripts\reorganize_move.ps1

$root = Resolve-Path .
$backup = Join-Path $root 'build\backup_before_move'
if(!(Test-Path $backup)) { New-Item -ItemType Directory -Path $backup | Out-Null }

$moves = @(
    @{src='01_Codigo_Fonte\gerenciador_estoque.c'; dst='src\gerenciador_estoque.c'},
    @{src='01_Codigo_Fonte\teste_completo.c'; dst='tests\teste_completo.c'},
    @{src='01_Codigo_Fonte\esbocoIA.c'; dst='src\\ai_prototype.c'},
    @{src='02_Testes\tests_gerenciador.c'; dst='tests\tests_gerenciador.c'},
    @{src='02_Testes\run_tests.ps1'; dst='tests\run_tests.ps1'},
    @{src='02_Testes\README_TESTS.md'; dst='tests\README_TESTS.md'},
    @{src='03_Relatorios\resultado_testes.txt'; dst='reports\resultado_testes.txt'},
    @{src='03_Relatorios\SUMARIO_TESTES.txt'; dst='reports\SUMARIO_TESTES.txt'},
    @{src='03_Relatorios\RELATORIO_REEXECUCAO_24_NOV_2025.txt'; dst='reports\RELATORIO_REEXECUCAO_24_NOV_2025.txt'}
)

foreach($m in $moves){
    $s = Join-Path $root $m.src
    $d = Join-Path $root $m.dst
    if(Test-Path $s){
        try{
            $bn = Split-Path $s -Leaf
            $backupPath = Join-Path $backup $bn
            Write-Host "Backing up $s -> $backupPath"
            Copy-Item -Force $s $backupPath
            Write-Host "Removing original $s"
            Remove-Item -Force $s
        } catch {
            Write-Warning "Falha ao mover ${s}: $_"
        }
    } else {
        Write-Host "Origem nao encontrada: $s (pulando)"
    }
}

Write-Host "Reorganização (backup) concluída. Verifique \"build\\backup_before_move\" para os arquivos originais."