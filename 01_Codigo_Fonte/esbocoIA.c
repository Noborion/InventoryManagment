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

// Funções de interface
void limpar_tela();
void desenhar_linha(char caractere, int tamanho);
void cabecalho(const char* titulo);
void menu_principal();
void pausar();

// Funções de gerenciamento
void cadastrar_produto();
void listar_produtos();
void buscar_produto();
void editar_produto();
void excluir_produto();
void relatorio_estoque();

// Funções auxiliares
int encontrar_produto_vazio();
void exibir_produto(int indice);
int validar_entrada_numero(const char* prompt, int min, int max);

// Função principal
int main() {
    // Inicializar todos os produtos como inativos
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        estoque[i].ativo = 0;
    }
    
    int opcao;
    
    do {
        limpar_tela();
        menu_principal();
        
        printf("\n  >> Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            // Limpar buffer de entrada
            while (getchar() != '\n');
            opcao = 0;
        }
        
        switch(opcao) {
            case 1:
                cadastrar_produto();
                break;
            case 2:
                listar_produtos();
                break;
            case 3:
                buscar_produto();
                break;
            case 4:
                editar_produto();
                break;
            case 5:
                excluir_produto();
                break;
            case 6:
                relatorio_estoque();
                break;
            case 0:
                limpar_tela();
                cabecalho("SAINDO DO SISTEMA");
                printf("\n  Obrigado por usar o Gerenciador de Estoque!\n");
                printf("  Sistema encerrado com sucesso.\n\n");
                break;
            default:
                printf("\n  [ERRO] Opcao invalida! Tente novamente.\n");
                pausar();
                break;
        }
    } while(opcao != 0);
    
    return 0;
}

// Limpar a tela (funciona em Windows e Linux)
void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Desenhar uma linha decorativa
void desenhar_linha(char caractere, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%c", caractere);
    }
    printf("\n");
}

// Exibir cabeçalho formatado
void cabecalho(const char* titulo) {
    int largura = 60;
    int espaco = (largura - strlen(titulo) - 2) / 2;
    
    desenhar_linha('=', largura);
    printf("%*s %s %*s\n", espaco, "", titulo, espaco, "");
    desenhar_linha('=', largura);
}

// Menu principal
void menu_principal() {
    cabecalho("GERENCIADOR DE ESTOQUE - LOJA DE TENIS");
    printf("\n");
    printf("  +----------------------------------------+\n");
    printf("  |  [1] Cadastrar Produto                |\n");
    printf("  |  [2] Listar Produtos                  |\n");
    printf("  |  [3] Buscar Produto                   |\n");
    printf("  |  [4] Editar Produto                   |\n");
    printf("  |  [5] Excluir Produto                  |\n");
    printf("  |  [6] Relatorio de Estoque             |\n");
    printf("  |  [0] Sair                             |\n");
    printf("  +----------------------------------------+\n");
}

// Pausar a execução
void pausar() {
    printf("\n  Pressione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
}

// Validar entrada numérica
int validar_entrada_numero(const char* prompt, int min, int max) {
    int valor;
    printf("  %s", prompt);
    
    while (1) {
        if (scanf("%d", &valor) != 1) {
            while (getchar() != '\n');
            printf("  [ERRO] Entrada invalida! Digite um numero: ");
            continue;
        }
        
        if (valor < min || valor > max) {
            printf("  [ERRO] Valor deve estar entre %d e %d! Tente novamente: ", min, max);
            continue;
        }
        
        return valor;
    }
}

// Encontrar índice de produto vazio
int encontrar_produto_vazio() {
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (!estoque[i].ativo) {
            return i;
        }
    }
    return -1; // Estoque cheio
}

