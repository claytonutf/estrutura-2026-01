#include <iostream>
using namespace std;

// =====================================================
// DEFINIÇÃO DO ALUNO
// =====================================================
// Estrutura que representa os dados armazenados na fila
struct aluno{
    int matricula;     // identificador do aluno
    char nome[30];     // nome do aluno
    float n1, n2, n3;  // notas
};

// =====================================================
// DEFINIÇÃO DO NÓ
// =====================================================
// Cada elemento da fila possui:
//
// 1) dados
// 2) ponteiro para o próximo
// 3) ponteiro para o anterior
//
// Isso caracteriza uma estrutura duplamente encadeada
struct elemento{
    aluno dados;

    elemento *prox;   // próximo nó
    elemento *ant;    // nó anterior
};

// =====================================================
// DEFINIÇÃO DA FILA
// =====================================================
// A fila controla:
//
// inicio -> primeiro elemento
// final   -> último elemento
struct fila{
    elemento *inicio;
    elemento *final;
};

// Tipo Fila
typedef fila* Fila;

// =====================================================
// CRIA FILA
// =====================================================
Fila cria_fila(){

    Fila fi = new fila;

    if(fi != nullptr){

        fi->inicio = nullptr;
        fi->final = nullptr;
    }

    return fi;
}

// =====================================================
// LIBERA FILA
// =====================================================
// Remove todos os nós da memória
void libera_fila(Fila fi){

    if(fi != nullptr){

        elemento *no;

        // percorre removendo todos os nós
        while(fi->inicio != nullptr){

            no = fi->inicio;

            fi->inicio = fi->inicio->prox;

            delete no;
        }

        delete fi;
    }
}

// =====================================================
// TAMANHO DA FILA
// =====================================================
int tamanho_fila(Fila fi){

    if(fi == nullptr)
        return 0;

    int cont = 0;

    elemento *no = fi->inicio;

    while(no != nullptr){

        cont++;

        no = no->prox;
    }

    return cont;
}

// =====================================================
// INSERÇÃO NO FINAL
// =====================================================
// ENQUEUE
//
// Inserção ocorre no final da fila
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

    // =================================================
    // FILA VAZIA
    // =================================================
    if(fi->inicio == nullptr){

        no->ant = nullptr;

        fi->inicio = no;
        fi->final = no;
    }

    // =================================================
    // FILA COM ELEMENTOS
    // =================================================
    else{

        // novo nó aponta para o antigo final
        no->ant = fi->final;

        // antigo final aponta para novo nó
        fi->final->prox = no;

        // atualiza final
        fi->final = no;
    }

    return 1;
}

// =====================================================
// REMOÇÃO NO INÍCIO
// =====================================================
// DEQUEUE
//
// Remove o primeiro elemento da fila
int remove_fila(Fila fi){

    if(fi == nullptr || fi->inicio == nullptr)
        return 0;

    // guarda primeiro nó
    elemento *no = fi->inicio;

    // =================================================
    // FILA COM APENAS 1 ELEMENTO
    // =================================================
    if(fi->inicio == fi->final){

        fi->inicio = nullptr;
        fi->final = nullptr;
    }

    // =================================================
    // FILA COM VÁRIOS ELEMENTOS
    // =================================================
    else{

        fi->inicio = fi->inicio->prox;

        // novo início não possui anterior
        fi->inicio->ant = nullptr;
    }

    delete no;

    return 1;
}

// =====================================================
// CONSULTA PRIMEIRO ELEMENTO
// =====================================================
int consulta_inicio(Fila fi, aluno *al){

    if(fi == nullptr || fi->inicio == nullptr)
        return 0;

    *al = fi->inicio->dados;

    return 1;
}

// =====================================================
// CONSULTA ÚLTIMO ELEMENTO
// =====================================================
int consulta_final(Fila fi, aluno *al){

    if(fi == nullptr || fi->final == nullptr)
        return 0;

    *al = fi->final->dados;

    return 1;
}

// =====================================================
// IMPRESSÃO NORMAL
// =====================================================
// Percorre do início para o final
void imprime_inicio_final(Fila fi){

    if(fi == nullptr)
        return;

    elemento *no = fi->inicio;

    cout << "\n===== FILA (INICIO -> FINAL) =====\n";

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

// =====================================================
// IMPRESSÃO REVERSA
// =====================================================
// Percorre do final para o início
//
// Isso só é possível facilmente porque
// a estrutura é duplamente encadeada
void imprime_final_inicio(Fila fi){

    if(fi == nullptr)
        return;

    elemento *no = fi->final;

    cout << "\n===== FILA (FINAL -> INICIO) =====\n";

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

        no = no->ant;
    }
}

// =====================================================
// MAIN
// =====================================================
int main(){

    // =================================================
    // Dados de exemplo
    // =================================================
    aluno a[4] = {

        {1,"Andre",9.5,7.8,8.5},
        {2,"Ricardo",7.5,8.7,6.8},
        {3,"Bianca",9.7,6.7,8.4},
        {4,"Ana",5.7,6.1,7.4}
    };

    // =================================================
    // Criação da fila
    // =================================================
    Fila fi = cria_fila();

    cout << "Tamanho inicial: "
         << tamanho_fila(fi) << endl;

    // =================================================
    // Inserções
    // =================================================
    for(int i = 0; i < 4; i++){

        cout << "\nInserindo: "
             << a[i].nome << endl;

        insere_fila(fi, a[i]);
    }

    // =================================================
    // Impressão normal
    // =================================================
    imprime_inicio_final(fi);

    // =================================================
    // Impressão reversa
    // =================================================
    imprime_final_inicio(fi);

    cout << "\nTamanho da fila: "
         << tamanho_fila(fi) << endl;

    // =================================================
    // Consulta início e final
    // =================================================
    aluno aux;

    if(consulta_inicio(fi, &aux)){

        cout << "\nPrimeiro da fila:\n";

        cout << "Matricula: "
             << aux.matricula << endl;

        cout << "Nome: "
             << aux.nome << endl;
    }

    if(consulta_final(fi, &aux)){

        cout << "\nUltimo da fila:\n";

        cout << "Matricula: "
             << aux.matricula << endl;

        cout << "Nome: "
             << aux.nome << endl;
    }

    // =================================================
    // Remoções
    // =================================================
    for(int i = 0; i < 4; i++){

        cout << "\nAntes da remocao:\n";

        imprime_inicio_final(fi);

        remove_fila(fi);

        cout << "\nDepois da remocao:\n";

        imprime_inicio_final(fi);

        cout << "Tamanho atual: "
             << tamanho_fila(fi) << endl;
    }

    // =================================================
    // Liberação de memória
    // =================================================
    libera_fila(fi);

    return 0;
}