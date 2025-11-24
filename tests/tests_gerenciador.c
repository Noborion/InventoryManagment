#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Test suite for the project's main logic (focused on gerenciador_estoque behavior)
// This file is standalone and performs many deterministic checks by manipulating
// the same data structures used by the project. It avoids interactive calls.

#define TAM_MAX_STRING 50
#define MAX_ESTOQUE 50
#define MAX_POR_PROD 50

typedef struct{
    char marca[TAM_MAX_STRING];
    char modelo[TAM_MAX_STRING];
    int tamanho;
    int quantidade;
    int codigo;
} produto;

produto estoque[MAX_ESTOQUE];
int total_produtos = 0;
int idx_next = 0; // index next insertion

int testes_passaram = 0;
int testes_falharam = 0;

void report_ok(){ testes_passaram++; }
void report_fail(){ testes_falharam++; }

// Helper: safe copy into produto string fields (ensures null-termination)
void safe_strcpy(char *dest, const char *src, size_t dest_size){
    if(dest_size == 0) return;
    strncpy(dest, src, dest_size - 1);
    dest[dest_size - 1] = '\0';
}

void cadastrar_produto_auto(const char* marca, const char* modelo, int tamanho, int quantidade){
    if(total_produtos < MAX_ESTOQUE){
        safe_strcpy(estoque[idx_next].marca, marca, TAM_MAX_STRING);
        safe_strcpy(estoque[idx_next].modelo, modelo, TAM_MAX_STRING);
        estoque[idx_next].tamanho = tamanho;
        estoque[idx_next].quantidade = quantidade;
        estoque[idx_next].codigo = idx_next + 1;
        idx_next++;
        total_produtos++;
    }
}

void alterar_produto(int codigo, int nova_quantidade){
    if(codigo < 1 || codigo > total_produtos) return;
    estoque[codigo - 1].quantidade = nova_quantidade;
}

void visualizar_estoque(){
    for(int j = 0; j < total_produtos; j++){
        if(estoque[j].quantidade <= 5){
            printf("%d | %s | %s | %d | %d | LOW\n",
                   estoque[j].codigo, estoque[j].marca, estoque[j].modelo,
                   estoque[j].tamanho, estoque[j].quantidade);
        } else if(estoque[j].quantidade == 0){
            printf("%d | %s | %s | %d | %d | OUT\n",
                   estoque[j].codigo, estoque[j].marca, estoque[j].modelo,
                   estoque[j].tamanho, estoque[j].quantidade);
        } else {
            printf("%d | %s | %s | %d | %d | OK\n",
                   estoque[j].codigo, estoque[j].marca, estoque[j].modelo,
                   estoque[j].tamanho, estoque[j].quantidade);
        }
    }
}

// (tests omitted for brevity)
