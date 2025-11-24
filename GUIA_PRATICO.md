# 📚 Guia Prático: Como Usar a Estrutura do Projeto

## 🎯 Visão Geral da Organização

O projeto agora segue uma estrutura **moderna e profissional** com pastas bem definidas para cada função:

```
ESTRUTURA/
├── src/                    ← 💻 Código-fonte principal
│   ├── gerenciador_estoque.c       (programa principal)
│   └── ai_prototype.c               (protótipo/inspiração - não testado)
│
├── tests/                  ← 🧪 Testes e executáveis
│   ├── teste_completo.c            (suíte de testes original - 24 casos)
│   ├── tests_gerenciador.c         (suíte não-interativa)
│   ├── run_tests.ps1               (script para executar testes)
│   └── README_TESTS.md             (instruções de teste)
│
├── reports/                ← 📊 Relatórios finais
│   ├── resultado_testes.txt        (log de execução)
│   ├── SUMARIO_TESTES.txt          (resumo executivo)
│   └── RELATORIO_REEXECUCAO_24_NOV_2025.txt
│
├── build/                  ← 🔨 Binários e backups
│   └── backup_before_move/         (cópias dos originais para segurança)
│
├── docs/                   ← 📖 Documentação complementar
├── scripts/                ← 🛠️  Scripts de automação
│   └── reorganize_move.ps1         (script de reorganização)
│
├── 01_Codigo_Fonte/        ← [LEGADO] Arquivos originais ainda presentes
├── 02_Testes/              ← [LEGADO] Testes originais
├── 03_Relatorios/          ← [LEGADO] Relatórios antigos
├── 04_Documentacao/        ← [LEGADO] Documentação original
└── 05_Saida/               ← [LEGADO] Saída do sistema
```

---

## 🚀 Fluxos de Trabalho Principais

### 1️⃣ **Compilar e Executar o Programa Principal**

```powershell
# Opção A: Compilar manualmente
cd .\src\
gcc -std=c11 -Wall -Wextra gerenciador_estoque.c -o gerenciador_estoque.exe
.\gerenciador_estoque.exe

# Opção B: Com VSCode
# Abra gerenciador_estoque.c e use Ctrl+Shift+B (ou a tarefa C/C++ Compile Run)
```

**Resultado esperado:** Menu interativo do gerenciador de estoque

---

### 2️⃣ **Executar os Testes Automaticamente**

#### Opção A: Com o script PowerShell (recomendado)

```powershell
cd .\tests\
.\run_tests.ps1
```

**Resultado esperado:**
```
Compilando tests_gerenciador.c...
Executando testes...
Testes passados: 11 / Testes falhados: 0
✓ Todos os testes passaram!
```

#### Opção B: Manualmente com gcc

```powershell
cd .\tests\
gcc -std=c11 -O2 -Wall -Wextra tests_gerenciador.c -o tests_gerenciador.exe
.\tests_gerenciador.exe
```

#### Opção C: Com MSVC (Developer Command Prompt)

```powershell
cl /Fe:tests_gerenciador.exe ..\tests\tests_gerenciador.c
tests_gerenciador.exe
```

---

### 3️⃣ **Consultar Relatórios e Resultados**

```powershell
# Abrir relatórios no editor
notepad .\reports\SUMARIO_TESTES.txt
notepad .\reports\resultado_testes.txt

# Ou no Markdown (melhor formatação)
code .\reports\  # abre a pasta no VSCode
```

**Arquivos disponíveis:**
- `resultado_testes.txt` — Log de execução com timestamps
- `SUMARIO_TESTES.txt` — Resumo executivo com recomendações
- `RELATORIO_REEXECUCAO_24_NOV_2025.txt` — Relatório da última execução

---

### 4️⃣ **Desenvolver/Modificar o Código**

```powershell
# Editar o programa principal
code .\src\gerenciador_estoque.c

# Após fazer mudanças, recompilar e testar:
cd .\src\
gcc -std=c11 -Wall -Wextra gerenciador_estoque.c -o gerenciador_estoque.exe

# Depois executar os testes para validar:
cd ..\tests\
.\run_tests.ps1
```

**Workflow recomendado:**
1. Edite `src/gerenciador_estoque.c`
2. Compile em `src/`
3. Execute testes em `tests/`
4. Se todos passarem → Pronto para commit 🎉

---

## 🔄 Estrutura Dupla: Por que existem pastas antigas e novas?

