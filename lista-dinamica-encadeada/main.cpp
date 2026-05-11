#include <iostream>
using namespace std;

// =====================
// Definição do aluno
// =====================
// Estrutura que representa um registro armazenado na lista
// Funciona como o "dado" do nó
struct aluno{
    int matricula;     // chave de ordenação
    char nome[30];     // nome do aluno (array de char - estilo C)
    float n1,n2,n3;    // três notas
};

// =====================
// Definição da lista
// =====================
// Cada elemento da lista encadeada é um nó
// contendo:
// 1) os dados (aluno)
// 2) um ponteiro para o próximo elemento
struct elemento{
    aluno dados;        // informação armazenada
    elemento *prox;     // ponteiro para o próximo nó
};

// Definição do tipo Lista:
// Lista é um ponteiro para elemento
// Ou seja, Lista aponta para o primeiro nó
typedef elemento* Lista;

// =====================
// Funções da lista
// =====================

// Cria uma lista vazia
// Retorna um ponteiro para ponteiro (Lista*)
// Isso permite alterar o início da lista dentro das funções
Lista* cria_lista(){
    Lista* li = new Lista;   // aloca ponteiro para lista
    if(li != nullptr)
        *li = nullptr;       // lista começa vazia
    return li;
}

// Libera toda a memória da lista
// Percorre nó por nó e desaloca
void libera_lista(Lista* li){
    if(li != nullptr){
        elemento* no;
        while(*li != nullptr){      // enquanto houver elementos
            no = *li;               // guarda o primeiro nó
            *li = (*li)->prox;      // avança a lista
            delete no;              // libera o nó antigo
        }
        delete li;                  // libera o ponteiro da lista
    }
}

// Retorna o número de elementos da lista
int tamanho_lista(Lista* li){
    if(li == nullptr)
        return 0;

    int cont = 0;
    elemento* no = *li;   // começa no primeiro elemento

    // percorre toda a lista
    while(no != nullptr){
        cont++;
        no = no->prox;
    }

    return cont;
}

int insere_lista_final(Lista* li, aluno al){
    if(li == nullptr)
        return 0;

    // cria novo nó
    elemento *no = new elemento;
    if(no == nullptr)
        return 0;

    no->dados = al;
    no->prox = nullptr; // será o último

    // caso a lista esteja vazia
    if(*li == nullptr){
        *li = no;
    } else {
        elemento *aux = *li;

        // percorre até o último nó
        while(aux->prox != nullptr){
            aux = aux->prox;
        }

        // liga o último nó ao novo
        aux->prox = no;
    }

    return 1;
}

// Insere um elemento mantendo a lista ordenada pela matrícula
int insere_lista_ordenada(Lista* li, aluno al){
    if(li == nullptr)
        return 0;

    // cria novo nó
    elemento *no = new elemento;
    if(no == nullptr)
        return 0;

    no->dados = al; // copia os dados do aluno

    // ponteiros auxiliares:
    // ant = nó anterior
    // atual = nó atual
    elemento *ant = nullptr;
    elemento *atual = *li;

    // percorre até encontrar posição de inserção
    while(atual != nullptr && atual->dados.matricula < al.matricula){
        ant = atual;
        atual = atual->prox;
    }

    // inserção no início da lista
    if(ant == nullptr){
        no->prox = *li;
        *li = no;
    } 
    // inserção no meio ou final
    else {
        no->prox = atual;
        ant->prox = no;
    }

    return 1;
}

// Remove o último elemento da lista
int remove_lista_final(Lista* li){
    if(li == nullptr || *li == nullptr)
        return 0;

    elemento *ant = nullptr;
    elemento *no = *li;

    // percorre até o último nó
    while(no->prox != nullptr){
        ant = no;
        no = no->prox;
    }

    // caso tenha apenas um elemento
    if(ant == nullptr)
        *li = nullptr;
    else
        ant->prox = nullptr;

    delete no; // libera memória

    return 1;
}


/*
Para remover um nó intermediário em uma lista simplesmente encadeada, normalmente é necessário:

localizar o nó que será removido;
guardar o nó anterior;
fazer o nó anterior apontar para o próximo do nó removido;
liberar a memória do nó removido.

A lógica seria semelhante à utilizada em remove_lista_final, mas interrompendo no elemento desejado.

Exemplo de implementação removendo pela matrícula:
*/
int remove_lista_meio(Lista* li, int mat){
    if(li == nullptr || *li == nullptr)
        return 0;

    elemento *ant = nullptr;
    elemento *no = *li;

    // procura o elemento
    while(no != nullptr && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }

    // elemento não encontrado
    if(no == nullptr)
        return 0;

    // remoção do primeiro elemento
    if(ant == nullptr){
        *li = no->prox;
    }
    // remoção do meio ou final
    else{
        ant->prox = no->prox;
    }

    delete no;

    return 1;
}

// Imprime todos os elementos da lista
void imprime_lista(Lista* li){
    if(li == nullptr)
        return;

    elemento* no = *li;

    // percorre e imprime cada nó
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
// MAIN (programa principal)
// =====================
int main(){

    // Vetor de alunos (dados de entrada)
    aluno a[4] = {
        {2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}
    };

    // Criação da lista
    Lista* li = cria_lista();

    cout << "Tamanho inicial: " << tamanho_lista(li) << endl;

    // =====================
    // Inserção ordenada
    // =====================
    // Os elementos são inseridos fora de ordem
    for(int i = 0; i < 4; i++)
        insere_lista_final(li, a[i]);

    cout << "\nLista após inserção:\n";
    imprime_lista(li);

    cout << "\nTamanho: " << tamanho_lista(li) << endl;

    // =====================
    // Remoções
    // =====================
    cout << "\nAntes da remoção da matrícula 1:\n";
    imprime_lista(li);
    remove_lista_meio(li, 1);
    cout << "\nApós a remoção da matrícula 1:\n";
    imprime_lista(li);
    

    // Remove sempre o último elemento
    for(int i = 0; i < 4; i++){
        remove_lista_final(li);
        cout << "\nApós remoção:\n";
        imprime_lista(li);
        cout << "Tamanho: " << tamanho_lista(li) << endl;
    }

    // =====================
    // Inserindo novamente
    // =====================
    for(int i = 0; i < 4; i++)
        insere_lista_final(li, a[i]);

    cout << "\nLista final:\n";
    imprime_lista(li);

    // Liberação de memória
    libera_lista(li);

    

    return 0;
}