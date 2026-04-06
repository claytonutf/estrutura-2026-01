#include <stdio.h>

// Função que recebe um ponteiro (referência ao valor original)
void alteraValor(int *x) {

    printf("Dentro da função (antes):\n");
    printf("*x = %d\n", *x);
    printf("Endereço de x (&x) = %p\n", (void*)&x);
    printf("Valor de x (endereço de num) = %p\n", (void*)x);

    *x = *x + 10;

    printf("\nDentro da função (depois):\n");
    printf("*x = %d\n", *x);
    printf("Endereço de x (&x) = %p\n", (void*)&x);
    printf("Valor de x (endereço de num) = %p\n", (void*)x);
}

int main() {
    int num = 5;

    printf("Antes da função:\n");
    printf("num = %d\n", num);
    printf("Endereço de num (&num) = %p\n\n", (void*)&num);

    alteraValor(&num); // passando o endereço de num

    printf("\nDepois da função:\n");
    printf("num = %d\n", num);
    printf("Endereço de num (&num) = %p\n\n", (void*)&num);

    return 0;
}