// Exibir produto formatado
void exibir_produto(int indice) {
    if (indice < 0 || indice >= MAX_PRODUTOS || !estoque[indice].ativo) {
        return;
    }
    
    printf("  +----------------------------------------+\n");
    printf("  | Codigo: %-30d |\n", indice + 1);
    printf("  | Marca:  %-30s |\n", estoque[indice].marca);
    printf("  | Modelo: %-30s |\n", estoque[indice].modelo);
    printf("  | Tamanho: %-29d |\n", estoque[indice].tamanho);
    printf("  | Qtd:    %-30d |\n", estoque[indice].quantidade);
    printf("  +----------------------------------------+\n");
}

// Cadastrar novo produto
void cadastrar_produto() {
    limpar_tela();
    cabecalho("CADASTRAR PRODUTO");
    
    if (total_produtos >= MAX_PRODUTOS) {
        printf("\n  [ERRO] Estoque cheio! Nao e possivel cadastrar mais produtos.\n");
        pausar();
        return;
    }
    
    int indice = encontrar_produto_vazio();
    if (indice == -1) {
        printf("\n  [ERRO] Nao foi possivel encontrar espaco no estoque.\n");
        pausar();
        return;
    }
    
    printf("\n  Preencha os dados do produto:\n\n");
    
    // Limpar buffer
    while (getchar() != '\n');
    
    // Marca
    printf("  Marca: ");
    fgets(estoque[indice].marca, TAM_STRING, stdin);
    estoque[indice].marca[strcspn(estoque[indice].marca, "\n")] = 0;
    
    // Modelo
    printf("  Modelo: ");
    fgets(estoque[indice].modelo, TAM_STRING, stdin);
    estoque[indice].modelo[strcspn(estoque[indice].modelo, "\n")] = 0;
    
    // Tamanho
    estoque[indice].tamanho = validar_entrada_numero("Tamanho (ex: 36, 37, 38...): ", 20, 50);
    
    // Quantidade
    estoque[indice].quantidade = validar_entrada_numero("Quantidade em estoque: ", 0, 10000);
    
    // Ativar produto
    estoque[indice].ativo = 1;
    total_produtos++;
    
    printf("\n  [SUCESSO] Produto cadastrado com sucesso!\n");
    printf("  Codigo do produto: %d\n", indice + 1);
    pausar();
}

// Listar todos os produtos
void listar_produtos() {
    limpar_tela();
    cabecalho("LISTAR PRODUTOS");
    
    if (total_produtos == 0) {
        printf("\n  [AVISO] Nenhum produto cadastrado no estoque.\n");
        pausar();
        return;
    }
    
    printf("\n  Total de produtos cadastrados: %d\n\n", total_produtos);
    
    int contador = 0;
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (estoque[i].ativo) {
            exibir_produto(i);
            printf("\n");
            contador++;
        }
    }
    
    if (contador == 0) {
        printf("  [AVISO] Nenhum produto ativo encontrado.\n");
    }
    
    pausar();
}

