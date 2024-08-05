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
    No *n = *lista; // recebe o endere�o do primeiro elemento da lista

    cout << "L:{";

    while(n != NULL ) // enquanto houverem elementos na lista
    {
        cout << n->dado; // mostra o dado da lista
        n = n->prox;  // avan�a o ponteiro

        if(n != NULL) // se n�o for nulo, ter� um pr�ximo
            cout << ", ";
    }

    cout << "}\n";

}

bool insereInicioL(No **lista, int valor) ///
{

    No *novo = new No(); // cria n� que ser� adicionado a lista

    if (novo == NULL) // verefica se a cria��o ocorreu bem
        return false;

    novo->dado = valor; // insere o valor informado no n�
    novo->prox = *lista; // o ponteiro do novo n� aponta para o in�cio da lista
    *lista = novo;          // adiciona o novo n� no inicio da lista

    return true;
}

bool insereFimL(No **lista, int valor) ///
{

    No *novo = new No(); // cria o n� que ser� inserido no fim da fila

    if(novo == NULL) // verefica se tudo ocorreu bem na cria��o do n�
        return false;

    novo->dado = valor; // o n� recebe o valor inserido
    novo->prox = NULL; // o n� aponta para NULL, porque ser� o �ltimo da fila

    if(*lista == NULL) // verefica se ele ser� o primeiro a ser inserido
        *lista = novo; // se ele for o primeiro, ser� o primeiro elemento da lista, ent�o o in�cio da lista aponta para ele

    else  // caso n�o for o primeiro
    {

        No *posicao = *lista; // cria-se um ponteiro auxiliar que vai percorrer a lista

        while(posicao->prox != NULL) // enquanto o ponteiro n�o chegar no �ltimo n�, ele continua
            posicao = posicao->prox;

        posicao->prox = novo; // ao chegar no �ltimo n�, o pr�ximo elemento dele ser� o n� criado
    }

    return true;

}

void inserirCrescente(No **lista, int valor){ ///

   No *novo = new No(); // cria novo n�
   novo->dado = valor;  // com o valor informado

    if(*lista == NULL){ // se a lista est� vazia
        *lista = novo;       // insere o novo elemento no in�cio dela
        novo->prox = NULL;  // consequentemente, ser� o �ltimo
    }

    else{

        No *posicao = *lista, *posicaoAnterior = *lista; // cria ponteiro para percorrer lista e para guardar ultima posicao
        int maior = 0, menor = (*lista)->dado;  // cria maior e menor

        while(posicao != NULL){ // enquanto a lista nao acabar

            if(posicao->dado > maior) // verefica se o elemento � o maior
                maior = posicao->dado;

            if(posicao->dado < menor) // verefica se o elemento � o menor
                menor = posicao->dado;

            posicaoAnterior = posicao; // salva a posi��o
            posicao = posicao->prox; // avan�a o vetor

        }

        if(valor >= maior){ // verefica se � o �ltimo
            novo->prox = NULL;  // pr�ximo elemento � nulo
            posicaoAnterior->prox = novo; // o antigo �ltimo elemento recebe o novo n�
        }

        else if(valor <= menor){ // verefica se � o primeiro
            novo->prox = *lista; // o in�cio da lista ser� seu pr�ximo
            *lista = novo;       // insere o novo elemento no in�cio dela
        }

        else{ // verefica se est� no meio

            posicao = *lista; // seta o ponteiro para o in�cio da lista

            while(posicao != NULL){ // percorre a lista

                if(posicao->prox->dado > valor){ // se o pr�ximo valor for maior que o informado
                    novo->prox = posicao->prox; // o pr�ximo do novo ser� o pr�ximo do atual
                    posicao->prox = novo; // o proximo do atual ser� o novo
                    break;
                }

                posicao = posicao->prox; // avan�a na lista
            }
        }

    }

}

