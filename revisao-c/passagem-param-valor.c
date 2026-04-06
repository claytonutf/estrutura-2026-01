#include <stdio.h>

// Função que recebe um parâmetro por valor
void alteraValor(int x) {
    x = x + 10;
    printf("Dentro da função, x = %d\n", x);
}

int main() {
    int num = 5;

    printf("Antes da função, num = %d\n", num);

    alteraValor(num);

    printf("Depois da função, num = %d\n", num);

    return 0;
}
