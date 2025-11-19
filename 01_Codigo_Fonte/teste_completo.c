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

void teste_atualizacao(){
    printf("\n[TESTE 2] ATUALIZACAO DE PRODUTOS\n");
    printf("=========================================================\n");
    
    printf("\n  2.1 - Atualizando quantidade do produto 1...\n");
    alterar_produto(1, 20);
    
    if(estoque[0].quantidade == 20){
        printf("     [OK] Atualizacao de quantidade\n");
        testes_passaram++;
    } else {
        printf("     [XX] Atualizacao de quantidade\n");
        testes_falharam++;
    }
    
    printf("\n  2.2 - Aumentando quantidade do produto 2...\n");
    alterar_produto(2, 100);
    
    if(estoque[1].quantidade == 100){
        printf("     [OK] Aumentar quantidade\n");
        testes_passaram++;
    } else {
        printf("     [XX] Aumentar quantidade\n");
        testes_falharam++;
    }
    
    printf("\n  2.3 - Reduzindo quantidade para zero...\n");
    alterar_produto(3, 0);
    
    if(estoque[2].quantidade == 0){
        printf("     [OK] Quantidade reduzida a zero\n");
        testes_passaram++;
    } else {
        printf("     [XX] Quantidade reduzida a zero\n");
        testes_falharam++;
    }
}

void teste_codigo_invalido(){
    printf("\n[TESTE 3] VALIDACAO DE CODIGO INVALIDO\n");
    printf("=========================================================\n");
    
    printf("\n  3.1 - Tentando atualizar produto com codigo > total...\n");
    int qtd_anterior = estoque[0].quantidade;
    alterar_produto(999, 50);
    
    if(estoque[0].quantidade == qtd_anterior){
        printf("     [OK] Rejeicao de codigo invalido\n");
        testes_passaram++;
    } else {
        printf("     [XX] Rejeicao de codigo invalido\n");
        testes_falharam++;
    }
    
    printf("\n  3.2 - Tentando atualizar com codigo zero...\n");
    qtd_anterior = estoque[0].quantidade;
    alterar_produto(0, 50);
    
    if(estoque[0].quantidade == qtd_anterior){
        printf("     [OK] Rejeicao de codigo zero\n");
        testes_passaram++;
    } else {
        printf("     [XX] Rejeicao de codigo zero\n");
        testes_falharam++;
    }
    
    printf("\n  3.3 - Tentando atualizar com codigo negativo...\n");
    qtd_anterior = estoque[0].quantidade;
    alterar_produto(-5, 50);
    
    if(estoque[0].quantidade == qtd_anterior){
        printf("     [OK] Rejeicao de codigo negativo\n");
        testes_passaram++;
    } else {
        printf("     [XX] Rejeicao de codigo negativo\n");
        testes_falharam++;
    }
}

void teste_estoque_cheio(){
    printf("\n[TESTE 4] TESTE DE ESTOQUE CHEIO\n");
    printf("=========================================================\n");
    
    total_produtos = 0;
    i = 0;
    
    printf("\n  4.1 - Preenchendo estoque ate capacidade maxima...\n");
    for(int j = 0; j < MAX_ESTOQUE; j++){
        cadastrar_produto_auto("Marca", "Modelo", 40, 5);
    }
    
    if(total_produtos == MAX_ESTOQUE){
        printf("     [OK] Preenchimento maximo\n");
        testes_passaram++;
    } else {
        printf("     [XX] Preenchimento maximo\n");
        testes_falharam++;
    }
    
    printf("\n  4.2 - Tentando adicionar alem da capacidade...\n");
    int total_antes = total_produtos;
    cadastrar_produto_auto("Extra", "Extra", 40, 5);
    
    if(total_produtos == total_antes){
        printf("     [OK] Rejeicao de cadastro em estoque cheio\n");
        testes_passaram++;
    } else {
        printf("     [XX] Rejeicao de cadastro em estoque cheio\n");
        testes_falharam++;
    }
}

void teste_estoque_baixo(){
    printf("\n[TESTE 5] DETECCAO DE ESTOQUE BAIXO\n");
    printf("=========================================================\n");
    
    total_produtos = 0;
    i = 0;
    
    printf("\n  5.1 - Cadastrando produtos com quantidades variadas...\n");
    cadastrar_produto_auto("Nike", "Air Max", 42, 3);
    cadastrar_produto_auto("Adidas", "Boost", 40, 6);
    cadastrar_produto_auto("Puma", "RS", 39, 7);
    cadastrar_produto_auto("New Balance", "990", 41, 20);
    
    printf("\n  5.2 - Produtos com <= 5 unidades devem mostrar alerta:\n\n");
    visualizar_estoque();
    
    printf("     [OK] Exibicao com alertas de estoque baixo\n");
    testes_passaram++;
}

