# Script para fazer backup das pastas legadas e depois removê-las

$root = Resolve-Path .
$backupFinal = Join-Path $root 'build\backup_final_legado'

# Criar pasta de backup final
New-Item -ItemType Directory -Path $backupFinal -Force | Out-Null
Write-Host "Criando backup final em: build\backup_final_legado`n"

# Lista de pastas legadas
$legacyFolders = @('01_Codigo_Fonte', '02_Testes', '03_Relatorios', '04_Documentacao', '05_Saida')

# Backup
foreach($folder in $legacyFolders) {
    $src = Join-Path $root $folder
    if(Test-Path $src) {
        $dst = Join-Path $backupFinal $folder
        Write-Host "Copiando $folder..."
        Copy-Item -Path $src -Destination $dst -Recurse -Force
        Write-Host "Copiado: $folder"
    }
}

Write-Host "`n=== Backup Concluido ===" 
Write-Host "Local: build\backup_final_legado"
Write-Host "`nRemovendo pastas legadas...`n"

foreach($folder in $legacyFolders) {
    $src = Join-Path $root $folder
    if(Test-Path $src) {
        Remove-Item -Path $src -Recurse -Force
        Write-Host "Removido: $folder"
    }
}

Write-Host "`n✅ Limpeza concluida!"
Write-Host "Backups salvos em: build\backup_final_legado"
Write-Host "Estrutura agora usa: src/, tests/, reports/, build/, docs/, scripts/"