O projeto **mantém ambas as estruturas** temporariamente:

| Pasta | Status | Uso |
|-------|--------|-----|
| `01_Codigo_Fonte/` | LEGADO | Originais (segurança) |
| `src/` | ✅ ATIVA | Use para novo desenvolvimento |
| `02_Testes/` | LEGADO | Testes originais |
| `tests/` | ✅ ATIVA | Execute testes daqui |
| `03_Relatorios/` | LEGADO | Backups antigos (ignorado por .gitignore) |
| `reports/` | ✅ ATIVA | Relatórios finais |

**Benefício:** Você pode sempre voltar aos originais se necessário, mas trabalha com a nova estrutura.

---

## 🎓 Tarefas Comuns

### Adicionar um novo teste

1. Abra `tests/tests_gerenciador.c` no editor
2. Adicione uma nova função de teste seguindo o padrão:

```c
void test_novo_caso() {
    // Setup
    Produto teste = {"marca", "modelo", 30, 5, 1};
    estoque[0] = teste;
    total_produtos = 1;
    
    // Ação
    int resultado = validacao_tamanho(30);
    
    // Verificação
    ASSERT_EQ(resultado, 1, "Tamanho válido deve retornar 1");
}
```

3. Registre a função em `main()`:

```c
int main() {
    test_novo_caso();
    // ... outros testes
}
```

4. Execute o script `run_tests.ps1` para testar

---

### Compilar para Release/Otimização

```powershell
cd .\src\
gcc -O2 -Wall -Wextra gerenciador_estoque.c -o gerenciador_estoque_release.exe
```

---

### Fazer Backup Seguro

```powershell
# Backup manual em data específica
Copy-Item .\src\ .\build\backup_$(Get-Date -Format "yyyy-MM-dd")
```

---

## ✅ Checklist: Pronto para Usar?

- [x] **Código-fonte** em `src/` ✓
- [x] **Testes** em `tests/` ✓
- [x] **Relatórios** em `reports/` ✓
- [x] **Backups** em `build/backup_before_move/` ✓
- [x] **Script de testes** configurado (`run_tests.ps1`) ✓
- [x] **.gitignore** atualizado ✓
- [x] **Protótipo IA** renomeado para `ai_prototype.c` ✓

---

## 🆘 Troubleshooting

### "Erro: gcc não encontrado"
```powershell
# Adicione MinGW ao PATH ou use um compilador alternativo:
# Opção 1: Instale MinGW-w64 (https://www.mingw-w64.org/)
# Opção 2: Use MSVC (cl.exe) no Developer Command Prompt
# Opção 3: Use WSL (Windows Subsystem for Linux)
```

### "Arquivo não encontrado em src/"
```powershell
# Verifique que você está na pasta correta:
Get-Location
Get-ChildItem .\src\

# Se vazio, os arquivos ainda estão em 01_Codigo_Fonte/
# Você pode copiar manualmente:
Copy-Item .\01_Codigo_Fonte\*.c .\src\
```

### "Testes falhando após mudança"
```powershell
# Recompile tudo do zero:
cd .\tests\
Remove-Item *.exe
.\run_tests.ps1
```

---

## 📝 Referência Rápida: Comandos Mais Usados

```powershell
# Compilar programa principal
gcc -std=c11 -Wall -Wextra .\src\gerenciador_estoque.c -o .\src\gerenciador.exe

# Executar programa
.\src\gerenciador.exe

# Rodar testes
.\tests\run_tests.ps1

# Ver relatório
cat .\reports\SUMARIO_TESTES.txt

# Listar arquivos
ls -la .\src\
ls -la .\tests\

# Limpar binários
Remove-Item .\src\*.exe
Remove-Item .\tests\*.exe
```

---

## 🎯 Próximos Passos Recomendados

1. **Familiarize-se com a nova estrutura** navegando pelas pastas
2. **Execute os testes** usando `.\tests\run_tests.ps1`
3. **Consulte os relatórios** em `.\reports\`
4. **Comece a desenvolver** com a confiança de que a estrutura está organizada
5. **Quando confortável**, pode limpar as pastas legadas (`01_*`, `02_*`, `03_*`, `04_*`, `05_*`)

---

**Última atualização:** 24 de novembro de 2025  
**Status:** ✅ Pronto para uso  
**Versão da estrutura:** 2.0 (moderno + seguro)
