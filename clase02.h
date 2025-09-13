#ifndef CLASE02_H
#define CLASE02_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

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
    struct nodo* n_nodo =  (struct nodo*) calloc(1,sizeof(struct nodo));
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
int imprimir_lista(struct lista* lista);

/*
Inserta un elemento al final de la lista
E: la dirección de la lista y el valor a insertar
S: lista con el elemento nuevo al final
R: deben darse los parámetros que son
*/
int insertar_final(struct lista* lista, int valor);


/*
Inserta un elemento al inicio de la lista
E: la dirección de la lista y el valor a insertar
S: lista con el elemento nuevo al inicio
R: deben darse los parámetros que son
*/
int insertar_inicio(struct lista* lista, int valor);

/*
Inserta un elemento de manera ordenada en la lista
E: la dirección de la lista y el valor a insertar
S: lista con el elemento nuevo en la posición que va
R: deben darse los parámetros que son
*/
int insertar_ordenado(struct lista* lista, int valor);

/*
Elimina un elemento de la lista
E: la lista y el elemento
S: la lista sin el elemento
R: deben ser lista y elemento
*/
int eliminar_elemento(struct lista* lista, int valor);



#endif