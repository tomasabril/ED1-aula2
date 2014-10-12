/* entrega dia 21/10/14
Criar um programa para manipular uma lista duplamente encadeada
o O programa deverá apresentar um menu com as seguintes opções:

1. Inclusão no início da lista
2. Inclusão no fim da lista
3. Remoção do início da lista
4. Remoção do fim da lista
5. Impressão da lista com valor do topo, e todos os nós, contendo
o endereço do nó, valor, endereço do ponteiro direito e do
ponteiro esquerdo.
*/
///Tomás Abril
///Allan Patrick

#include <stdio.h>
#include <iostream>

using namespace std;

int incluiIni();
int incluiFim();
int removeIni();
int removeFim();
int imprimeLista();

struct No {
    int dado;
    No* prox;
    No* ant;
};

struct Head {
    int tamanho;
    No* inicio;
    No* fim;
};

Head * head = new Head;

int main()
{
    int op;
    cout << "0 - termina\n";
    cout << "1 - inclusao no inicio da lista\n";
    cout << "2 - inclusao no fim da lista\n";
    cout << "3 - remoção do inicio da lista\n";
    cout << "4 - remoção do fim da lista\n";
    cout << "5 - Impressão da lista\n";

    head->inicio = NULL;
    head->fim = NULL;
    head->tamanho = 0;
    int t = 1;
    while(t) {
        cout << "\ndigite a opção: ";
        cin >> op;
        switch(op) {
        case 0 :
            t = 0;
            break;
        case 1 :
            incluiIni();
            break;
        case 2 :
            incluiFim();
            break;
        case 3 :
            removeIni();
            break;
        case 4 :
            removeFim();
            break;
        case 5 :
            imprimeLista();
            break;
        default:
            cout << "opção invalida\n";
        }
    }

    return 0;
}

int incluiIni()
{
    int valor;
    cout << "digite valor\n";
    cin >> valor;

    No * no = new No;
    no->dado = valor;

    if (head->tamanho == 0) {
        head->fim = no;
        head->tamanho = 1;
    } else {
        head->tamanho ++;
        no->prox = head->inicio;
        (head->inicio)->ant = no;
    }
    head->inicio = no;
}

int incluiFim()
{
    int valor;
    cout << "digite valor\n";
    cin >> valor;

    No * no = new No;
    no->dado = valor;

    if (head->tamanho == 0) {
        head->inicio = no;
        head->tamanho = 1;
    } else {
        head->tamanho ++;
        no->ant = head->fim;
        (head->fim)->prox = no;
    }
    head->fim = no;
}

int removeIni()
{
    if(head->tamanho > 1) {
        head->inicio = (head->inicio)->prox;
        delete (head->inicio)->ant;
        head->tamanho --;
    } else if(head->tamanho == 1) {
        delete head->inicio;
        head->inicio = NULL;
        head->fim = NULL;
        head->tamanho = 0;
    } else {
        cout << "Lista já está vazia\n";
    }
}

int removeFim()
{
    if(head->tamanho > 1) {
        head->fim = (head->fim)->ant;
        delete (head->fim)->prox;
        head->tamanho --;
    } else if(head->tamanho == 1) {
        delete head->inicio;
        head->inicio = NULL;
        head->fim = NULL;
        head->tamanho = 0;
    } else {
        cout << "Lista já está vazia\n";
    }
}

int imprimeLista()
{
    cout << "\n Header\n";
    cout << "tamanho: " << head->tamanho << "\ninicio: " << head->inicio
         << "\nfim:    " << head->fim;
    cout << "\n Nós\n";
    if(head->tamanho == 0) {
        cout << "\n nao existe nenhum no\n";
    }
    No* posatual = new No;
    posatual = head->inicio;
    while(posatual != head->fim) {
        cout << "\ndado: " << posatual->dado << "\nproximo:  " << posatual->prox
             << "\nanterior: " << posatual->ant;
        posatual = posatual->prox;
    }
    delete posatual;
}


