Instrucoes para executar os testes (Windows PowerShell)

Requisitos:
- `gcc` (MinGW-w64) disponível no PATH, ou MSVC (cl.exe) no Developer Prompt.

Passos (com gcc):

1. Abra PowerShell na pasta do repositório (onde está `tests`).
2. Execute:

```powershell
cd .\tests
.\run_tests.ps1
```

Se quiser compilar manualmente com `gcc`:

```powershell
cd .\tests
gcc -std=c11 -O2 -Wall -Wextra tests_gerenciador.c -o tests_gerenciador.exe
.\tests_gerenciador.exe
```

Com MSVC (Developer Command Prompt):

```powershell
cl /Fe:tests_gerenciador.exe ..\tests\tests_gerenciador.c
tests_gerenciador.exe
```

O script `run_tests.ps1` tentará usar `gcc` se presente. O executável `tests_gerenciador.exe` retorna código 0 se todos os testes passarem, não-zero caso contrário.

Notas:
- Estes testes são não-interativos: manipulam diretamente as estruturas de dados do gerenciador (simulando cenários). Não chamam funções que esperem entrada do usuário.
- Não testam `ai_prototype.c` conforme solicitado.