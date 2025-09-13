#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "clase02.h"


//Crea un nodo 
struct nodo{
    int valor;
    struct nodo* sigt;

};
//inicio de la lista
struct lista{
    struct nodo* inicio;
};

/*
Crea los nodos
E: el valor que va a tener el nodo
S: un nodo
R: debe dársele un valor
*/
struct nodo* crear_nodo(int valor){
    struct nodo* n_nodo = calloc(1,sizeof(struct nodo));
    if(n_nodo != NULL) {
        n_nodo->valor = valor;
    }
    return n_nodo;
};
/*
Imprime la lista
E: puntero de la lista
S: lista impresa
R: debe dársele el puntero
*/
int imprimir_lista(struct lista* lista){

    struct nodo* actual = lista -> inicio;

    while(actual != NULL){
        printf("%d\n",actual -> valor);

        actual = actual -> sigt;
    }
    return 0;
}

/*
Inserta un elemento al final de la lista
E: la dirección de la lista y el valor a insertar
S: lista con el elemento nuevo al final
R: deben darse los parámetros que son
*/
int insertar_final(struct lista* lista, int valor){
    struct nodo* n_nodo = crear_nodo(valor);

    struct nodo* actual = lista->inicio;

    if(lista->inicio == NULL){
        lista-> inicio = n_nodo;
        return 0;
    }

    while(actual->sigt != NULL){

        actual = actual -> sigt;
    }
    actual -> sigt = n_nodo;
    return 0;
}

/*
Inserta un elemento al inicio de la lista
E: la dirección de la lista y el valor a insertar
S: lista con el elemento nuevo al inicio
R: deben darse los parámetros que son
*/
int insertar_inicio(struct lista* lista, int valor){
    struct nodo* n_nodo = crear_nodo(valor);

    struct nodo* actual = lista->inicio;

    
    if(lista->inicio == NULL){
        lista-> inicio = n_nodo;
        return 0;
    }
    n_nodo->sigt = lista->inicio;
    lista->inicio = n_nodo;

    return 0;
}

/*
Inserta un elemento de manera ordenada en la lista
E: la dirección de la lista y el valor a insertar
S: lista con el elemento nuevo en la posición que va
R: deben darse los parámetros que son
*/
int insertar_ordenado(struct lista* lista, int valor){
    struct nodo* n_nodo = crear_nodo(valor);

    struct nodo* actual = lista->inicio;

    
    if(lista->inicio == NULL || lista->inicio->valor > valor){
        n_nodo->sigt = lista->inicio;
        lista-> inicio = n_nodo;
        return 0;
    }

    while (actual->sigt != NULL && actual->valor < valor) {
        actual = actual->sigt;
    }
    
    n_nodo->sigt = actual->sigt;
    actual->sigt = n_nodo;

    return 0;
}


/*
Elimina un elemento de la lista
E: la lista y el elemento
S: la lista sin el elemento
R: deben ser lista y elemento
*/
int eliminar_elemento(struct lista* lista, int valor){

    if(lista -> inicio == NULL){
        return 1;
    }
    /*se crea actual y anterior para 
    recorrer la lista guardando las direcciones
    */
    struct nodo* actual = lista -> inicio;
    struct nodo* anterior = NULL;


    //para el primer valor
    if(actual -> valor == valor){

        lista->inicio = actual->sigt;
        free(actual);
        return 0;
    }

    //si no está en el primero

    while(actual != NULL && actual->valor != valor){

        anterior = actual;
        actual = actual->sigt;
    }

    //si no existe el valor

    if(actual == NULL){
        return 1;
    }

    anterior->sigt = actual->sigt;

    free(actual);


    return 0;

}

int main(){

    /*
    Unas pruebas sencillas, mezclando los números
    a ver si sí se inserta donde es
    */
    struct lista lista1;
    lista1.inicio = NULL;
    insertar_final(&lista1,5);
    insertar_final(&lista1,6);
    insertar_final(&lista1,7);
    insertar_inicio(&lista1,3);
    insertar_inicio(&lista1,2);
    insertar_inicio(&lista1,1);
    insertar_ordenado(&lista1,4);
    insertar_ordenado(&lista1,8);
    insertar_ordenado(&lista1,0);
    eliminar_elemento(&lista1,0);
    imprimir_lista(&lista1);


    return 0;
}