#include <stdio.h>
#include <iostream>
using namespace std;

/*
Lógica do Fatorial

Exemplo: n = 5
Chamadas recursivas
5! = 5 * 4!
4! = 4 * 3!
3! = 3 * 2!
2! = 2 * 1!
1! = 1 * 0!
0! = 1  // caso base
Resultado: 120

n! = n * (n-1)!
0! = 1
*/

int fatorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * fatorial(n-1);
    }
}

int main(){

    int n = 5;
    cout<<"Fatorial de "<< n <<" é: "<<fatorial(n)<<endl;

    return 0;
}