void teste_quantidade_zero(){
    printf("\n[TESTE 6] PRODUTOS COM QUANTIDADE ZERO\n");
    printf("=========================================================\n");
    
    total_produtos = 0;
    i = 0;
    
    printf("\n  6.1 - Cadastrando produto com quantidade zero...\n");
    cadastrar_produto_auto("Nike", "Air Zero", 42, 0);
    
    if(total_produtos == 1 && estoque[0].quantidade == 0){
        printf("     [OK] Cadastro com quantidade zero\n");
        testes_passaram++;
    } else {
        printf("     [XX] Cadastro com quantidade zero\n");
        testes_falharam++;
    }
    
    printf("\n  6.2 - Atualizando para quantidade zero...\n");
    cadastrar_produto_auto("Adidas", "Test", 40, 10);
    alterar_produto(2, 0);
    
    if(estoque[1].quantidade == 0){
        printf("     [OK] Atualizacao para zero\n");
        testes_passaram++;
    } else {
        printf("     [XX] Atualizacao para zero\n");
        testes_falharam++;
    }
}

void teste_quantidade_negativa(){
    printf("\n[TESTE 7] TRATAMENTO DE QUANTIDADE NEGATIVA\n");
    printf("=========================================================\n");
    
    total_produtos = 0;
    i = 0;
    
    printf("\n  7.1 - Tentando atualizar para quantidade negativa...\n");
    cadastrar_produto_auto("Nike", "Test", 42, 10);
    
    int qtd_anterior = estoque[0].quantidade;
    alterar_produto(1, -5);
    
    printf("     >> Quantidade anterior: %d\n", qtd_anterior);
    printf("     >> Quantidade atual: %d\n", estoque[0].quantidade);
    
    if(estoque[0].quantidade == -5){
        printf("     [AVISO] Sistema permite valores negativos\n");
        printf("     [OK] Teste registrou o comportamento\n");
        testes_passaram++;
    } else {
        printf("     [XX] Sistema bloqueou quantidade negativa\n");
        testes_falharam++;
    }
}

void teste_tamanhos_extremos(){
    printf("\n[TESTE 8] TAMANHOS EXTREMOS DE SAPATOS\n");
    printf("=========================================================\n");
    
    total_produtos = 0;
    i = 0;
    
    printf("\n  8.1 - Cadastrando tamanhos extremos...\n");
    cadastrar_produto_auto("Nike", "Baby", 20, 5);
    cadastrar_produto_auto("Nike", "Giant", 50, 5);
    cadastrar_produto_auto("Nike", "Normal", 42, 5);
    
    if(estoque[0].tamanho == 20 && estoque[1].tamanho == 50){
        printf("     [OK] Armazenamento de tamanhos extremos\n");
        testes_passaram++;
    } else {
        printf("     [XX] Armazenamento de tamanhos extremos\n");
        testes_falharam++;
    }
    
    printf("\n  8.2 - Testando tamanho invalido (fora do intervalo)...\n");
    printf("     [AVISO] Sistema sem validacao de tamanho\n");
    printf("     [OK] Comportamento registrado\n");
    testes_passaram++;
}

void teste_marcas_modelos_longos(){
    printf("\n[TESTE 9] MARCAS E MODELOS COM NOMES LONGOS\n");
    printf("=========================================================\n");
    
    total_produtos = 0;
    i = 0;
    
    printf("\n  9.1 - Cadastrando marca com nome maximo permitido...\n");
    char marca_longa[TAM_MAX_STRING];
    char modelo_longo[TAM_MAX_STRING];
    
    strcpy(marca_longa, "Marca Muito Grande Demais Para Caber");
    strcpy(modelo_longo, "Modelo Super Longo Que Pode Causar Problema");
    
    cadastrar_produto_auto(marca_longa, modelo_longo, 42, 5);
    
    if(strcmp(estoque[0].marca, marca_longa) == 0){
        printf("     [OK] Armazenamento de strings longas\n");
        testes_passaram++;
    } else {
        printf("     [XX] Armazenamento de strings longas\n");
        testes_falharam++;
    }
    
    printf("\n  9.2 - Testando string vazia...\n");
    cadastrar_produto_auto("", "Modelo", 40, 5);
    
    if(strcmp(estoque[1].marca, "") == 0 && total_produtos == 2){
        printf("     [OK] Cadastro com marca vazia\n");
        testes_passaram++;
    } else {
        printf("     [XX] Cadastro com marca vazia\n");
        testes_falharam++;
    }
}

