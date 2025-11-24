/*
 * NOTA: Este arquivo foi gerado por uma IA (AI Coding Assistant of Cursor IDE)
 * e utilizado como referência/inspiração para desenvolvimento do código principal.
 *
 * NÃO FOI TESTADO e NÃO FAZ PARTE da solução final submetida.
 *
 * Ver gerenciador_estoque.c para o programa principal testado com 24 casos de teste.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUTOS 100
#define TAM_STRING 50

// Estrutura para armazenar um produto
typedef struct {
    char marca[TAM_STRING];
    char modelo[TAM_STRING];
    int tamanho;
    int quantidade;
    int ativo; // 1 = ativo, 0 = removido
} Produto;

// Matriz global de produtos
Produto estoque[MAX_PRODUTOS];
int total_produtos = 0;

// (restante do arquivo mantido no local original)
