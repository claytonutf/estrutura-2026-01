#include <iostream>

using namespace std;

// Definição do nó da árvore
struct NO {
    int info;
    NO* esq;
    NO* dir;
};

// ArvBin é um ponteiro para NO
typedef NO* ArvBin;

// Cria uma árvore vazia
ArvBin* cria_ArvBin() {
    ArvBin* raiz = new ArvBin;

    if (raiz != nullptr)
        *raiz = nullptr;

    return raiz;
}

// Libera todos os nós da árvore
void libera_NO(NO* no) {
    if (no == nullptr)
        return;

    libera_NO(no->esq);
    libera_NO(no->dir);

    delete no;
}

// Libera a estrutura da árvore
void libera_ArvBin(ArvBin* raiz) {
    if (raiz == nullptr)
        return;

    libera_NO(*raiz);  // libera todos os nós
    delete raiz;       // libera o ponteiro da raiz
}

// Função auxiliar para inserir nós (apenas para teste)
bool insere_ArvBin(ArvBin* raiz, int valor) {
    if (raiz == nullptr)
        return false;

    NO* novo = new NO;
    novo->info = valor;
    novo->esq = nullptr;
    novo->dir = nullptr;

    if (*raiz == nullptr) {
        *raiz = novo;
        return true;
    }

    NO* atual = *raiz;

    while (true) {
        if (valor < atual->info) {
            if (atual->esq == nullptr) {
                atual->esq = novo;
                return true;
            }
            atual = atual->esq;
        }
        else {
            if (atual->dir == nullptr) {
                atual->dir = novo;
                return true;
            }
            atual = atual->dir;
        }
    }
}

// Percurso em ordem (para teste)
void emOrdem(NO* no) {
    if (no == nullptr)
        return;

    emOrdem(no->esq);
    cout << no->info << " ";
    emOrdem(no->dir);
}

int main() {
    // Cria a árvore
    ArvBin* raiz = cria_ArvBin();

    // Insere alguns valores
    insere_ArvBin(raiz, 10);
    insere_ArvBin(raiz, 5);
    insere_ArvBin(raiz, 20);
    insere_ArvBin(raiz, 3);
    insere_ArvBin(raiz, 7);

    cout << "Percurso em ordem: ";
    emOrdem(*raiz);
    cout << endl;

    // Libera a árvore
    libera_ArvBin(raiz);

    return 0;
}