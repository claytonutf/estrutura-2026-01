#include <iostream>
using namespace std;

// =====================
// Definição do aluno
// =====================
// Estrutura que representa os dados armazenados na fila
struct aluno{
    int matricula;     // identificador do aluno
    char nome[30];     // nome do aluno
    float n1, n2, n3;  // notas
};

// =====================
// Definição do nó
// =====================
// Cada elemento da fila será um nó encadeado
struct elemento{
    aluno dados;        // dados armazenados
    elemento *prox;     // ponteiro para o próximo nó
};

// =====================
// Definição da fila
// =====================
// A fila precisa controlar:
// 1) início da fila
// 2) final da fila
struct fila{
    elemento *inicio;   // primeiro elemento
    elemento *final;    // último elemento
};

// Tipo Fila = ponteiro para struct fila
typedef fila* Fila;

// =====================
// Funções da fila
// =====================

// Cria uma fila vazia
Fila cria_fila(){

    // aloca memória para a fila
    Fila fi = new fila;

    if(fi != nullptr){
        fi->inicio = nullptr;
        fi->final = nullptr;
    }

    return fi;
}

// =====================
// Libera toda a memória da fila
// =====================
void libera_fila(Fila fi){

    if(fi != nullptr){

        elemento *no;

        // percorre toda a fila removendo elemento por elemento
        while(fi->inicio != nullptr){

            no = fi->inicio;

            // avança o início
            fi->inicio = fi->inicio->prox;

            delete no;
        }

        delete fi;
    }
}

// =====================
// Retorna o tamanho da fila
// =====================
int tamanho_fila(Fila fi){

    if(fi == nullptr)
        return 0;

    int cont = 0;

    elemento *no = fi->inicio;

    // percorre toda a fila
    while(no != nullptr){
        cont++;
        no = no->prox;
    }

    return cont;
}

// =====================
// Insere elemento no final da fila
// ENQUEUE
// =====================
int insere_fila(Fila fi, aluno al){

    if(fi == nullptr)
        return 0;

    // cria novo nó
    elemento *no = new elemento;

    if(no == nullptr)
        return 0;

    no->dados = al;

    // novo nó será o último
    no->prox = nullptr;

    // =====================
    // Caso fila vazia
    // =====================
    if(fi->inicio == nullptr){

        fi->inicio = no;
        fi->final = no;
    }

    // =====================
    // Caso fila já tenha elementos
    // =====================
    else{

        // último nó aponta para o novo
        fi->final->prox = no;

        // atualiza o final
        fi->final = no;
    }

    return 1;
}

// =====================
// Remove elemento do início da fila
// DEQUEUE
// =====================
int remove_fila(Fila fi){

    if(fi == nullptr || fi->inicio == nullptr)
        return 0;

    // guarda o primeiro nó
    elemento *no = fi->inicio;

    // avança o início
    fi->inicio = fi->inicio->prox;

    // =====================
    // Se a fila ficou vazia
    // =====================
    if(fi->inicio == nullptr)
        fi->final = nullptr;

    // libera memória
    delete no;

    return 1;
}

// =====================
// Consulta o primeiro elemento da fila
// FRONT / PEEK
// =====================
int consulta_fila(Fila fi, aluno *al){

    if(fi == nullptr || fi->inicio == nullptr)
        return 0;

    // copia os dados do primeiro elemento
    *al = fi->inicio->dados;

    return 1;
}

// =====================
// Imprime toda a fila
// =====================
void imprime_fila(Fila fi){

    if(fi == nullptr)
        return;

    elemento *no = fi->inicio;

    cout << "\n===== FILA =====\n";

    // percorre toda a fila
    while(no != nullptr){

        cout << "Matricula: " << no->dados.matricula << endl;
        cout << "Nome: " << no->dados.nome << endl;

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
    // Criação da fila
    // =====================
    Fila fi = cria_fila();

    cout << "Tamanho inicial da fila: "
         << tamanho_fila(fi) << endl;

    // =====================
    // Inserções na fila
    // =====================
    // Inserção ocorre no FINAL
    for(int i = 0; i < 4; i++){

        cout << "\nInserindo: "
             << a[i].nome << endl;

        insere_fila(fi, a[i]);
    }

    // imprime fila
    imprime_fila(fi);

    cout << "Tamanho da fila: "
         << tamanho_fila(fi) << endl;

    // =====================
    // Consulta primeiro elemento
    // =====================
    aluno aux;

    if(consulta_fila(fi, &aux)){

        cout << "\nPrimeiro da fila:\n";

        cout << "Matricula: "
             << aux.matricula << endl;

        cout << "Nome: "
             << aux.nome << endl;
    }

    // =====================
    // Remoções da fila
    // =====================
    // Remoção ocorre no INÍCIO
    for(int i = 0; i < 4; i++){

        cout << "\nAntes da remocao:\n";
        imprime_fila(fi);

        remove_fila(fi);

        cout << "\nDepois da remocao:\n";
        imprime_fila(fi);

        cout << "Tamanho atual: "
             << tamanho_fila(fi) << endl;
    }

    // =====================
    // Liberação de memória
    // =====================
    libera_fila(fi);

    return 0;
}