// BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// CONSTANTES
#define TAM_MAX_STRING 50
#define MAX_ESTOQUE 50
#define MAX_POR_PROD 50


// STRUCTS
typedef struct{
    char marca[TAM_MAX_STRING];
    char modelo[TAM_MAX_STRING];
    int tamanho;
    int quantidade;
    int codigo;
} produto;


// VARIAVEIS GLOBAIS
produto estoque[MAX_ESTOQUE];
int total_produtos = 0;
int i = 0;


// FUNÇÕES
void menu();
void cadastrar_produto();
void alterar_produto();
void visualizar_estoque();
void linha();
void limpar_tela();


int main(){
    int opcao;

    limpar_tela();

    do{

        menu();
        printf("  >> Escolha uma opcao: ");
        scanf("%d", &opcao);
        limpar_tela();

        switch(opcao){
            case 1: 
                cadastrar_produto();
                limpar_tela();
                printf("\n  ***Produto cadastrado com sucesso***\n");
                break;

            case 2:
                visualizar_estoque();
                printf("\n\n");
                alterar_produto();
                break;

            case 3:
                visualizar_estoque();
                break;

            default: if (opcao>4) printf("\nOPCAO INVALIDA!\n"); break;
        }

    }while(opcao != 4);

    return 0;
}

void menu(){
    printf("\n\n  +========= Bem-Vindo a Sneaker King =========+\n");
    printf("  |                                            |\n");
    printf("  |   Selecione uma opcao:                     |\n");
    printf("  |                                            |\n");
    printf("  |   [1] Cadastrar Produto                    |\n");
    printf("  |   [2] Atualizar produto                    |\n");
    printf("  |   [3] Visualizar estoque                   |\n");
    printf("  |   [4] Sair                                 |\n");
    printf("  |                                            |\n");
    printf("  +============================================+\n\n");
}

void cadastrar_produto(){

    if(total_produtos < MAX_ESTOQUE){

        while (getchar() != '\n');

        printf("  Digite a marca: ");
        fgets(estoque[i].marca, sizeof(estoque[i].marca), stdin);
        estoque[i].marca[strcspn(estoque[i].marca, "\n")] = 0;

        printf("  Digite o modelo: ");
        fgets(estoque[i].modelo, sizeof(estoque[i].modelo), stdin); 
        estoque[i].modelo[strcspn(estoque[i].modelo, "\n")] = 0;

        printf("  Digite o tamanho: ");
        scanf("%d", &estoque[i].tamanho);

        do{
            printf("  Digite a quantidade: ");
            scanf("%d", &estoque[i].quantidade);
            if(estoque[i].quantidade < 0 || estoque[i].quantidade > MAX_POR_PROD){
                printf("  \nQuantidade invalida! Deve ser entre 0 e %d.\n\n", MAX_POR_PROD);
            }
        }while(estoque[i].quantidade < 0 || estoque[i].quantidade > MAX_POR_PROD);
        estoque[i].codigo = i + 1;
        
        i++;
        total_produtos++;

    } else {
        printf("\nEstoque cheio. Não é mais possível.");
    }
}

void alterar_produto(){
    int aux;

    printf("  Digite o codigo do produto: ");
    scanf("%d", &aux);

    if(estoque[aux - 1].codigo < 0 || aux > total_produtos){
        printf("  Codigo invalido!\n");
        return;
    }
    else{
        do{
            printf("  Digite a nova quantidade: ");
            scanf("%d", &estoque[aux - 1].quantidade);
            if(estoque[aux - 1].quantidade < 0 || estoque[aux - 1].quantidade > MAX_POR_PROD){
                printf("\n  Quantidade invalida! Deve ser entre 0 e %d.\n\n", MAX_POR_PROD);
            }
        }while(estoque[aux - 1].quantidade < 0 || estoque[aux - 1].quantidade > MAX_POR_PROD);
    }

}

void visualizar_estoque(){

    printf("\n  +================== Estoque Atual ==================+\n");
    printf("\n\n  Codigo do produto| Marca | Modelo | Tamanho | Quantidade |\n\n");

    for(int j=0; j<total_produtos; j++){

        if(estoque[j].quantidade == 0){
            printf("  %d| %s | %s | %d | %d unid. | *** EM FALTA ***\n", estoque[j].codigo, estoque[j].marca, estoque[j].modelo, estoque[j].tamanho, estoque[j].quantidade);
        }
        else if(estoque[j].quantidade <= 5){
            printf("  %d| %s | %s | %d | %d unid. | *** ESTOQUE BAIXO ***\n", estoque[j].codigo, estoque[j].marca, estoque[j].modelo, estoque[j].tamanho, estoque[j].quantidade);
        }
        else{
            printf("  %d| %s | %s | %d | %d unid. |\n", estoque[j].codigo, estoque[j].marca, estoque[j].modelo, estoque[j].tamanho, estoque[j].quantidade);
        }
    }
}

void limpar_tela(){
    printf("\033[H\033[2J");
}