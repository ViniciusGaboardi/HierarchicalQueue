#ifndef FUNCOESFILA_H_INCLUDED
#define FUNCOESFILA_H_INCLUDED

using namespace std;

template<typename T>
struct Nodo
{
    T elemento;
    int prioridade;
    Nodo<T>* anterior;
    Nodo<T>* proximo;
};

template<typename T>
struct FilaDuplamenteEncadeada
{
    int cardinalidade;
    Nodo<T>* inicio;
    Nodo<T>* fim;
};

template<typename T>
void cria(FilaDuplamenteEncadeada<T> &fila)
{
    fila.cardinalidade = 0;
    fila.inicio = nullptr;
    fila.fim = nullptr;
}

template<typename T>
bool estaVazia(FilaDuplamenteEncadeada<T> fila)
{
    return fila.cardinalidade == 0;
}

template<typename T>
int numeroDeElementos(FilaDuplamenteEncadeada<T> fila)
{
    return fila.cardinalidade;
}

template<typename T>
bool existeElemento(FilaDuplamenteEncadeada<T> &fila, T elemento)
{
    Nodo<T>* node = fila.inicio;

    while(node!=nullptr){
        if(node->elemento == elemento)
            return true;
        node = node->proximo;
    }
    return false;
}

template<typename T>
bool checaPosicao(FilaDuplamenteEncadeada<T> &fila, int posicao)
{
    if(posicao < 1 || posicao > fila.cardinalidade){
        return false;
    }
    return true;
}

template<typename T>
int recuperaPrioridade(FilaDuplamenteEncadeada<T> &fila, T elemento)
{
    Nodo<T>* node = fila.inicio;

    while(node != nullptr){
        if(node->elemento == elemento)
            return node->prioridade; // Retorna a prioridade do elemento encontrado

        node = node->proximo;
    }

    return -1; // Elemento n�o encontrado na fila
}

template<typename T>
T recuperaElemento(FilaDuplamenteEncadeada<T> &fila, int posicao)
{
    if(!checaPosicao(fila, posicao))
        return T();

    Nodo<T>* node = fila.inicio;
    int contador = 1;

    while(node != nullptr && contador < posicao){
        node = node->proximo;
        contador++;
    }

    if(node != nullptr)
        return node->elemento;

    return T(); // Se o n� n�o for encontrado, retorna um valor padr�o.
}

template<typename T>
int recuperaPosicao(FilaDuplamenteEncadeada<T> &fila, T elemento)
{
    Nodo<T>* node = fila.inicio;
    int posicao = 1;

    while(node != nullptr){
        if(node->elemento == elemento)
            return posicao; // Elemento encontrado, retornamos a posi��o
        node = node->proximo;
        posicao++;
    }

    return -1; // Elemento n�o encontrado, retorna -1 para indicar que n�o est� na lista
}

template<typename T>
void insere(FilaDuplamenteEncadeada<T> &fila, T elemento, int prioridade)
{
    Nodo<T>* novoNodo = new Nodo<T>;
    novoNodo->elemento = elemento;
    novoNodo->prioridade = prioridade;
    novoNodo->anterior = fila.fim;
    novoNodo->proximo = nullptr;

    if(fila.fim != nullptr)
        fila.fim->proximo = novoNodo;
    else
        fila.inicio = novoNodo; // Se a lista estava vazia, o novo n� tamb�m ser� o in�cio da lista.

    fila.fim = novoNodo;
    fila.cardinalidade++;
}

template<typename T>
void removePorPrioridade(FilaDuplamenteEncadeada<T> &fila)
{
    if(estaVazia(fila))
        return;

    int prioridadeParaRemover = 3; // Inicialize com a prioridade mais baixa

    Nodo<T>* node = fila.inicio; // Encontre a maior prioridade na fila
    while(node != nullptr){
        if(node->prioridade < prioridadeParaRemover){
            prioridadeParaRemover = node->prioridade;
        }
        node = node->proximo;
    }

    node = fila.inicio;
    Nodo<T>* nodoParaRemover = nullptr;
    while(node != nullptr){ // Remove o primeiro elemento com a maior prioridade encontrada
        if(node->prioridade == prioridadeParaRemover){
            nodoParaRemover = node;
            break;
        }
        node = node->proximo;
    }

    if(nodoParaRemover != nullptr){
        if(nodoParaRemover->anterior != nullptr)
            nodoParaRemover->anterior->proximo = nodoParaRemover->proximo;
        else
            fila.inicio = nodoParaRemover->proximo;

        if(nodoParaRemover->proximo != nullptr)
            nodoParaRemover->proximo->anterior = nodoParaRemover->anterior;
        else
            fila.fim = nodoParaRemover->anterior;

        delete nodoParaRemover;
        fila.cardinalidade--;
    }
}

template<typename T>
void geraLinha(FilaDuplamenteEncadeada<T> fila)
{
    for(int i = 0; i<numeroDeElementos(fila); i++)
        cout<<"========";
    cout<<endl;
}

template<typename T>
void mostraOrdenado(FilaDuplamenteEncadeada<T> fila)
{
    cout<<"Queue filtered by Priority:"<<endl;
    geraLinha(fila);
    for(int prioridade = 1; prioridade <= 3; prioridade++){
        Nodo<T>* p = fila.inicio;
        while(p != nullptr){
            if(p->prioridade == prioridade){
                cout<<"|"<<p->elemento<<" -> "<<p->prioridade;
            }
            p = p->proximo;
        }
    }
    cout<<"|"<<endl;
}

template<typename T>
void mostra(FilaDuplamenteEncadeada<T> fila)
{
    Nodo<T>*p = fila.inicio;
    cout<<"Original Queue:"<<endl;
    geraLinha(fila);
    while(p!=nullptr){
        cout<<"|"<<p->elemento<<" -> "<<p->prioridade;
        p = p->proximo;
    }
    cout<<"|"<<endl;
}

template<typename T>
void destroiFila(FilaDuplamenteEncadeada<T> &fila)
{
    Nodo<T>* node = fila.inicio;
    while(node != nullptr){
        Nodo<T>* temp = node;
        node = node->proximo;
        delete temp;
    }

    fila.inicio = nullptr;
    fila.fim = nullptr;
    fila.cardinalidade = 0;
}

#endif // FUNCOESFILA_H_INCLUDED
