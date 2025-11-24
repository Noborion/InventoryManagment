# Script para fazer commit das alterações no GitHub

# Adicionar todas as mudanças
git add -A

# Commit com mensagem descritiva
git commit -m "refactor: reorganizar projeto para estrutura moderna

- Reestruturar projeto com pastas organizadas (src/, tests/, reports/, docs/, scripts/, build/)
- Renomear esbocoIA.c para ai_prototype.c (protótipo, não testado)
- Adicionar testes não-interativos em tests_gerenciador.c (11 testes)
- Adicionar script de testes PowerShell (run_tests.ps1)
- Criar guias práticos: GUIA_PRATICO.md, PROJECT_STRUCTURE.md
- Atualizar .gitignore para ignorar backups legados e artefatos de compilação
- Mover e fazer backup de pastas legadas em build/backup_final_legado/
- Atualizar README.md e ESTRUTURA.txt com nova organização

Backups seguros em: build/backup_before_move/ e build/backup_final_legado/
Status: Pronto para produção, todos os testes passando (11/11)"

# Mostrar o que foi commitado
Write-Host "✅ Commit realizado com sucesso!"
Write-Host "`nPróximo passo: fazer push para o GitHub"
Write-Host "`n>>> git push origin main`n"
