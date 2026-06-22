#include <iostream>

using namespace std;

#define RED true
#define BLACK false

struct NO {
    int info;
    bool cor;
    NO* esq;
    NO* dir;

    NO(int valor) {
        info = valor;
        cor = RED;
        esq = nullptr;
        dir = nullptr;
    }
};

class ArvoreLLRB {
private:

    NO* raiz;

    bool cor(NO* H) {
        if (H == nullptr)
            return BLACK;

        return H->cor;
    }

    void trocaCor(NO* H) {
        H->cor = !H->cor;

        if (H->esq != nullptr)
            H->esq->cor = !H->esq->cor;

        if (H->dir != nullptr)
            H->dir->cor = !H->dir->cor;
    }

    NO* rotacionaEsquerda(NO* A) {
        NO* B = A->dir;

        A->dir = B->esq;
        B->esq = A;

        B->cor = A->cor;
        A->cor = RED;

        return B;
    }

    NO* rotacionaDireita(NO* A) {
        NO* B = A->esq;

        A->esq = B->dir;
        B->dir = A;

        B->cor = A->cor;
        A->cor = RED;

        return B;
    }

    NO* insereNO(NO* H, int valor, bool& inseriu) {

        if (H == nullptr) {
            inseriu = true;
            return new NO(valor);
        }

        if (valor < H->info)
            H->esq = insereNO(H->esq, valor, inseriu);

        else if (valor > H->info)
            H->dir = insereNO(H->dir, valor, inseriu);

        else {
            inseriu = false;
            return H;
        }

        if (cor(H->dir) == RED &&
            cor(H->esq) == BLACK)
            H = rotacionaEsquerda(H);

        if (cor(H->esq) == RED &&
            cor(H->esq->esq) == RED)
            H = rotacionaDireita(H);

        if (cor(H->esq) == RED &&
            cor(H->dir) == RED)
            trocaCor(H);

        return H;
    }

    bool busca(NO* H, int valor) {

        if (H == nullptr)
            return false;

        if (valor == H->info)
            return true;

        if (valor < H->info)
            return busca(H->esq, valor);

        return busca(H->dir, valor);
    }

    void emOrdem(NO* H) {

        if (H == nullptr)
            return;

        emOrdem(H->esq);

        cout << H->info
             << " ("
             << (H->cor == RED ? "R" : "B")
             << ") ";

        emOrdem(H->dir);
    }

    void imprimeEstrutura(NO* H, int nivel) {

        if (H == nullptr)
            return;

        imprimeEstrutura(H->dir, nivel + 1);

        for (int i = 0; i < nivel; i++)
            cout << "    ";

        cout << H->info
             << (H->cor == RED ? "(R)" : "(B)")
             << endl;

        imprimeEstrutura(H->esq, nivel + 1);
    }

    void destruir(NO* H) {

        if (H == nullptr)
            return;

        destruir(H->esq);
        destruir(H->dir);

        delete H;
    }

public:

    ArvoreLLRB() {
        raiz = nullptr;
    }

    ~ArvoreLLRB() {
        destruir(raiz);
    }

    bool inserir(int valor) {

        bool inseriu = false;

        raiz = insereNO(raiz, valor, inseriu);

        if (raiz != nullptr)
            raiz->cor = BLACK;

        return inseriu;
    }

    bool consultar(int valor) {
        return busca(raiz, valor);
    }

    void imprimirEmOrdem() {

        cout << "\nPercurso em ordem:\n";
        emOrdem(raiz);
        cout << endl;
    }

    void imprimirArvore() {

        cout << "\nEstrutura da LLRB:\n\n";
        imprimeEstrutura(raiz, 0);
    }
};

int main() {

    ArvoreLLRB arvore;

    int opcao;
    int valor;

    do {

        cout << "\n========== ARVORE RUBRO-NEGRA LLRB ==========\n";
        cout << "1 - Inserir\n";
        cout << "2 - Buscar\n";
        cout << "3 - Exibir em ordem\n";
        cout << "4 - Exibir estrutura\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {

        case 1:

            cout << "Valor: ";
            cin >> valor;

            if (arvore.inserir(valor))
                cout << "Inserido com sucesso.\n";
            else
                cout << "Valor duplicado.\n";

            break;

        case 2:

            cout << "Valor: ";
            cin >> valor;

            if (arvore.consultar(valor))
                cout << "Encontrado.\n";
            else
                cout << "Nao encontrado.\n";

            break;

        case 3:

            arvore.imprimirEmOrdem();
            break;

        case 4:

            arvore.imprimirArvore();
            break;
        }

    } while (opcao != 0);

    return 0;
}