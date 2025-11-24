Projeto: InventoryManagment — Estrutura proposta

Objetivo
- Organizar as pastas para melhorar clareza visual e fluxo de trabalho.
- Não mover arquivos automaticamente sem sua confirmação; criei pastas e instruí como mover.

Estrutura sugerida (mapa):

- `src/`         -> Código-fonte principal (.c, .h). Atualmente em `01_Codigo_Fonte/`.
- `tests/`       -> Suites de teste e scripts. Atualmente em `02_Testes/`.
- `reports/`     -> Relatórios de teste e logs (apenas relatórios finais; backups ficam em `03_Relatorios/backup_*` e estão ignorados pelo .gitignore).
- `docs/`        -> Documentação (atualmente `04_Documentacao/`).
- `build/`       -> Binários gerados e artefatos de compilação (limpo, para builds locais).
- `output/`      -> Saídas do programa (opcional, atualmente `01_Codigo_Fonte/output`).

Ações feitas automaticamente
- Criei pastas vazias: `src/`, `tests/`, `reports/`, `docs/`, `build/`.
- Atualizei `.gitignore` para ignorar `03_Relatorios/backup_*`, artefatos de build e arquivos temporários.
- NÃO movi arquivos existentes; isso evita quebras inesperadas e preserva histórico.

Como mover os arquivos (comandos PowerShell)
- Mover código-fonte para `src/`:

```powershell
# mover todos os .c e .h
Move-Item .\01_Codigo_Fonte\*.c .\src\
Move-Item .\01_Codigo_Fonte\*.h .\src\
# mover pasta de output para build ou output
Move-Item .\01_Codigo_Fonte\output .\build\output
```

- Mover testes para `tests/`:

```powershell
Move-Item .\02_Testes\* .\tests\
```

- Mover relatórios finais para `reports/` (manter backups em `03_Relatorios` se quiser):

```powershell
Move-Item .\03_Relatorios\RELATORIO_*.txt .\reports\
Move-Item .\03_Relatorios\RELATORIO_*.md .\reports\
```

Observações e recomendações
- Recomendo revisar `Makefile`/tarefas após mover arquivos (ou atualizar tarefas do VSCode) para apontar para `src/` e `tests/`.
- Se quiser, eu executo a reorganização automaticamente agora (mover arquivos e atualizar caminhos). Confirme que quer que eu faça as alterações físicas no repositório.

Se quiser que eu faça a reorganização agora, responda "Mover agora" e eu aplico os movimentos (farei backup dos arquivos movidos se desejar).