#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA

struct No
{
    int dado;
    No *prox;
    No *ant;

    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
    }
};

struct Lista
{
    No *inicio;
    No *fim;
    int tamanho;

    Lista() // construtor
    {
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};

void destroiL(Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;

    cout << "L[" << lista->tamanho << "]:{";

    while(n)
    {
        cout << n->dado;
        n = n->prox;
        if(n)
            cout << ", ";
    }

    cout << "}\n";

}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}


bool insereInicioL(Lista *lista, int valor)
{

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; //Se o novo nó será adicionado no início da lista, o ponteiro *ant do primeiro nó sempre é nulo
    novo->prox = lista->inicio;

    if (!lista->fim)
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}

bool insereFinalL(Lista *lista, int valor){

    No *novo = new No();

    novo->dado = valor; // coloca o valor no novo no
    novo->prox = NULL; // sempre será NULO

    if(vaziaL(lista)){
        lista->inicio = novo; //
        novo->ant = NULL; // se for único, o anterior é nulo
    }

    else{
        novo->ant = lista->fim;
        lista->fim->prox = novo;
    }


    lista->fim = novo;
    lista->tamanho++;

    return true;

}

No* buscaL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}

bool removerNoL(Lista *lista, No *no)
{
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) // se anterior é igual a NULL, o elemento a ser excluído está no início da lista
    {
        lista->inicio = no->prox;
        if (!lista->inicio) // lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    }else{ // elemento está no meio ou no fim

        no->ant->prox = no->prox;
        if (!no->prox) // se for retirado último da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;

    }

    lista->tamanho--;
    delete(no);
    return true;
}

bool removeL(Lista *lista, int valor)
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}


int removeInicioL(Lista *lista){

    int removido = 0;

    if(lista->inicio != NULL){

        No *deletado = lista->inicio;
        removido = deletado->dado;
        lista->inicio = lista->inicio->prox;
        lista->tamanho--;

        if(lista->inicio == NULL)
            lista->fim = NULL;

        delete deletado;

    }

    return removido;

}

int removeFimL(Lista *lista){

    int removido = 0;

    if(lista->inicio != NULL){

        No *inicio = lista->inicio;
        No *deletado = lista->fim;
        removido = deletado->dado;

        if(inicio->prox == NULL){
            lista->inicio->prox = NULL;
            lista->inicio = NULL;
            lista->fim = NULL;
        }

        else{
            lista->fim = lista->fim->ant;
            lista->fim->prox = NULL;
        }

        lista->tamanho--;

        delete deletado;

    }

    return removido;


}

void removeTodos(Lista *L, int valor){

    while(buscaL(L, valor)){
        removeL(L, valor);
    }

}

int achaMenor(Lista *lista){

    int menor = lista->inicio->dado;
    No *percorre = lista->inicio;

    while(percorre){

        if(menor > percorre->dado)
            menor = percorre->dado;

        percorre = percorre->prox;
    }

    return menor;

}

Lista leMaiores(Lista *L, int K){

    Lista copia = Lista();
    Lista gerada = Lista();

    No *percorre = L->inicio;

    while(true){

        insereInicioL(&copia, percorre->dado);
        percorre = percorre->prox;

        if(percorre == NULL)
            break;

     }

    mostraL(&copia);

    No *percorreCopia = copia.inicio;
    int menor = L->inicio->dado;

    while(true){
        insereFinalL(&gerada, achaMenor(&copia));
        removeL(&copia, achaMenor(&copia));

        if(vaziaL(&copia))
            break;

    }

    cout << "\n\nK: " << K;
    cout << "\n\nTAM: " << L->tamanho;

    if(K < L->tamanho){

        K = L->tamanho - K;

        while(K != 0){
            removeFimL(&gerada);
            K--;
        }
    }


    return gerada;
}


#endif // _HPP_LISTA_DUPLA




