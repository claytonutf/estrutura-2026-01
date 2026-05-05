#include <cstdlib>   // malloc, free
#include <stdio.h>  // (não utilizado diretamente, mas mantido)
#include <iostream> // cout, endl
#include <cstring>  // strcpy

using namespace std;

// =====================
// Constante de tamanho máximo
// =====================
#define MAX 100

// =====================
// Estrutura: Cliente
// Representa um registro da lista
// =====================
struct cliente {
    int cpf;
    char nome[50];
};

// =====================
// Estrutura: Lista Estática
// - qtde: quantidade atual de elementos
// - dados: vetor fixo de clientes
// =====================
struct lista {
    int qtde;
    cliente dados[MAX];
};

// Tipo abstrato Lista
typedef struct lista Lista;

// Ponteiro global para lista (uso didático)
Lista *li;

// =====================
// Função: cria_lista
// Aloca dinamicamente uma lista
// Inicializa quantidade com 0
// =====================
Lista* cria_lista() {
    Lista *li = (Lista*) malloc(sizeof(struct lista));

    if (li != NULL) {
        li->qtde = 0; // lista inicia vazia
    }

    return li;
}

// =====================
// Função: libera_lista
// Libera toda a memória da lista
// OBS: Como é lista estática (vetor),
// não há nós individuais para liberar
// =====================
void libera_lista(Lista* li) {
    free(li);
}

// =====================
// Função: tamanho_lista
// Retorna a quantidade de elementos
// =====================
int tamanho_lista(Lista* li) {
    if (li == NULL) {
        return -1; // erro
    }
    return li->qtde;
}

// =====================
// Função: lista_cheia
// Verifica se atingiu capacidade máxima
// =====================
int lista_cheia(Lista *li) {
    if (li == NULL) {
        return -1; // erro
    }
    return (li->qtde == MAX);
}

// =====================
// Função: lista_vazia
// Verifica se não possui elementos
// =====================
int lista_vazia(Lista *li) {
    if (li == NULL) {
        return -1; // erro
    }
    return (li->qtde == 0);
}

// =====================
// Função: insere_lista_final
// Insere elemento no final da lista
//
// Lógica:
// - Verifica se lista existe
// - Verifica se há espaço
// - Insere na posição qtde
// - Incrementa qtde
// =====================
int insere_lista_final(Lista *li, cliente cl) {
    if (li == NULL) {
        return 0; // erro
    }

    if (li->qtde == MAX) {
        return 0; // lista cheia
    }

    li->dados[li->qtde] = cl; // insere no final
    li->qtde++;               // atualiza quantidade

    return 1; // sucesso
}

// =====================
// Função: imprime_lista
// Percorre e exibe todos os elementos
// =====================
void imprime_lista(Lista *li) {
    if (li == NULL) {
        cout << "Lista inexistente!" << endl;
        return;
    }

    if (li->qtde == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    // Percorrendo a lista
    for (int i = 0; i < li->qtde; i++) {
        cout << "Elemento " << i << endl;
        cout << "CPF: " << li->dados[i].cpf << endl;
        cout << "Nome: " << li->dados[i].nome << endl;
        cout << "---------------------" << endl;
    }
}

// =====================
// Função principal (main)
// Demonstra uso da lista
// =====================
int main() {

    cout << "Funcao Main" << endl;

    // Criação da lista
    li = cria_lista();

    // =====================
    // Inserção do cliente 1
    // =====================
    cliente c1;
    c1.cpf = 111;
    strcpy(c1.nome, "Cliente 1");

    if (insere_lista_final(li, c1)) {
        cout << "Inserido com sucesso!" << endl;
    } else {
        cout << "Erro ao inserir!" << endl;
    }

    // =====================
    // Inserção do cliente 2
    // =====================
    cliente c2;
    c2.cpf = 222;
    strcpy(c2.nome, "Cliente 2");

    if (insere_lista_final(li, c2)) {
        cout << "Inserido com sucesso!" << endl;
    } else {
        cout << "Erro ao inserir!" << endl;
    }

    // =====================
    // Exibição de dados
    // =====================
    cout << "Tamanho da lista: " << tamanho_lista(li) << endl;

    imprime_lista(li);

    // =====================
    // Liberação de memória
    // =====================
    libera_lista(li);

    return 0;
}