// Buscar produto
void buscar_produto() {
    limpar_tela();
    cabecalho("BUSCAR PRODUTO");
    
    if (total_produtos == 0) {
        printf("\n  [AVISO] Nenhum produto cadastrado no estoque.\n");
        pausar();
        return;
    }
    
    printf("\n  Opcoes de busca:\n");
    printf("  [1] Por codigo\n");
    printf("  [2] Por marca\n");
    printf("  [3] Por modelo\n");
    printf("  [4] Por tamanho\n");
    
    int opcao = validar_entrada_numero("\n  Escolha uma opcao: ", 1, 4);
    
    while (getchar() != '\n'); // Limpar buffer
    
    int encontrados = 0;
    
    switch(opcao) {
        case 1: { // Por código
            int codigo = validar_entrada_numero("\n  Digite o codigo do produto: ", 1, MAX_PRODUTOS);
            int indice = codigo - 1;
            
            if (indice >= 0 && indice < MAX_PRODUTOS && estoque[indice].ativo) {
                printf("\n  Produto encontrado:\n\n");
                exibir_produto(indice);
                encontrados = 1;
            } else {
                printf("\n  [AVISO] Produto nao encontrado ou inativo.\n");
            }
            break;
        }
        case 2: { // Por marca
            char busca_marca[TAM_STRING];
            printf("\n  Digite a marca: ");
            fgets(busca_marca, TAM_STRING, stdin);
            busca_marca[strcspn(busca_marca, "\n")] = 0;
            
            printf("\n  Resultados da busca:\n\n");
            for (int i = 0; i < MAX_PRODUTOS; i++) {
                if (estoque[i].ativo && strstr(estoque[i].marca, busca_marca) != NULL) {
                    exibir_produto(i);
                    printf("\n");
                    encontrados++;
                }
            }
            break;
        }
        case 3: { // Por modelo
            char busca_modelo[TAM_STRING];
            printf("\n  Digite o modelo: ");
            fgets(busca_modelo, TAM_STRING, stdin);
            busca_modelo[strcspn(busca_modelo, "\n")] = 0;
            
            printf("\n  Resultados da busca:\n\n");
            for (int i = 0; i < MAX_PRODUTOS; i++) {
                if (estoque[i].ativo && strstr(estoque[i].modelo, busca_modelo) != NULL) {
                    exibir_produto(i);
                    printf("\n");
                    encontrados++;
                }
            }
            break;
        }
        case 4: { // Por tamanho
            int busca_tamanho = validar_entrada_numero("\n  Digite o tamanho: ", 20, 50);
            
            printf("\n  Resultados da busca:\n\n");
            for (int i = 0; i < MAX_PRODUTOS; i++) {
                if (estoque[i].ativo && estoque[i].tamanho == busca_tamanho) {
                    exibir_produto(i);
                    printf("\n");
                    encontrados++;
                }
            }
            break;
        }
    }
    
    if (encontrados == 0 && opcao != 1) {
        printf("  [AVISO] Nenhum produto encontrado.\n");
    }
    
    pausar();
}

// Editar produto
void editar_produto() {
    limpar_tela();
    cabecalho("EDITAR PRODUTO");
    
    if (total_produtos == 0) {
        printf("\n  [AVISO] Nenhum produto cadastrado no estoque.\n");
        pausar();
        return;
    }
    
    int codigo = validar_entrada_numero("\n  Digite o codigo do produto a editar: ", 1, MAX_PRODUTOS);
    int indice = codigo - 1;
    
    if (indice < 0 || indice >= MAX_PRODUTOS || !estoque[indice].ativo) {
        printf("\n  [ERRO] Produto nao encontrado ou inativo.\n");
        pausar();
        return;
    }
    
    printf("\n  Produto atual:\n\n");
    exibir_produto(indice);
    
    printf("\n  Digite os novos dados (pressione ENTER para manter o valor atual):\n\n");
    
    while (getchar() != '\n'); // Limpar buffer
    
    // Marca
    char nova_marca[TAM_STRING];
    printf("  Nova marca [atual: %s]: ", estoque[indice].marca);
    fgets(nova_marca, TAM_STRING, stdin);
    nova_marca[strcspn(nova_marca, "\n")] = 0;
    if (strlen(nova_marca) > 0) {
        strcpy(estoque[indice].marca, nova_marca);
    }
    
    // Modelo
    char novo_modelo[TAM_STRING];
    printf("  Novo modelo [atual: %s]: ", estoque[indice].modelo);
    fgets(novo_modelo, TAM_STRING, stdin);
    novo_modelo[strcspn(novo_modelo, "\n")] = 0;
    if (strlen(novo_modelo) > 0) {
        strcpy(estoque[indice].modelo, novo_modelo);
    }
    
    // Tamanho
    char entrada_tamanho[10];
    printf("  Novo tamanho [atual: %d] (ENTER para manter): ", estoque[indice].tamanho);
    fgets(entrada_tamanho, 10, stdin);
    if (strlen(entrada_tamanho) > 1) {
        estoque[indice].tamanho = atoi(entrada_tamanho);
        if (estoque[indice].tamanho < 20 || estoque[indice].tamanho > 50) {
            printf("  [AVISO] Tamanho invalido, mantendo valor anterior.\n");
            // Reverter para o valor original seria necessário, mas simplificando
        }
    }
    
    // Quantidade
    char entrada_qtd[10];
    printf("  Nova quantidade [atual: %d] (ENTER para manter): ", estoque[indice].quantidade);
    fgets(entrada_qtd, 10, stdin);
    if (strlen(entrada_qtd) > 1) {
        int nova_qtd = atoi(entrada_qtd);
        if (nova_qtd >= 0) {
            estoque[indice].quantidade = nova_qtd;
        }
    }
    
    printf("\n  [SUCESSO] Produto editado com sucesso!\n");
    printf("\n  Produto atualizado:\n\n");
    exibir_produto(indice);
    pausar();
}

