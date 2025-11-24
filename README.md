## Estrutura de Diretórios

```
ESTRUTURA/
├── 01_Codigo_Fonte/          ← Código fonte dos programas
│   ├── gerenciador_estoque.c (Programa principal testado)
│   ├── ai_prototype.c         (Inspiração - não testado)
│   └── teste_completo.c      (Código dos testes)
│
├── 02_Testes/                ← Executáveis dos testes
│   └── teste_completo.exe    (Programa de testes compilado)
│
├── 03_Relatorios/            ← Resultados e análises dos testes
│   ├── RELATORIO_FINAL.txt   (Relatório visual final)
│   ├── RELATORIO_TESTES.md   (Análise detalhada)
│   ├── SUMARIO_TESTES.txt    (Resumo executivo)
│   ├── LISTA_COMPLETA_TESTES.txt (Lista de todos os 24 testes)
│   └── resultado_testes.txt  (Log da execução)
│
├── 04_Documentacao/          ← Documentação do projeto
│   ├── INSTRUCOES.txt        (Guia de uso dos testes)
│   └── TrabalhoPratico_2aParte.pdf (Enunciado original)
│
├── 05_Saida/                 ← Arquivos de saída/output
│   └── (conteúdo original)
│
└── README.md                 ← Este arquivo
```

---

## Descrição das Pastas

### 📄 01_Codigo_Fonte
Contém todo o código fonte em C:
- **gerenciador_estoque.c** - Versão básica do gerenciador de estoque
- **esbocoIA.c** - Versão avançada (usada como inspiração apenas)
- **teste_completo.c** - Código dos 24 testes abrangentes

### ▶️ 02_Testes
Contém o executável compilado:
- **teste_completo.exe** - Execute este arquivo para rodar os 24 testes

### 📊 03_Relatorios
Documentos com resultados detalhados dos testes (ATUALIZADOS 17/11/2025):
- **RELATORIO_FINAL.txt** - Relatório visual com resumo estatístico
- **RELATORIO_TESTES.md** - Análise técnica profunda com tabelas
- **SUMARIO_TESTES.txt** - Resumo executivo com recomendações
- **LISTA_COMPLETA_TESTES.txt** - Lista com todos os 24 testes
- **resultado_testes.txt** - Log de execução (reexecutado)

Nota: Arquivos adicionais e versões antigas foram movidos para
`03_Relatorios/backup_2025-11-19` durante o processo de curadoria (19/11/2025).

### 📚 04_Documentacao
Documentação e guias:
- **INSTRUCOES.txt** - Como usar os programas de teste
- **TrabalhoPratico_2aParte.pdf** - Enunciado original do trabalho

### 📦 05_Saida
Arquivos de saída/output do sistema

---

## Como Usar

### Executar os Testes
```bash
cd 02_Testes
.\teste_completo.exe
```

### Recompilar os Testes
```bash
cd 01_Codigo_Fonte
gcc -o ..\/02_Testes\/teste_completo.exe gerenciador_estoque.c
```

### Consultar Relatórios
Abra qualquer arquivo em `03_Relatorios/`:
- Para análise visual: `03_Relatorios/RELATORIO_FINAL.txt`
- Para análise técnica: `03_Relatorios/RELATORIO_TESTES.md`
- Para recomendações: `03_Relatorios/SUMARIO_TESTES.txt`

---

## Resumo dos Testes

- **Total de Testes:** 24
- **Taxa de Aprovação:** 100% (24/24)
- **Programa Testado:** gerenciador_estoque.c
- **Status:** ✓ Pronto para produção
- **Última Validação:** 17 de novembro de 2025

---

## Histórico de Testes

| Data | Total | Aprovados | Status |
|------|-------|-----------|--------|
| 15/11/2025 | 24 | 24 | ✓ Sucesso |
| 17/11/2025 | 24 | 24 | ✓ Revalidado |

---

## Checklist de Uso

- [ ] Ler este README.md
- [ ] Ler 04_Documentacao/INSTRUCOES.txt
- [ ] Executar 02_Testes/teste_completo.exe
- [ ] Consultar 03_Relatorios/RELATORIO_FINAL.txt
- [ ] Revisar código em 01_Codigo_Fonte/

---

## Informações Técnicas

| Aspecto | Detalhes |
|---------|----------|
| Linguagem | C (ISO C99) |
| Compilador | GCC |
| Plataforma | Windows (PowerShell) |
| Testes | 24 (100% aprovação) |
| Executáveis | 1 (teste_completo.exe) |
| Documentação | 5 arquivos |
| Última Atualização | 17 de novembro de 2025 |

---

**Data de Organização Inicial:** 15 de novembro de 2025
**Data da Revalidação:** 17 de novembro de 2025
**Versão:** 1.1 REVALIDADO
