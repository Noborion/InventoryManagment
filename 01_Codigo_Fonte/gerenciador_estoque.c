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
int i = 0, auxtam;


// FUNÇÕES
void menu();
void cadastrar_produto();
void alterar_produto();
void visualizar_estoque();
int validacao_tamanho(int tam);
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

            default:
                if(opcao != 4){
                    printf("\nOPCAO INVALIDA!\n");
                    break;
                }
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
        limpar_tela();

        printf("  Digite o modelo: ");
        fgets(estoque[i].modelo, sizeof(estoque[i].modelo), stdin); 
        estoque[i].modelo[strcspn(estoque[i].modelo, "\n")] = 0;
        limpar_tela();

        
        do{
            printf("  Digite um tamanho valido (Min: 20, Max: 50): ");
            scanf("%d", &auxtam);
            estoque[i].tamanho = validacao_tamanho(auxtam);

        }while(estoque[i].tamanho < 20 || estoque[i].tamanho > 50);
        limpar_tela();

        do{
            printf("  Digite a quantidade (Min: 0, Max: 50): ");
            scanf("%d", &estoque[i].quantidade);
            if(estoque[i].quantidade < 0 || estoque[i].quantidade > MAX_POR_PROD){
                printf("\n  Quantidade invalida! Deve ser entre 0 e %d.\n\n", MAX_POR_PROD);
            }
        }while(estoque[i].quantidade < 0 || estoque[i].quantidade > MAX_POR_PROD);
        limpar_tela();
        estoque[i].codigo = i + 1;
        
        i++;
        total_produtos++;

    } else {
        printf("\n  Estoque cheio. Não é mais possível.");
    }
}

void alterar_produto(){
    int aux;

    printf("  Digite o codigo do produto a ser alterado (Para sair digite: 0): ");
    scanf("%d", &aux);

    if(aux < 0 || aux > total_produtos){
        limpar_tela();
        printf("\n  ***Codigo invalido***");
        return;
    }
    else if(aux == 0){
        limpar_tela();
        return;
    }
    else{
        int opcao_alterar;
        
        do{
            printf("\n\n  +============================================+\n");
            printf("  |                                            |\n");
            printf("  |   [1] Alterar marca                        |\n");
            printf("  |   [2] Alterar modelo                       |\n");
            printf("  |   [3] Alterar tamanho                      |\n");
            printf("  |   [4] Alterar quantidade                   |\n");
            printf("  |   [5] Voltar ao menu                       |\n");
            printf("  |                                            |\n");
            printf("  +============================================+\n\n");

            printf("  >> Digite a opcao desejada: ");
            scanf("%d", &opcao_alterar);
            limpar_tela();

            switch(opcao_alterar){
                case 1:
                    while (getchar() != '\n');
                    printf("  Digite a nova marca: ");
                    fgets(estoque[aux - 1].marca, sizeof(estoque[aux - 1].marca), stdin);
                    estoque[aux - 1].marca[strcspn(estoque[aux - 1].marca, "\n")] = 0;
                    limpar_tela();
                    printf("\n  ***Marca atualizada com sucesso***");
                    break;

                case 2:
                    while (getchar() != '\n');
                    printf("  Digite o novo modelo: ");
                    fgets(estoque[aux - 1].modelo, sizeof(estoque[aux - 1].modelo), stdin); 
                    estoque[aux - 1].modelo[strcspn(estoque[aux - 1].modelo, "\n")] = 0;
                    limpar_tela();
                    printf("\n  ***Modelo atualizado com sucesso***");
                    break;

                case 3:
                    do{
                        printf("  Digite o novo tamanho (Min: 20, Max: 50): ");
                        scanf("%d", &auxtam);
                        estoque[aux - 1].tamanho = validacao_tamanho(auxtam);

                    }while(estoque[aux - 1].tamanho < 20 || estoque[aux - 1].tamanho > 50);
                    limpar_tela();
                    printf("\n  ***Tamanho atualizado com sucesso***");
                    break;

                case 4:
                    do{
                        printf("  Digite a nova quantidade (Min: 0, Max: 50): ");
                        scanf("%d", &estoque[aux - 1].quantidade);
                        if(estoque[aux - 1].quantidade < 0 || estoque[aux - 1].quantidade > MAX_POR_PROD){
                            printf("\n  Quantidade invalida! Deve ser entre 0 e %d.\n\n", MAX_POR_PROD);
                        }
                    }while(estoque[aux - 1].quantidade < 0 || estoque[aux - 1].quantidade > MAX_POR_PROD);
                    limpar_tela();
                    printf("\n  ***Quantidade atualizada com sucesso***");
                    break;
                    
                default:
                    if(opcao_alterar != 5){
                        printf("  Opcao invalida!\n");
                        break;
                    }
            }
        }while(opcao_alterar != 5);
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

int validacao_tamanho(int tam){
    if(tam < 20 || tam > 50){
        printf("  \nTamanho invalido! Deve ser entre 20 e 50.\n\n");
        return tam;
    }
    else{
        return tam;
    }
}

void limpar_tela(){
    printf("\033[H\033[2J");
}