#ifndef _HPP_LISTA_DESCRITOR
#define _HPP_LISTA_DESCRITOR

struct No
{
    int dado;
    struct No *prox;

    No() // construtor
    {
        prox = nullptr;
    }
};

struct Lista
{
    No *inicio; // ponteiro do in�cio da lista
    No *fim; // ponteiro do final da lista
    int tamanho; // tamanho da lista

    Lista() // construtor
    {
        inicio = nullptr; // ao ser iniciada, o in�cio � nulo
        fim = nullptr; // o final � nulo
        tamanho = 0;  // e o tamanho � 0
    }
};

void mostraL(Lista *lista) ///
{
    No *n = lista->inicio;

    cout << "L:{";

    while(n != NULL ) // enquanto n n�o for NULL fica no la�o
    {
        cout << n->dado;
        n = n->prox;

        if(n != NULL)
            cout << ", ";
    }

    cout << "}\n";
}

void destroiL(Lista *lista) ///
{
    No *n = lista->inicio;

    while(n != nullptr)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

bool vaziaL(Lista *lista) ///
{
    if(lista->inicio == NULL )
        return true;
    else
        return false;
}

bool insereInicioL(Lista *lista, int valor) ///
{

    No *novo = new No();

    if (novo == nullptr) // verefica a aloca��o de mem�ria
        return false;

    novo->dado = valor; // novo n� recebe o valor informado
    novo->prox = lista->inicio; // o pr�ximo elemento do novo n� ser� o in�cio da fila
    lista->inicio = novo; // o in�cio da lista receber� o novo n�
    lista->tamanho++; // o tamanho aumentar�

    if (!lista->fim) // se o ponteiro final por nulo, quer dizer que o novo n� ser� o in�cio e o fim da lista
        lista->fim = lista->inicio; // o final da lista receber� o in�cio

    return true;
}

bool insereFimL(Lista *lista, int valor) ///
{

    No *novo = new No(); // cria novo n�

    if (novo == nullptr) // verefica a aloca��o de mem�ria
        return false;

    novo->dado = valor; // novo n� recebe o valor informado
    novo->prox = NULL; // o sucessor do n� ser� nulo, j� que ser� o �ltimo

    if(vaziaL(lista)) // se a lista estiver vazia
    {
        lista->inicio = novo; // o in�cio da lista receber� o n� tamb�m
        lista->fim = novo; // e o ponteiro n� ser� adicionado ao final
    }
    else
    {
        lista->fim->prox = novo; // o pr�ximo elemento no final da lista ser� o novo n�
        lista->fim = novo; // e o novo n� final ser� o "novo"
    }

    lista->tamanho++; // incrementa a lista

    return true;
}

bool insereDepoisElementoL(Lista *lista, int valor, int elementoAnterior) { ///

    if(lista == NULL || lista->inicio == NULL) // verifica��o inicial
        return false;

    No *novo = new No();

    if(novo == NULL) // verifica��o de aloca��o de mem�ria
        return false;

    No *posicao = lista->inicio;
    novo->dado = valor;

    while(posicao != NULL && posicao->dado != elementoAnterior) // encontrar o elemento anterior
        posicao = posicao->prox;


    if(posicao == NULL)  // se n�o encontrou o elemento anterior, retorna falso
        return false;

    novo->prox = posicao->prox; // inserir o novo n� ap�s o elemento anterior
    posicao->prox = novo;

    if(novo->prox == NULL) // se o novo n� foi inserido no final da lista, atualiza o ponteiro `fim`
        lista->fim = novo;

    lista->tamanho++; // incrementa o tamanho da lista

    return true;
}

bool insereAntesElementoL(Lista *lista, int valor, int elementoPosterior){ ///

    if(lista == NULL || lista->inicio == NULL) // verifica��o inicial
        return false;

    No *novo = new No();

    if(novo == NULL) // verifica��o de aloca��o de mem�ria
        return false;

    No *posicao = lista->inicio, *posicaoAnterior = NULL;
    novo->dado = valor;

    while(posicao != NULL && posicao->dado != elementoPosterior){ // encontrar o elemento posterior
        posicaoAnterior = posicao;
        posicao = posicao->prox;
    }

    if(posicao == NULL)  // se n�o encontrou o elemento posterior, retorna falso
        return false;

    novo->prox = posicao;

    if(!posicaoAnterior)
        lista->inicio = novo;

    else
        posicaoAnterior->prox = novo;

    lista->tamanho++; // incrementa o tamanho da lista

    return true;

}

int achaMaior(Lista *lista){ ///

    No *posicao = lista->inicio; // posi��o recebe o inicio da lista
    int maior = 0; // inicializa o maior

    while(posicao){ // enquanto houver posi��es na lista

        if(posicao->dado > maior) // verefica qual o maior valor
            maior = posicao->dado;

        posicao = posicao->prox; // avan�a na lista

    }

    return maior; // retorna o maior

}

int achaMenor(Lista *lista){ ///

    No *posicao = lista->inicio; // coloca o ponteiro no inicio da lista
    int menor = lista->inicio->dado; // inicializa a lista com o primeiro valor

    while(posicao){ // enquanto houver posi��es

        if(posicao->dado < menor) // verefica se o elemento � o menor
            menor = posicao->dado;

        posicao = posicao->prox; // percorre a lista

    }

    return menor;

}

bool inserirCrescente(Lista *lista, int valor) { ///

    No *novo = new No(); // cria novo n�

    if(!novo)
        return false;

    novo->dado = valor; // atribui valor a ele

    if(vaziaL(lista)) // se estiver vazia
        insereInicioL(lista, valor); // insere normalmente o elemento

    else {
        int maior = achaMaior(lista);
        int menor = achaMenor(lista);

        if(valor <= menor) // se for menor, insere no inicio
            insereInicioL(lista, valor);

        else if(valor >= maior) // se for maior, insere no final
            insereFimL(lista, valor);

        else { // caso contr�rio, inser��o � no meio

            No *posicao = lista->inicio;

            while(posicao->prox != NULL && posicao->prox->dado < valor) // verefica se o pr�ximo valor � menor, se for, insere
                posicao = posicao->prox;

            novo->prox = posicao->prox; // recebe o endere�o do pr�ximo
            posicao->prox = novo; //

            if(novo->prox == NULL)
                lista->fim = novo;

        }
    }

    lista->tamanho++;

    return true;
}

bool inserirDecrescente(Lista *lista, int valor){

    No *novo = new No();

    if(!novo)
        return false;

    novo->dado = valor;

    if(vaziaL(lista))
        insereInicioL(lista, valor);

    else {
        int maior = achaMaior(lista);
        int menor = achaMenor(lista);

        if(valor <= menor)
            insereFimL(lista, valor);

        else if(valor >= maior)
            insereInicioL(lista, valor);

        else {

            No *posicao = lista->inicio;

            while(posicao->prox != NULL && posicao->prox->dado > valor)
                posicao = posicao->prox;

            novo->prox = posicao->prox;
            posicao->prox = novo;

            if(novo->prox == NULL)
                lista->fim = novo;

        }
    }

    lista->tamanho++;

    return true;

}

bool removeElementoL(Lista *lista, int valor) ///
{
    No *anterior = nullptr;
    No *atual = lista->inicio;

    while(atual && atual->dado != valor) // percorre at� atual ser nulo ou achar o valor procurado
    {
        anterior = atual; // salva a posi��o anterior
        atual = atual->prox; // percorre a lista
    }

    if(!atual) // se atual for nulo, a lista � vazia
        return false;

    if (!anterior) // se anterior for nulo, o n� a ser removido � o primeiro
    {
        lista->inicio = atual->prox; // o in�cio da lista ser� atualizado, sendo o subsequente do atual (nulo)

        if (!lista->inicio) // se o inicio for nulo, a lista ficou vazia
            lista->fim = lista->inicio; // atualiza o final para ser nulo tamb�m
    }
    else // se for removido um elemento do meio
    {
        anterior->prox = atual->prox; // o n� anterior vai se ligar ao pr�ximo do que ser� deletado
        if (!atual->prox) // se o proximo do atual for nulo
            lista->fim = anterior; // o final ser� o anterior
    }

    lista->tamanho--;

    delete(atual);
    return true;

}

int removeInicioL(Lista *lista){ ///

    int dadoRemovido = 0;

    if(lista){

        dadoRemovido = lista->inicio->dado;

        No *deletado = lista->inicio;

        lista->inicio = deletado->prox;

        if(!lista->inicio)
            lista->fim == NULL;

        lista->tamanho--;


        delete (deletado);

    }

    return dadoRemovido;

}

int removeFinalL(Lista *lista){ ///

    int dadoRemovido = 0;

    if(lista){

        No *posicao = lista->inicio;
        No *deletado = lista->fim;
        dadoRemovido = lista->fim->dado;

        if(posicao->prox == NULL){
            deletado = NULL;
            lista->fim = deletado;
            lista->inicio = deletado;
        }

        else{

            No *posicaoAnterior = NULL;

            while(posicao->prox != NULL){
                posicaoAnterior = posicao;
                posicao = posicao->prox;
            }

            posicaoAnterior->prox = NULL;
            lista->fim = posicao;

        }

        lista->tamanho--;
        delete (deletado);

    }

    return dadoRemovido;

}

No* buscaL(Lista *lista, int valor) ///
{
    No *n = lista->inicio;

    while(n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}


#endif // _HPP_LISTA_DESCRITOR



