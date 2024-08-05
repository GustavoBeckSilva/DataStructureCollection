#ifndef _HPP_LISTA_DINAMICA
#define _HPP_LISTA_DINAMICA

struct No
{
    int dado;
    struct No *prox;
};

void inicializaL(No **lista) ///
{
    *lista = NULL;
}

bool vaziaL(No **lista) ///
{
    if((*lista) == NULL )
        return true;
    else
        return false;
}

void destroiL(No **lista) ///
{
    No *n = *lista;

    while (n != NULL)
    {
        No *aux  = n;
        n = n->prox;
        delete aux;
    }

    *lista = NULL;
}

void mostraL(No **lista) ///
{
    No *n = *lista; // recebe o endereço do primeiro elemento da lista

    cout << "L:{";

    while(n != NULL ) // enquanto houverem elementos na lista
    {
        cout << n->dado; // mostra o dado da lista
        n = n->prox;  // avança o ponteiro

        if(n != NULL) // se não for nulo, terá um próximo
            cout << ", ";
    }

    cout << "}\n";

}

bool insereInicioL(No **lista, int valor) ///
{

    No *novo = new No(); // cria nó que será adicionado a lista

    if (novo == NULL) // verefica se a criação ocorreu bem
        return false;

    novo->dado = valor; // insere o valor informado no nó
    novo->prox = *lista; // o ponteiro do novo nó aponta para o início da lista
    *lista = novo;          // adiciona o novo nó no inicio da lista

    return true;
}

bool insereFimL(No **lista, int valor) ///
{

    No *novo = new No(); // cria o nó que será inserido no fim da fila

    if(novo == NULL) // verefica se tudo ocorreu bem na criação do nó
        return false;

    novo->dado = valor; // o nó recebe o valor inserido
    novo->prox = NULL; // o nó aponta para NULL, porque será o último da fila

    if(*lista == NULL) // verefica se ele será o primeiro a ser inserido
        *lista = novo; // se ele for o primeiro, será o primeiro elemento da lista, então o início da lista aponta para ele

    else  // caso não for o primeiro
    {

        No *posicao = *lista; // cria-se um ponteiro auxiliar que vai percorrer a lista

        while(posicao->prox != NULL) // enquanto o ponteiro não chegar no último nó, ele continua
            posicao = posicao->prox;

        posicao->prox = novo; // ao chegar no último nó, o próximo elemento dele será o nó criado
    }

    return true;

}

void inserirCrescente(No **lista, int valor){ ///

   No *novo = new No(); // cria novo nó
   novo->dado = valor;  // com o valor informado

    if(*lista == NULL){ // se a lista está vazia
        *lista = novo;       // insere o novo elemento no início dela
        novo->prox = NULL;  // consequentemente, será o último
    }

    else{

        No *posicao = *lista, *posicaoAnterior = *lista; // cria ponteiro para percorrer lista e para guardar ultima posicao
        int maior = 0, menor = (*lista)->dado;  // cria maior e menor

        while(posicao != NULL){ // enquanto a lista nao acabar

            if(posicao->dado > maior) // verefica se o elemento é o maior
                maior = posicao->dado;

            if(posicao->dado < menor) // verefica se o elemento é o menor
                menor = posicao->dado;

            posicaoAnterior = posicao; // salva a posição
            posicao = posicao->prox; // avança o vetor

        }

        if(valor >= maior){ // verefica se é o último
            novo->prox = NULL;  // próximo elemento é nulo
            posicaoAnterior->prox = novo; // o antigo último elemento recebe o novo nó
        }

        else if(valor <= menor){ // verefica se é o primeiro
            novo->prox = *lista; // o início da lista será seu próximo
            *lista = novo;       // insere o novo elemento no início dela
        }

        else{ // verefica se está no meio

            posicao = *lista; // seta o ponteiro para o início da lista

            while(posicao != NULL){ // percorre a lista

                if(posicao->prox->dado > valor){ // se o próximo valor for maior que o informado
                    novo->prox = posicao->prox; // o próximo do novo será o próximo do atual
                    posicao->prox = novo; // o proximo do atual será o novo
                    break;
                }

                posicao = posicao->prox; // avança na lista
            }
        }

    }

}