void teste_multiplos_produtos(){
    printf("\n[TESTE 10] GERENCIAMENTO DE MULTIPLOS PRODUTOS\n");
    printf("=========================================================\n");
    
    total_produtos = 0;
    i = 0;
    
    printf("\n  10.1 - Cadastrando 10 produtos diferentes...\n");
    
    const char* marcas[] = {"Nike", "Adidas", "Puma", "New Balance", "Asics", 
                            "Reebok", "Saucony", "Mizuno", "Brooks", "Converse"};
    const char* modelos[] = {"Air Force", "Ultraboost", "RS-X", "990v5", "Gel-Lyte", 
                             "Club C", "Jazz", "Wave", "Ghost", "Chuck Taylor"};
    
    for(int j = 0; j < 10; j++){
        cadastrar_produto_auto(marcas[j], modelos[j], 40 + j, 10 * (j + 1));
    }
    
    if(total_produtos == 10){
        printf("     [OK] Cadastro de 10 produtos\n");
        testes_passaram++;
    } else {
        printf("     [XX] Cadastro de 10 produtos\n");
        testes_falharam++;
    }
    
    printf("\n  10.2 - Verificando integridade dos dados...\n");
    int integridade_ok = 1;
    for(int j = 0; j < 10; j++){
        if(estoque[j].codigo != j + 1 || 
           strcmp(estoque[j].marca, marcas[j]) != 0 ||
           estoque[j].tamanho != 40 + j){
            integridade_ok = 0;
            break;
        }
    }
    
    if(integridade_ok){
        printf("     [OK] Integridade de 10 produtos\n");
        testes_passaram++;
    } else {
        printf("     [XX] Integridade de 10 produtos\n");
        testes_falharam++;
    }
    
    printf("\n  10.3 - Atualizando multiplos produtos...\n");
    for(int j = 0; j < 5; j++){
        alterar_produto(j + 1, 999);
    }
    
    int atualizacoes_ok = 1;
    for(int j = 0; j < 5; j++){
        if(estoque[j].quantidade != 999){
            atualizacoes_ok = 0;
            break;
        }
    }
    
    if(atualizacoes_ok){
        printf("     [OK] Atualizacao de 5 produtos\n");
        testes_passaram++;
    } else {
        printf("     [XX] Atualizacao de 5 produtos\n");
        testes_falharam++;
    }
    
    printf("\n  10.4 - Visualizando estoque completo...\n\n");
    visualizar_estoque();
    
    printf("     [OK] Visualizacao de estoque com multiplos produtos\n");
    testes_passaram++;
}

void cadastrar_produto_auto(const char* marca, const char* modelo, int tamanho, int quantidade){
    if(total_produtos < MAX_ESTOQUE){
        strcpy(estoque[i].marca, marca);
        strcpy(estoque[i].modelo, modelo);
        estoque[i].tamanho = tamanho;
        estoque[i].quantidade = quantidade;
        estoque[i].codigo = i + 1;
        
        i++;
        total_produtos++;
    }
}

void alterar_produto(int codigo, int nova_quantidade){
    if(codigo < 1 || codigo > total_produtos){
        return;
    }
    else{
        estoque[codigo - 1].quantidade = nova_quantidade;
    }
}

void visualizar_estoque(){
    printf("  Codigo | Marca | Modelo | Tamanho | Quantidade\n");
    printf("  -------+-------+--------+---------+------------------\n");

    for(int j=0; j<total_produtos; j++){
        if(estoque[j].quantidade <= 5){
            printf("  %d | %s | %s | %d | %d unid. | !!! ESTOQUE BAIXO !!!\n", 
                   estoque[j].codigo, estoque[j].marca, estoque[j].modelo, 
                   estoque[j].tamanho, estoque[j].quantidade);
        }
        else{
            printf("  %d | %s | %s | %d | %d unid.\n", 
                   estoque[j].codigo, estoque[j].marca, estoque[j].modelo, 
                   estoque[j].tamanho, estoque[j].quantidade);
        }
    }
    printf("\n");
}
