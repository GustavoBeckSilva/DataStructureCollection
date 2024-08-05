#include <iostream>
using namespace std;

#include "hppListaComDescritor.hpp"


int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    int valor, pos;
    No* aux = nullptr;
    Lista lista = Lista();//chama o cosntrutor para inicilizar a lista

    insereInicioL(&lista, 30);
    insereInicioL(&lista, 10);
    insereFimL(&lista, 25);

       insereAntesElementoL(&lista, 20, 30);
    //insereFimL(&lista, 45);
    mostraL(&lista);

/*
    cout << "\n\n###TESTE 1 - inserindo inicio/fim\n";
    insereFimL(&lista, 10);
    insereFimL(&lista, 20);
    insereFimL(&lista, 30);
    insereFimL(&lista, 40);
    insereInicioL(&lista, 200);
    insereFimL(&lista, 500);
    cout << "Tamanho de L: " << lista.tamanho << endl;
    mostraL(&lista);


    cout << "\n\n###TESTE 2 - sobrecarga de operador para mostrar a lista\n";
    mostraL(&lista);


     cout << "\n\n###TESTE 3 - verificando se está vazia\n";
    if(vaziaL(&lista) == true)
        cout << "A lista está vazia\n";
    else
        cout << "A lista NÃO está vazia\n";


    cout << "\n\n###TESTE 4 - remover no início da lista\n";
    cout << "remover o nó com o valor 200\n";
    removeL(&lista, 200);
    mostraL(&lista);


    cout << "\n\n###TESTE 5 - remover no meio da lista\n";
    cout << "podemos verificar se a remoção foi realizado com sucesso (se o elemento foi encontrado)\n";
    if(removeL(&lista, 20) == true)
        cout << "O valor 20 foi removido da lista!\n";
    else
        cout << "O valor 20 não foi encontrado!\n";

    mostraL(&lista);


    cout << "\n\n###TESTE 6 - remover no final da lista\n";
    cout << "remover o nó com o valor 500\n";
    removeL(&lista, 500);
    mostraL(&lista);


    cout << "\n\n###TESTE 7 - busca\n";
    aux = buscaL(&lista, 30);
    if(aux != NULL)
        cout << "Um nó com o valor 30 foi encontrado: " << aux->dado << "\n";
    else
        cout << "O valor 30 não foi entrado na lista\n";


    cout << "\n\n###TESTE 8 - busca\n";
    aux = buscaL(&lista, 1);
    if(aux != NULL)
        cout << "Um nó com o valor 1 foi encontrado: " << aux->dado << "\n";
    else
        cout << "O valor 1 não foi entrado na lista\n";



    destroiL(&lista);*/
    return EXIT_SUCCESS;

}