void inserirDecrescente(No **lista, int valor){ ///

   No *novo = new No(); // cria novo nó
   novo->dado = valor;  // com o valor informado

    if(*lista == NULL){ // se a lista está vazia
        *lista = novo;       // insere o novo elemento no início dela
        novo->prox = NULL;  // consequentemente, será o último
    }

    else{

        No *posicao = *lista, *posicaoAnterior = *lista; // cria ponteiro para percorrer lista e para guardar ultima posicao
        int maior = 0, menor = (*lista)->dado;  // cria maior e menor

        while(posicao != NULL){ // enquanto a lista nao acabar

            if(posicao->dado > maior) // verefica se o elemento é o maior
                maior = posicao->dado;

            if(posicao->dado < menor) // verefica se o elemento é o menor
                menor = posicao->dado;

            posicaoAnterior = posicao; // salva a posição
            posicao = posicao->prox; // avança o vetor

        }

        if(valor >= maior){ // verefica se é o último
            novo->prox = *lista; // o início da lista será seu próximo
            *lista = novo;       // insere o novo elemento no início dela
        }

        else if(valor <= menor){ // verefica se é o primeiro
            novo->prox = NULL;  // próximo elemento é nulo
            posicaoAnterior->prox = novo; // o antigo último elemento recebe o novo nó
        }

        else{ // verefica se está no meio

            posicao = *lista; // seta o ponteiro para o início da lista

            while(posicao != NULL){ // percorre a lista

                if(posicao->prox->dado < valor){ // se o próximo valor for maior que o informado
                    novo->prox = posicao->prox; // o próximo do novo será o próximo do atual
                    posicao->prox = novo; // o proximo do atual será o novo
                    break;
                }

                posicao = posicao->prox; // avança na lista
            }
        }

    }

}

int achaMaior(No **lista){

    No *posicao = *lista; // cria ponteiro para percorrer lista

    int maior = 0;// cria maior

        while(posicao != NULL){ // enquanto a lista nao acabar

            if(posicao->dado > maior) // verefica se o elemento é o maior
                maior = posicao->dado;

            posicao = posicao->prox; // avança o vetor

        }

    return maior;

}

int achaMenor(No **lista){

    No *posicao = *lista; // cria ponteiro para percorrer lista

        int menor = (*lista)->dado;  // cria menor

        while(posicao != NULL){ // enquanto a lista nao acabar

            if(posicao->dado < menor) // verefica se o elemento é o menor
                menor = posicao->dado;

            posicao = posicao->prox; // avança o vetor

        }

        return menor;

}

bool insereDepoisElementoL(No **lista, int valor, int elementoAnterior) ///
{

    if(*lista != NULL) // caso a lista não estiver vazia
    {
        No *novo = new No(); // cria novo nó

        if(novo == NULL) // verefica se criação ocorreu normalmente
            return false;

        No *posicao = *lista; // ponteiro auxiliar aponta para o inicio da lista
        novo->dado = valor; // dado informado é inserido no novo nó

        while(posicao->dado != elementoAnterior) // enquanto o elemento anterior ao que será inserido não for achado
        {

            if(posicao->dado == elementoAnterior) // se for achado, o ponteiro estará apontando para ele
                break;

            if(posicao->prox == NULL && posicao->dado != valor) // se for o ultimo elemento e não foi achado, elemento nao está na lista
                return false;

            posicao = posicao->prox; // avança o ponteiro

        }

        // caso elemento estiver na fila, o ponteiro já está setado

        if(posicao->prox != NULL) // se o elemmento estiver no meio
            novo->prox = posicao->prox; // o próximo elemento do novo nó será o antigo proximo elemento do nó anterior

        else // se o elemento for o último
            novo->prox == NULL; // o novo nó apontara para o fim, já que será o último

        posicao->prox = novo; // atualiza o ponteiro da posição anterior, apontando para o novo nó, o incluindo na lista

    }

    else
        return false; // se a lista estiver vazia, não há como inserir depois de algum elemento

    return true;

}