void inserirDecrescente(No **lista, int valor){ ///

   No *novo = new No(); // cria novo n�
   novo->dado = valor;  // com o valor informado

    if(*lista == NULL){ // se a lista est� vazia
        *lista = novo;       // insere o novo elemento no in�cio dela
        novo->prox = NULL;  // consequentemente, ser� o �ltimo
    }

    else{

        No *posicao = *lista, *posicaoAnterior = *lista; // cria ponteiro para percorrer lista e para guardar ultima posicao
        int maior = 0, menor = (*lista)->dado;  // cria maior e menor

        while(posicao != NULL){ // enquanto a lista nao acabar

            if(posicao->dado > maior) // verefica se o elemento � o maior
                maior = posicao->dado;

            if(posicao->dado < menor) // verefica se o elemento � o menor
                menor = posicao->dado;

            posicaoAnterior = posicao; // salva a posi��o
            posicao = posicao->prox; // avan�a o vetor

        }

        if(valor >= maior){ // verefica se � o �ltimo
            novo->prox = *lista; // o in�cio da lista ser� seu pr�ximo
            *lista = novo;       // insere o novo elemento no in�cio dela
        }

        else if(valor <= menor){ // verefica se � o primeiro
            novo->prox = NULL;  // pr�ximo elemento � nulo
            posicaoAnterior->prox = novo; // o antigo �ltimo elemento recebe o novo n�
        }

        else{ // verefica se est� no meio

            posicao = *lista; // seta o ponteiro para o in�cio da lista

            while(posicao != NULL){ // percorre a lista

                if(posicao->prox->dado < valor){ // se o pr�ximo valor for maior que o informado
                    novo->prox = posicao->prox; // o pr�ximo do novo ser� o pr�ximo do atual
                    posicao->prox = novo; // o proximo do atual ser� o novo
                    break;
                }

                posicao = posicao->prox; // avan�a na lista
            }
        }

    }

}

int achaMaior(No **lista){

    No *posicao = *lista; // cria ponteiro para percorrer lista

    int maior = 0;// cria maior

        while(posicao != NULL){ // enquanto a lista nao acabar

            if(posicao->dado > maior) // verefica se o elemento � o maior
                maior = posicao->dado;

            posicao = posicao->prox; // avan�a o vetor

        }

    return maior;

}

int achaMenor(No **lista){

    No *posicao = *lista; // cria ponteiro para percorrer lista

        int menor = (*lista)->dado;  // cria menor

        while(posicao != NULL){ // enquanto a lista nao acabar

            if(posicao->dado < menor) // verefica se o elemento � o menor
                menor = posicao->dado;

            posicao = posicao->prox; // avan�a o vetor

        }

        return menor;

}

bool insereDepoisElementoL(No **lista, int valor, int elementoAnterior) ///
{

    if(*lista != NULL) // caso a lista n�o estiver vazia
    {
        No *novo = new No(); // cria novo n�

        if(novo == NULL) // verefica se cria��o ocorreu normalmente
            return false;

        No *posicao = *lista; // ponteiro auxiliar aponta para o inicio da lista
        novo->dado = valor; // dado informado � inserido no novo n�

        while(posicao->dado != elementoAnterior) // enquanto o elemento anterior ao que ser� inserido n�o for achado
        {

            if(posicao->dado == elementoAnterior) // se for achado, o ponteiro estar� apontando para ele
                break;

            if(posicao->prox == NULL && posicao->dado != valor) // se for o ultimo elemento e n�o foi achado, elemento nao est� na lista
                return false;

            posicao = posicao->prox; // avan�a o ponteiro

        }

        // caso elemento estiver na fila, o ponteiro j� est� setado

        if(posicao->prox != NULL) // se o elemmento estiver no meio
            novo->prox = posicao->prox; // o pr�ximo elemento do novo n� ser� o antigo proximo elemento do n� anterior

        else // se o elemento for o �ltimo
            novo->prox == NULL; // o novo n� apontara para o fim, j� que ser� o �ltimo

        posicao->prox = novo; // atualiza o ponteiro da posi��o anterior, apontando para o novo n�, o incluindo na lista

    }

    else
        return false; // se a lista estiver vazia, n�o h� como inserir depois de algum elemento

    return true;

}

