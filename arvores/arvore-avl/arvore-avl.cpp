// ======================================================
// Implementação de Árvore AVL em um único arquivo (.cpp)
// ======================================================

#include <iostream>
#include <cstdlib>

using namespace std;

struct NO {
    int info;
    int alt;
    NO* esq;
    NO* dir;
};

typedef NO* ArvAVL;

// ------------------------------------------------------
// Funções auxiliares
// ------------------------------------------------------

int maior(int x, int y) {
    return (x > y) ? x : y;
}

int altura_NO(NO* no) {
    if (no == NULL)
        return -1;

    return no->alt;
}

int fatorBalanceamento_NO(NO* no) {
    if (no == NULL)
        return 0;

    return abs(altura_NO(no->esq) - altura_NO(no->dir));
}

// ------------------------------------------------------
// Rotações
// ------------------------------------------------------

void RotacaoLL(ArvAVL* raiz) {
    NO* no;

    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;

    (*raiz)->alt =
        maior(altura_NO((*raiz)->esq),
               altura_NO((*raiz)->dir)) + 1;

    no->alt =
        maior(altura_NO(no->esq),
               altura_NO(no->dir)) + 1;

    *raiz = no;
}

void RotacaoRR(ArvAVL* raiz) {
    NO* no;

    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;

    (*raiz)->alt =
        maior(altura_NO((*raiz)->esq),
               altura_NO((*raiz)->dir)) + 1;

    no->alt =
        maior(altura_NO(no->esq),
               altura_NO(no->dir)) + 1;

    *raiz = no;
}

void RotacaoLR(ArvAVL* raiz) {
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

void RotacaoRL(ArvAVL* raiz) {
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
}

// ------------------------------------------------------
// Inserção
// ------------------------------------------------------

int insere_ArvAVL(ArvAVL* raiz, int valor) {
    int res;

    if (*raiz == NULL) {
        NO* novo = new NO;

        if (novo == NULL)
            return 0;

        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;

        *raiz = novo;

        return 1;
    }

    NO* atual = *raiz;

    if (valor < atual->info) {

        if ((res = insere_ArvAVL(&(atual->esq), valor)) == 1) {

            if (fatorBalanceamento_NO(atual) >= 2) {

                if (valor < atual->esq->info)
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }

    } else if (valor > atual->info) {

        if ((res = insere_ArvAVL(&(atual->dir), valor)) == 1) {

            if (fatorBalanceamento_NO(atual) >= 2) {

                if (valor > atual->dir->info)
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }

    } else {
        cout << "Valor duplicado!" << endl;
        return 0;
    }

    atual->alt =
        maior(altura_NO(atual->esq),
               altura_NO(atual->dir)) + 1;

    return res;
}

// ------------------------------------------------------
// Procura o menor elemento
// ------------------------------------------------------

NO* procuraMenor(NO* atual) {

    while (atual != NULL && atual->esq != NULL)
        atual = atual->esq;

    return atual;
}

// ------------------------------------------------------
// Remoção
// ------------------------------------------------------

int remove_ArvAVL(ArvAVL* raiz, int valor) {

    if (*raiz == NULL) {
        cout << "Valor não existe!" << endl;
        return 0;
    }

    int res = 0;

    if (valor < (*raiz)->info) {

        if ((res = remove_ArvAVL(&(*raiz)->esq, valor)) == 1) {

            if (fatorBalanceamento_NO(*raiz) >= 2) {

                if (altura_NO((*raiz)->dir->esq) <=
                    altura_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }

    } else if (valor > (*raiz)->info) {

        if ((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1) {

            if (fatorBalanceamento_NO(*raiz) >= 2) {

                if (altura_NO((*raiz)->esq->dir) <=
                    altura_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }

    } else {

        if ((*raiz)->esq == NULL || (*raiz)->dir == NULL) {

            NO* oldNode = *raiz;

            if ((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;

            delete oldNode;

        } else {

            NO* temp = procuraMenor((*raiz)->dir);

            (*raiz)->info = temp->info;

            remove_ArvAVL(&(*raiz)->dir, temp->info);

            if (fatorBalanceamento_NO(*raiz) >= 2) {

                if (altura_NO((*raiz)->esq->dir) <=
                    altura_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }

        if (*raiz != NULL) {

            (*raiz)->alt =
                maior(altura_NO((*raiz)->esq),
                       altura_NO((*raiz)->dir)) + 1;
        }

        return 1;
    }

    if (*raiz != NULL) {

        (*raiz)->alt =
            maior(altura_NO((*raiz)->esq),
                   altura_NO((*raiz)->dir)) + 1;
    }

    return res;
}

// ------------------------------------------------------
// Percurso em ordem
// ------------------------------------------------------

void emOrdem(ArvAVL raiz) {

    if (raiz != NULL) {

        emOrdem(raiz->esq);

        cout << raiz->info
             << " (h=" << raiz->alt << ") ";

        emOrdem(raiz->dir);
    }
}

// ------------------------------------------------------
// Programa principal
// ------------------------------------------------------

int main() {

    ArvAVL raiz = NULL;

    insere_ArvAVL(&raiz, 50);
    insere_ArvAVL(&raiz, 30);
    insere_ArvAVL(&raiz, 70);
    insere_ArvAVL(&raiz, 20);
    insere_ArvAVL(&raiz, 40);
    insere_ArvAVL(&raiz, 60);
    insere_ArvAVL(&raiz, 80);
    insere_ArvAVL(&raiz, 10);

    cout << "Árvore AVL (em ordem):" << endl;
    emOrdem(raiz);

    cout << endl << endl;

    cout << "Removendo 30..." << endl;

    remove_ArvAVL(&raiz, 30);

    cout << "Árvore após remoção:" << endl;
    emOrdem(raiz);

    cout << endl;

    return 0;
}