bool insereAntesElementoL(No **lista, int valor, int elementoPosterior) ///
{

    if(*lista != NULL) // caso a lista não estiver vazia
    {
        No *novo = new No(); // cria novo nó

        if(novo == NULL) // verefica se criação ocorreu normalmente
            return false;

        No *posicao = *lista, *posicaoAnterior = *lista; // ponteiro auxiliar e o guarda posição apontam para o inicio da lista
        novo->dado = valor; // dado informado é inserido no novo nó

        if(posicao->prox == NULL && posicao->dado == elementoPosterior)  // se haver apenas elemento único e ele existir
            *lista = novo; // nó vai para o início da lista

        else if(posicao->prox == NULL && posicao->dado != elementoPosterior) // se haver apenas um elemento e ele não for o desejado
            return false;

        else
        {
            while(posicao->dado != elementoPosterior) // enquanto o elemento posterior ao que será inserido não for achado
            {

                if(posicao->dado == elementoPosterior) // se for achado, o ponteiro estará apontando para ele
                    break;

                if(posicao->prox == NULL && posicao->dado != elementoPosterior) // se for o ultimo elemento e não foi achado, elemento nao está na lista
                    return false;

                posicaoAnterior = posicao; // guarda a posição anterior
                posicao = posicao->prox; // avança o ponteiro

            }

            posicaoAnterior->prox = novo; // caso estiver no meio, a posição anterior aponta para o novo nó

        }

        novo->prox = posicao; // o novo nó aponta para a posição posterior, que serviu de parametro


    }

    else
        return false; // se a lista estiver vazia, não há como inserir depois de algum elemento

    return true;


}

int leInicioL(No **lista) ///
{
    int dado = 0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado, tem essa sintaxe por ser um ponteiro duplo (*(*lista)).dado

    return dado;
}

int leFinalL(No **lista) ///
{

    No *aux = *lista;

    if(vaziaL(lista) == false){

        while(aux->prox != NULL) // vai até o elemento final da lista
            aux = aux->prox;

        return aux->dado; // retorna o dado do elemento final
    }

    return 0; // se estiver vazia, retorna 0

}

int removeInicioL(No **lista)
{
    No* aux;
    int dado = 0;

    if(vaziaL(lista) == false) // faz a operação apenas se a lista estiver com pelo menos um elemento
    {
        dado = (*lista)->dado; //atribui o dado do início da lista para a variável dado
        aux = *lista; //pega a endereço do primeiro nó, o qual será removido

        *lista = (*lista)->prox; //inicio da lista vai ser tornar o posterior ao primeiro

        delete aux; // deleta o endereço antigo
    }

    return dado;
}

int removeFinalL(No **lista){ ///

    if(vaziaL(lista)) // caso lista estiver vazia, não remove nada
        return 0;

    No *posicao = *lista; // ponteiro na posição inicial da lista
    int retorno; // variavel de retorno

    if(posicao->prox == NULL){ // caso a lista ter um unico elemento
        retorno = posicao->dado; // armazena-o no retorno
        *lista = NULL; // e limpa a lista
    }

    else{ // caso ter mais de um elemento

        No *posicaoAnterior = *lista; // reserva um ponteiro para a posição anterior

        while(posicao->prox != NULL){ // enquanto não chegar no fim
            posicaoAnterior = posicao; // guarda a posição anterior
            posicao = posicao->prox; // avança o ponteiro
        }

        retorno = posicao->dado; // armazana o retorno
        posicaoAnterior->prox = NULL; // aponta o elemento anterior para NULL
        delete posicao; // deleta a ultima posição

    }

    return retorno; // retorna o valor deletado
}

bool removeElementoL(No **lista, int valor) ///
{
    No *anterior = NULL; // reserva ponteiro de posição anterior
    No *atual = *lista; // ponteiro da ultima posicao

    while(atual != NULL && atual->dado != valor) // enquanto nao estiver no ultimo elemento da lista e não achar o elemento
    {
        anterior = atual; // salva a posicao anterior
        atual = atual->prox; // avança o ponteiro
    }

    if(atual == NULL) // se o atual for nulo, o elemento nao foi localizado
        return false;

    if (anterior == NULL) // se o anterior for nulo, elemento está no inicio da fila
        *lista = atual->prox; // inicio da lista recebera o segundo elemento, podendo ser outro ou ser nulo

    else   // elemento está no meio ou final da lista
        anterior->prox = atual->prox; // elemento anterior recebe outro elemento ou null, se estiver no fim da fila

    delete(atual); // deleta o no salvo na ultima posicao

    return true;

}

No* buscaL(No **lista, int valor) ///
{

    No *n = *lista; // ponteiro que percorre toda a lista

    while (n != NULL) // enquanto não ter lido todos elementos
    {
        if (n->dado == valor) // testa se o valor foi encontrado
            return n;

        n = n->prox; // avança o ponteiro
    }

    return NULL;
}

#endif









