#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main() {
    Pessoa *lista = NULL; // ponteiro para o vetor
    int tamanho = 0;      // quantidade de elementos
    int opcao;

    do {
        printf("\n1 - Adicionar pessoa\n");
        printf("2 - Listar pessoas\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Aumenta o vetor em 1 posição

            // C puro
            // Compilar com: gcc lista-pessoas-vetor-dinamico-c.c -o programa
            // Pessoa *temp = realloc(lista, (tamanho + 1) * sizeof(Pessoa));


            // Código alternativo
            // Funciona, mas não é C puro
            Pessoa *temp = (Pessoa *) realloc(lista, (tamanho + 1) * sizeof(Pessoa));

            
            if (temp == NULL) {
                printf("Erro de alocacao!\n");
                free(lista);
                return 1;
            }

            lista = temp;

            // Limpa buffer do ENTER
            getchar();

            printf("Nome: ");
            fgets(lista[tamanho].nome, 50, stdin);

            // Remove '\n' do fgets
            // strcspn calcula quantos caracteres iniciais de uma string NÃO contêm nenhum caractere de outra string. A função percorre str1 até encontrar o primeiro caractere que aparece em str2. Ela retorna a posição onde isso acontece
            lista[tamanho].nome[strcspn(lista[tamanho].nome, "\n")] = '\0';

            printf("Idade: ");
            scanf("%d", &lista[tamanho].idade);

            tamanho++;
        }

        else if (opcao == 2) {
            printf("\n--- Lista de Pessoas ---\n");

            for (int i = 0; i < tamanho; i++) {
                printf("Pessoa %d:\n", i + 1);
                printf("Nome: %s\n", lista[i].nome);
                printf("Idade: %d\n\n", lista[i].idade);
            }
        }

    } while (opcao != 0);

    // Libera memória
    free(lista);

    return 0;
}
