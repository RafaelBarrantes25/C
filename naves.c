#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h> //Para una semilla aleatoria


//Crea un nodo 
struct nodo{
    int valor;
    int vida;
    int ataque;
    struct nodo* sigt;
    struct nodo* ant;

};
//inicio de la lista
struct lista{
    struct nodo* inicio;
    struct nodo* final; //un final para facilitar inserción al final
};

/*
Crea los nodos
E: el valor que va a tener el nodo
S: un nodo
R: debe dársele un valor
*/
struct nodo* crear_nodo(int valor, int vida, int ataque){
    struct nodo* n_nodo = calloc(1,sizeof(struct nodo));
    if(n_nodo != NULL) {
        n_nodo->valor = valor;
        n_nodo->vida = vida;
        n_nodo->ataque = ataque;
        n_nodo->sigt = NULL; //Se inicializan los valores
        n_nodo->ant = NULL; 
    }
    return n_nodo;
};
/*
Imprime la lista
E: puntero de la lista
S: lista impresa
R: debe dársele el puntero
*/
//MODIFICAR PARA VIDA Y ATAQUE
int imprimir_lista(struct lista* lista){

    struct nodo* actual = lista -> inicio;

    while(actual != NULL){
        printf("%s%d%s%d%s%d\n","Nave: ",actual -> valor," Vida: ",
            actual->vida," Ataque: ",actual->ataque);

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
int insertar_final(struct lista* lista, int valor, int vida, int ataque){
    struct nodo* n_nodo = crear_nodo(valor,vida,ataque);
    struct nodo* actual = lista->inicio;

    if(lista->inicio == NULL){
        lista-> inicio = n_nodo;
        lista-> final = n_nodo;
        return 0;
    }

    lista->final->sigt = n_nodo; //se inserta al final
    n_nodo->ant = lista->final;
    lista->final = n_nodo; 

    return 0;
}

/*
Inserta un elemento al inicio de la lista
E: la dirección de la lista y el valor a insertar
S: lista con el elemento nuevo al inicio
R: deben darse los parámetros que son
*/
int insertar_inicio(struct lista* lista, int valor, int vida, int ataque){
    struct nodo* n_nodo = crear_nodo(valor,vida,ataque);
    struct nodo* actual = lista->inicio;

    
    if(lista->inicio == NULL){
        lista-> inicio = n_nodo;
        lista->final = n_nodo;
        return 0;
    }
    n_nodo->sigt = lista->inicio;
    lista->inicio->ant = n_nodo;
    lista->inicio = n_nodo;

    return 0;
}

/*
Inserta un elemento de manera ordenada en la lista
E: la dirección de la lista y el valor a insertar
S: lista con el elemento nuevo en la posición que va
R: deben darse los parámetros que son
*/
int insertar_ordenado(struct lista* lista, int valor, int vida, int ataque){
    struct nodo* n_nodo = crear_nodo(valor,vida,ataque);


    //si la lista está vacía o el valor del nuevo es menor o igual al primero
    if(lista->inicio == NULL || lista->inicio->valor >= valor){
        n_nodo->sigt = lista->inicio;
        if(lista->inicio == NULL){
            lista->inicio->ant = n_nodo;
        }
        lista->inicio = n_nodo;

        if(lista->final == NULL){
            lista->final = n_nodo;
        }
        return 0;
    }

    struct nodo* actual = lista->inicio;
    //avanza en la lista hasta que llega al valor
    while (actual->sigt != NULL && actual->valor < valor) {
        actual = actual->sigt;
    }
    
    //se inserta
        n_nodo->sigt = actual->sigt;
    if(actual->sigt != NULL) {
        actual->sigt->ant = n_nodo;
    } else {
        lista->final = n_nodo;
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

    //Error si no hay elementos
    if(lista->inicio == NULL){
        return 1;
    }

    struct nodo* actual = lista->inicio;

    while(actual != NULL && actual->valor != valor){
        actual = actual->sigt;
    }

    //si llega al final  y no encuentra el valor
    if(actual == NULL){
        return 1; 
    }

    //si no hay anterior es que es el primero, entonces
    //elimina y cambia punteros
    if(actual->ant != NULL){
        actual->ant->sigt = actual->sigt;
    } else {
        lista->inicio = actual->sigt; 
    }

    //si es el final mueve el puntero
    if(actual->sigt != NULL){
        actual->sigt->ant = actual->ant;
    } else {
        lista->final = actual->ant;
    }
    
    free(actual);
    
    return 0;

}

int main(){

    srand(time(NULL));
    struct lista naves;
    //Genera un número entre 4 y 7 para las naves
    int aleatorio = (rand() % 3)+5;
    
    for(int i = 1;i<aleatorio+1;i++){
        //Vida y ataque aleatorios a cada nave entre 5 y 9
        int aleatorioV = (rand() % 6)+4;
        int aleatorioA = (rand() % 6)+4;
        insertar_final(&naves,i,aleatorioV,aleatorioA);
    }
    imprimir_lista(&naves);
    return 0;
}