#include <iostream>
using namespace std;

// =====================
// Definição do aluno
// =====================
// Estrutura que representa os dados armazenados na pilha
struct aluno{
    int matricula;     // identificador do aluno
    char nome[30];     // nome do aluno
    float n1, n2, n3;  // notas
};

// =====================
// Definição do nó
// =====================
// Cada elemento da pilha será um nó encadeado
struct elemento{
    aluno dados;        // dados armazenados
    elemento *prox;     // ponteiro para o próximo nó
};

// =====================
// Definição da pilha
// =====================
// Pilha é um ponteiro para elemento
// O topo da pilha será o primeiro nó
typedef elemento* Pilha;

// =====================
// Funções da pilha
// =====================

// Cria uma pilha vazia
Pilha* cria_pilha(){

    // aloca ponteiro para pilha
    Pilha *pi = new Pilha;

    if(pi != nullptr)
        *pi = nullptr;

    return pi;
}

// =====================
// Libera toda a memória da pilha
// =====================
void libera_pilha(Pilha *pi){

    if(pi != nullptr){

        elemento *no;

        // remove todos os elementos
        while(*pi != nullptr){

            no = *pi;

            // topo avança para o próximo
            *pi = (*pi)->prox;

            delete no;
        }

        delete pi;
    }
}

// =====================
// Retorna o tamanho da pilha
// =====================
int tamanho_pilha(Pilha *pi){

    if(pi == nullptr)
        return 0;

    int cont = 0;

    elemento *no = *pi;

    // percorre toda a pilha
    while(no != nullptr){

        cont++;

        no = no->prox;
    }

    return cont;
}

// =====================
// Insere elemento no topo
// PUSH
// =====================
int insere_pilha(Pilha *pi, aluno al){

    if(pi == nullptr)
        return 0;

    // cria novo nó
    elemento *no = new elemento;

    if(no == nullptr)
        return 0;

    // copia os dados
    no->dados = al;

    // novo nó aponta para o topo atual
    no->prox = *pi;

    // novo nó vira o topo
    *pi = no;

    return 1;
}

// =====================
// Remove elemento do topo
// POP
// =====================
int remove_pilha(Pilha *pi){

    if(pi == nullptr || *pi == nullptr)
        return 0;

    // guarda o topo
    elemento *no = *pi;

    // topo avança
    *pi = no->prox;

    // libera memória
    delete no;

    return 1;
}

// =====================
// Consulta o topo da pilha
// TOP / PEEK
// =====================
int consulta_topo_pilha(Pilha *pi, aluno *al){

    if(pi == nullptr || *pi == nullptr)
        return 0;

    // copia os dados do topo
    *al = (*pi)->dados;

    return 1;
}

// =====================
// Imprime a pilha
// =====================
void imprime_pilha(Pilha *pi){

    if(pi == nullptr)
        return;

    elemento *no = *pi;

    cout << "\n===== PILHA =====\n";

    // percorre do topo até a base
    while(no != nullptr){

        cout << "Matricula: "
             << no->dados.matricula << endl;

        cout << "Nome: "
             << no->dados.nome << endl;

        cout << "Notas: "
             << no->dados.n1 << " "
             << no->dados.n2 << " "
             << no->dados.n3 << endl;

        cout << "-------------------------" << endl;

        no = no->prox;
    }
}

// =====================
// MAIN
// =====================
int main(){

    // =====================
    // Dados de exemplo
    // =====================
    aluno a[4] = {

        {1,"Andre",9.5,7.8,8.5},
        {2,"Ricardo",7.5,8.7,6.8},
        {3,"Bianca",9.7,6.7,8.4},
        {4,"Ana",5.7,6.1,7.4}
    };

    // =====================
    // Criação da pilha
    // =====================
    Pilha *pi = cria_pilha();

    cout << "Tamanho inicial da pilha: "
         << tamanho_pilha(pi) << endl;

    // =====================
    // Inserções na pilha
    // =====================
    // Inserção ocorre no TOPO
    for(int i = 0; i < 4; i++){

        cout << "\nInserindo: "
             << a[i].nome << endl;

        insere_pilha(pi, a[i]);
    }

    // imprime pilha
    imprime_pilha(pi);

    cout << "Tamanho da pilha: "
         << tamanho_pilha(pi) << endl;

    // =====================
    // Consulta topo
    // =====================
    aluno aux;

    if(consulta_topo_pilha(pi, &aux)){

        cout << "\nTopo da pilha:\n";

        cout << "Matricula: "
             << aux.matricula << endl;

        cout << "Nome: "
             << aux.nome << endl;
    }

    // =====================
    // Remoções da pilha
    // =====================
    // Remoção ocorre no TOPO
    for(int i = 0; i < 4; i++){

        cout << "\nAntes da remocao:\n";

        imprime_pilha(pi);

        remove_pilha(pi);

        cout << "\nDepois da remocao:\n";

        imprime_pilha(pi);

        cout << "Tamanho atual: "
             << tamanho_pilha(pi) << endl;
    }

    // =====================
    // Liberação de memória
    // =====================
    libera_pilha(pi);

    return 0;
}