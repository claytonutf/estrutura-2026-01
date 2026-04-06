#include <stdio.h>

int main() {
    // Declaração das variáveis
    int idade;
    float altura;
    double peso;
    char letra;
    char nome[5];  // string (vetor de caracteres)

    // ================================
    // Entrada de inteiro
    // ================================
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    // ================================
    // Entrada de float
    // ================================
    printf("Digite sua altura (ex: 1.75): ");
    scanf("%f", &altura);

    // ================================
    // Entrada de double
    // ================================
    printf("Digite seu peso (ex: 70.5): ");
    scanf("%lf", &peso);

    // ================================
    // Entrada de caractere
    // OBS: o espaço antes de %c limpa o buffer
    // ================================
    printf("Digite uma letra: ");
    scanf(" %c", &letra);

    // ================================
    // Entrada de string (sem espaços)
    // ================================
    printf("Digite seu nome (sem espaços): ");
    scanf("%s", nome);

    // ================================
    // Exibindo os dados
    // ================================
    printf("\n--- Dados informados ---\n");
    printf("Idade: %d\n", idade);
    printf("Altura: %.2f\n", altura);
    printf("Peso: %.2lf\n", peso);
    printf("Letra: %c\n", letra);
    printf("Nome: %s\n", nome);

    // ================================
    // Entrada de string COM espaços
    // ================================
    printf("\nDigite seu nome completo: ");

    // Limpa o ENTER que ficou no buffer
    getchar();

    // fgets permite ler com espaços
    fgets(nome, 50, stdin);

    printf("Nome completo: %s\n", nome);

    return 0;
}
