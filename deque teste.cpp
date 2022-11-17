#include <iostream>
#include <cstdio>
using namespace std;

class DequeInt
{
public:

struct Noh { int elem; Noh *ant, *prox; };
Noh *esq, *dir;

DequeInt () { esq = dir = nullptr; }

    void inserir_esq (int e){
        Noh* n = new Noh;
        
        if(esq == nullptr){
            esq = dir = n;
            n-> ant = n-> prox = nullptr;
            n-> elem = e;
        }

        else{
            esq->ant = n;
            n->prox = esq;
            esq = n;
            n->ant = nullptr;
            n->elem = e;
        }
    }

    void inserir_dir (int d){
        Noh* n = new Noh;
        
        if(dir == nullptr){
            dir = esq = n;
            n-> ant = n-> prox = nullptr;
            n-> elem = d;
        }
        
        else{
            dir->prox = n;
            n->ant = dir;
            dir = n;
            n->prox = nullptr;
            n-> elem = d;
        }
    }

    void remover_esq (){
        Noh* n = new Noh;
        if(esq != nullptr){
            if(esq->prox == nullptr){
                dir = nullptr;
                esq = nullptr;
            }
            else{
                n = esq;
                esq = esq->prox;
                delete n;
            }
        }
    }

    void remover_dir(){
        Noh *n = new Noh;
        if(dir != nullptr){
            if(dir->ant == nullptr){
                esq = nullptr;
                dir = nullptr;
            }
            else{
                n = dir;
                dir = dir -> ant;
                delete n;
            }
        }
    }

    int consultar_esq(){
        if(esq == nullptr && dir == nullptr){
            cout<< "deque vazio";
        }
        cout<< "elemento mais a esquerda\n";
        cout<< esq->elem;
        cout<< endl;
    }

    int consultar_dir(){  
        if(dir == nullptr && esq == nullptr){
            cout<<"deque vazio";
        }
        cout<< "Elemento mais a direita\n";
        cout<< dir -> elem;
        cout<< endl;
    }

    int busca(int p){
        Noh* n = esq;
        Noh* m = dir;
        if(dir == nullptr && esq == nullptr){
            cout << "deque vazio";
        }
        else{
            while(m != nullptr && n != nullptr){
                if(m -> elem == p){
                    return 1;
                }
                else if(m -> elem != p){
                    m = m->ant;
                }
                if(n -> elem == p){
                    return 1;
                }
                else if(n -> elem != p){
                    n = n->prox;
                }
            }
        }
        return 0;
    }

    void printar_esq(){
        Noh* n = esq;
        while(n != nullptr){
            cout<<n->elem;
            cout<< endl;
            n = n->prox;
        }
    }
    void printar_dir(){
        Noh* n = dir;
        while(n != nullptr){
            cout<<n->elem;
            cout<< endl;
            n = n->ant;
        }
    }
};
    

int main (){
    DequeInt a;
    int e;//operador coringa
    int b;//insere esq
    int c;//insere dir
    int d;//busca
    while(e != 0){
        cout<< "digite 1 para inserir a esquerda, digite 2 para inserir a direita, digite 3 para remover a esquerda, digite 4 para remover a direita\n";
        cout<< "digite 5 para consultar a esquerda, digite 6 para consultar a direita, digite 7 para saber se um valor esta no deque\n";
        cout<< "digite 8 para printar o deque a partir da esquerda, digite 9 para printar o deque a partir da direita, 0 acaba\n";
        cin>> e;
        if(e == 1){
            cout<< "qual valor voce quer inserir a esquerda?\n";
            cin>> b;
            a.inserir_esq(b);
        }
        if(e == 2){
            cout<< "qual valor voce quer inserir a direita?\n";
            cin>> c;
            a.inserir_dir(c);
        }
        if(e == 3){
            a.remover_esq();
        }
        if(e == 4){
            a.remover_dir();
        }
        if(e == 5){
            a.consultar_esq();
        }
        if(e == 6){
            a.consultar_dir();
        }
        if(e == 7){
            cout<<"qual valor voce quer saber se estar no deque\n";
            cin>> d;
            if(a.busca(d) != 0){
                cout<< "o valor esta na deque\n";
            }
            else{
                cout<< "o valor nao esta no deque\n";
            }
        }
        if(e == 8){
            a.printar_esq();
        }
        if(e == 9){
            a.printar_dir();
        }
        if( e == 0){
            break;
        }
    }
}