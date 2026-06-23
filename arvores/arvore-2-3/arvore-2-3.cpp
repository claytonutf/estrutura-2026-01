#include <iostream>

using namespace std;

// ==================================================
// Estrutura do nó da Árvore 2-3
// ==================================================
struct NO23 {
    int chave1;          // primeira chave
    int chave2;          // segunda chave

    int numChaves;       // quantidade de chaves (1 ou 2)

    NO23* esq;           // filho esquerdo
    NO23* centro;        // filho central
    NO23* dir;           // filho direito
};

// Tipo da árvore
typedef NO23* Arv23;

// ==================================================
// Criação da árvore
// ==================================================
Arv23* cria_Arv23() {
    Arv23* raiz = new Arv23;

    if (raiz != nullptr)
        *raiz = nullptr;

    return raiz;
}

// ==================================================
// Criação de um nó
// ==================================================
NO23* cria_NO23(int valor) {
    NO23* novo = new NO23;

    novo->chave1 = valor;
    novo->chave2 = 0;

    novo->numChaves = 1;

    novo->esq = nullptr;
    novo->centro = nullptr;
    novo->dir = nullptr;

    return novo;
}

// ==================================================
// Liberação dos nós
// ==================================================
void libera_NO23(NO23* no) {
    if (no == nullptr)
        return;

    libera_NO23(no->esq);
    libera_NO23(no->centro);
    libera_NO23(no->dir);

    delete no;
}

// ==================================================
// Liberação da árvore
// ==================================================
void libera_Arv23(Arv23* raiz) {
    if (raiz == nullptr)
        return;

    libera_NO23(*raiz);
    delete raiz;
}

// ==================================================
// Verifica se o nó é folha
// ==================================================
bool ehFolha(NO23* no) {
    if (no == nullptr)
        return false;

    return (no->esq == nullptr &&
            no->centro == nullptr &&
            no->dir == nullptr);
}

// ==================================================
// Inserção simplificada
// Apenas para demonstração da estrutura.
// Não realiza split.
// ==================================================
bool insere_Arv23(Arv23* raiz, int valor) {

    if (raiz == nullptr)
        return false;

    // árvore vazia
    if (*raiz == nullptr) {
        *raiz = cria_NO23(valor);
        return true;
    }

    NO23* atual = *raiz;

    while (!ehFolha(atual)) {

        if (valor < atual->chave1)
            atual = atual->esq;

        else if (atual->numChaves == 1 ||
                 valor < atual->chave2)
            atual = atual->centro;

        else
            atual = atual->dir;
    }

    // folha com espaço disponível
    if (atual->numChaves == 1) {

        if (valor < atual->chave1) {
            atual->chave2 = atual->chave1;
            atual->chave1 = valor;
        }
        else {
            atual->chave2 = valor;
        }

        atual->numChaves = 2;

        return true;
    }

    cout << "Nó cheio. Necessário realizar SPLIT." << endl;
    return false;
}

// ==================================================
// Percurso em ordem
// ==================================================
void emOrdem(NO23* no) {

    if (no == nullptr)
        return;

    if (no->numChaves == 1) {

        emOrdem(no->esq);

        cout << no->chave1 << " ";

        emOrdem(no->centro);
    }
    else {

        emOrdem(no->esq);

        cout << no->chave1 << " ";

        emOrdem(no->centro);

        cout << no->chave2 << " ";

        emOrdem(no->dir);
    }
}

// ==================================================
// Programa principal
// ==================================================
int main() {

    Arv23* raiz = cria_Arv23();

    insere_Arv23(raiz, 10);
    insere_Arv23(raiz, 20);

    cout << "Percurso em ordem: ";
    emOrdem(*raiz);
    cout << endl;

    libera_Arv23(raiz);

    return 0;
}