// Excluir produto
void excluir_produto() {
    limpar_tela();
    cabecalho("EXCLUIR PRODUTO");
    
    if (total_produtos == 0) {
        printf("\n  [AVISO] Nenhum produto cadastrado no estoque.\n");
        pausar();
        return;
    }
    
    int codigo = validar_entrada_numero("\n  Digite o codigo do produto a excluir: ", 1, MAX_PRODUTOS);
    int indice = codigo - 1;
    
    if (indice < 0 || indice >= MAX_PRODUTOS || !estoque[indice].ativo) {
        printf("\n  [ERRO] Produto nao encontrado ou ja excluido.\n");
        pausar();
        return;
    }
    
    printf("\n  Produto a ser excluido:\n\n");
    exibir_produto(indice);
    
    printf("\n  Tem certeza que deseja excluir este produto? (s/n): ");
    char confirmacao;
    while (getchar() != '\n'); // Limpar buffer
    scanf("%c", &confirmacao);
    
    if (confirmacao == 's' || confirmacao == 'S') {
        estoque[indice].ativo = 0;
        total_produtos--;
        printf("\n  [SUCESSO] Produto excluido com sucesso!\n");
    } else {
        printf("\n  Operacao cancelada.\n");
    }
    
    pausar();
}

// Relatório de estoque
void relatorio_estoque() {
    limpar_tela();
    cabecalho("RELATORIO DE ESTOQUE");
    
    if (total_produtos == 0) {
        printf("\n  [AVISO] Nenhum produto cadastrado no estoque.\n");
        pausar();
        return;
    }
    
    int total_quantidade = 0;
    int produtos_baixo_estoque = 0;
    int maior_estoque = 0;
    int menor_estoque = 10000;
    
    printf("\n  +----------------------------------------+\n");
    printf("  | ESTATISTICAS DO ESTOQUE               |\n");
    printf("  +----------------------------------------+\n");
    
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        if (estoque[i].ativo) {
            total_quantidade += estoque[i].quantidade;
            
            if (estoque[i].quantidade < 10) {
                produtos_baixo_estoque++;
            }
            
            if (estoque[i].quantidade > maior_estoque) {
                maior_estoque = estoque[i].quantidade;
            }
            
            if (estoque[i].quantidade < menor_estoque) {
                menor_estoque = estoque[i].quantidade;
            }
        }
    }
    
    printf("  | Total de produtos: %-18d |\n", total_produtos);
    printf("  | Total de unidades: %-18d |\n", total_quantidade);
    printf("  | Produtos com estoque baixo: %-9d |\n", produtos_baixo_estoque);
    printf("  | Maior estoque: %-23d |\n", maior_estoque);
    printf("  | Menor estoque: %-23d |\n", menor_estoque);
    printf("  +----------------------------------------+\n");
    
    if (produtos_baixo_estoque > 0) {
        printf("\n  [ATENCAO] Produtos com estoque baixo (< 10 unidades):\n\n");
        for (int i = 0; i < MAX_PRODUTOS; i++) {
            if (estoque[i].ativo && estoque[i].quantidade < 10) {
                printf("  - Codigo %d: %s %s (Tamanho %d) - %d unidades\n",
                       i + 1, estoque[i].marca, estoque[i].modelo,
                       estoque[i].tamanho, estoque[i].quantidade);
            }
        }
    }
    
    pausar();
}