bool insereAntesElementoL(No **lista, int valor, int elementoPosterior) ///
{

    if(*lista != NULL) // caso a lista n�o estiver vazia
    {
        No *novo = new No(); // cria novo n�

        if(novo == NULL) // verefica se cria��o ocorreu normalmente
            return false;

        No *posicao = *lista, *posicaoAnterior = *lista; // ponteiro auxiliar e o guarda posi��o apontam para o inicio da lista
        novo->dado = valor; // dado informado � inserido no novo n�

        if(posicao->prox == NULL && posicao->dado == elementoPosterior)  // se haver apenas elemento �nico e ele existir
            *lista = novo; // n� vai para o in�cio da lista

        else if(posicao->prox == NULL && posicao->dado != elementoPosterior) // se haver apenas um elemento e ele n�o for o desejado
            return false;

        else
        {
            while(posicao->dado != elementoPosterior) // enquanto o elemento posterior ao que ser� inserido n�o for achado
            {

                if(posicao->dado == elementoPosterior) // se for achado, o ponteiro estar� apontando para ele
                    break;

                if(posicao->prox == NULL && posicao->dado != elementoPosterior) // se for o ultimo elemento e n�o foi achado, elemento nao est� na lista
                    return false;

                posicaoAnterior = posicao; // guarda a posi��o anterior
                posicao = posicao->prox; // avan�a o ponteiro

            }

            posicaoAnterior->prox = novo; // caso estiver no meio, a posi��o anterior aponta para o novo n�

        }

        novo->prox = posicao; // o novo n� aponta para a posi��o posterior, que serviu de parametro


    }

    else
        return false; // se a lista estiver vazia, n�o h� como inserir depois de algum elemento

    return true;


}

int leInicioL(No **lista) ///
{
    int dado = 0;

    if(vaziaL(lista) == false)
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado, tem essa sintaxe por ser um ponteiro duplo (*(*lista)).dado

    return dado;
}

int leFinalL(No **lista) ///
{

    No *aux = *lista;

    if(vaziaL(lista) == false){

        while(aux->prox != NULL) // vai at� o elemento final da lista
            aux = aux->prox;

        return aux->dado; // retorna o dado do elemento final
    }

    return 0; // se estiver vazia, retorna 0

}

int removeInicioL(No **lista)
{
    No* aux;
    int dado = 0;

    if(vaziaL(lista) == false) // faz a opera��o apenas se a lista estiver com pelo menos um elemento
    {
        dado = (*lista)->dado; //atribui o dado do in�cio da lista para a vari�vel dado
        aux = *lista; //pega a endere�o do primeiro n�, o qual ser� removido

        *lista = (*lista)->prox; //inicio da lista vai ser tornar o posterior ao primeiro

        delete aux; // deleta o endere�o antigo
    }

    return dado;
}

int removeFinalL(No **lista){ ///

    if(vaziaL(lista)) // caso lista estiver vazia, n�o remove nada
        return 0;

    No *posicao = *lista; // ponteiro na posi��o inicial da lista
    int retorno; // variavel de retorno

    if(posicao->prox == NULL){ // caso a lista ter um unico elemento
        retorno = posicao->dado; // armazena-o no retorno
        *lista = NULL; // e limpa a lista
    }

    else{ // caso ter mais de um elemento

        No *posicaoAnterior = *lista; // reserva um ponteiro para a posi��o anterior

        while(posicao->prox != NULL){ // enquanto n�o chegar no fim
            posicaoAnterior = posicao; // guarda a posi��o anterior
            posicao = posicao->prox; // avan�a o ponteiro
        }

        retorno = posicao->dado; // armazana o retorno
        posicaoAnterior->prox = NULL; // aponta o elemento anterior para NULL
        delete posicao; // deleta a ultima posi��o

    }

    return retorno; // retorna o valor deletado
}

bool removeElementoL(No **lista, int valor) ///
{
    No *anterior = NULL; // reserva ponteiro de posi��o anterior
    No *atual = *lista; // ponteiro da ultima posicao

    while(atual != NULL && atual->dado != valor) // enquanto nao estiver no ultimo elemento da lista e n�o achar o elemento
    {
        anterior = atual; // salva a posicao anterior
        atual = atual->prox; // avan�a o ponteiro
    }

    if(atual == NULL) // se o atual for nulo, o elemento nao foi localizado
        return false;

    if (anterior == NULL) // se o anterior for nulo, elemento est� no inicio da fila
        *lista = atual->prox; // inicio da lista recebera o segundo elemento, podendo ser outro ou ser nulo

    else   // elemento est� no meio ou final da lista
        anterior->prox = atual->prox; // elemento anterior recebe outro elemento ou null, se estiver no fim da fila

    delete(atual); // deleta o no salvo na ultima posicao

    return true;

}

No* buscaL(No **lista, int valor) ///
{

    No *n = *lista; // ponteiro que percorre toda a lista

    while (n != NULL) // enquanto n�o ter lido todos elementos
    {
        if (n->dado == valor) // testa se o valor foi encontrado
            return n;

        n = n->prox; // avan�a o ponteiro
    }

    return NULL;
}

#endif









