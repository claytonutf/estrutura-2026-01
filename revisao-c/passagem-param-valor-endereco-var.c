#include <stdio.h>

// Função que recebe um parâmetro por valor
void alteraValor(int x) {
    printf("Dentro da função (antes): x = %d | endereço = %p\n", x, (void*)&x);

    x = x + 10;

    printf("Dentro da função (depois): x = %d | endereço = %p\n", x, (void*)&x);
}

int main() {
    int num = 5;

    printf("Antes da função: num = %d | endereço = %p\n", num, (void*)&num);

    alteraValor(num);

    printf("Depois da função: num = %d | endereço = %p\n", num, (void*)&num);

    return 0;
}
