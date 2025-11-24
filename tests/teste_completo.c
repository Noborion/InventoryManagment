#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX_STRING 50
#define MAX_ESTOQUE 50

typedef struct{
    char marca[TAM_MAX_STRING];
    char modelo[TAM_MAX_STRING];
    int tamanho;
    int quantidade;
    int codigo;
} produto;

produto estoque[MAX_ESTOQUE];
int total_produtos = 0;
int i = 0;

void cadastrar_produto_auto(const char* marca, const char* modelo, int tamanho, int quantidade);
void alterar_produto(int codigo, int nova_quantidade);
void visualizar_estoque();

void teste_cadastro();
void teste_atualizacao();
void teste_estoque_cheio();
void teste_codigo_invalido();
void teste_estoque_baixo();
void teste_quantidade_zero();
void teste_quantidade_negativa();
void teste_tamanhos_extremos();
void teste_marcas_modelos_longos();
void teste_multiplos_produtos();

int testes_passaram = 0;
int testes_falharam = 0;

int main(){
    printf("\n========================================================\n");
    printf("   PROGRAMA DE TESTES - GERENCIADOR DE ESTOQUE\n");
    printf("           SNEAKER KING v1.0\n");
    printf("========================================================\n\n");
    
    teste_cadastro();
    teste_atualizacao();
    teste_codigo_invalido();
    teste_estoque_cheio();
    teste_estoque_baixo();
    teste_quantidade_zero();
    teste_quantidade_negativa();
    teste_tamanhos_extremos();
    teste_marcas_modelos_longos();
    teste_multiplos_produtos();
    
    printf("\n========================================================\n");
    printf("               RESUMO DOS TESTES\n");
    printf("========================================================\n\n");
    printf("  [OK] Testes Aprovados:  %d\n", testes_passaram);
    printf("  [XX] Testes Falhados:   %d\n", testes_falharam);
    printf("  [--] Total de Testes:   %d\n\n", testes_passaram + testes_falharam);
    
    if(testes_falharam == 0){
        printf("  SUCCESS: TODOS OS TESTES PASSARAM COM SUCESSO!\n\n");
    } else {
        printf("  FAILURE: ALGUNS TESTES FALHARAM!\n\n");
    }
    
    return 0;
}

void teste_cadastro(){
    printf("\n[TESTE 1] CADASTRO DE PRODUTOS\n");
    printf("=========================================================\n");
    
    total_produtos = 0;
    i = 0;
    
    printf("\n  1.1 - Cadastrando produto simples (Nike Air Force)...\n");
    cadastrar_produto_auto("Nike", "Air Force 1", 42, 10);
    
    if(total_produtos == 1 && strcmp(estoque[0].marca, "Nike") == 0){
        printf("     [OK] Cadastro simples\n");
        testes_passaram++;
    } else {
        printf("     [XX] Cadastro simples\n");
        testes_falharam++;
    }
    
    printf("\n  1.2 - Cadastrando multiplos produtos...\n");
    cadastrar_produto_auto("Adidas", "Ultraboost", 40, 5);
    cadastrar_produto_auto("Puma", "RS-X", 39, 15);
    
    if(total_produtos == 3 && strcmp(estoque[2].marca, "Puma") == 0){
        printf("     [OK] Cadastro multiplo\n");
        testes_passaram++;
    } else {
        printf("     [XX] Cadastro multiplo\n");
        testes_falharam++;
    }
    
    printf("\n  1.3 - Verificando atribuicao de codigos...\n");
    if(estoque[0].codigo == 1 && estoque[1].codigo == 2 && estoque[2].codigo == 3){
        printf("     [OK] Codigos sequenciais\n");
        testes_passaram++;
    } else {
        printf("     [XX] Codigos sequenciais\n");
        testes_falharam++;
    }
    
    printf("\n  1.4 - Verificando dados armazenados corretamente...\n");
    if(estoque[0].tamanho == 42 && estoque[1].quantidade == 5){
        printf("     [OK] Integridade dos dados\n");
        testes_passaram++;
    } else {
        printf("     [XX] Integridade dos dados\n");
        testes_falharam++;
    }
}

// Remaining functions are identical to original teste_completo.c
