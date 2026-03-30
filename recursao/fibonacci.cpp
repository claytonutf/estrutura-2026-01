#include <iostream>
using namespace std;

/*
Lógica da Sequência de Fibonacci

Exemplo: n = 8
Sequência: 1 1 2 3 5 8 13 21
Resultado: 21
*/
int fibonacci(int n) {

    // caso base
    if (n == 0)
        return 0;
    // caso base
    else if (n == 1)
        return 1;

    else
        // caso recursivo
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int n = 8;
    int resultado = fibonacci(n);
    cout << resultado << endl;

    return 0;
}