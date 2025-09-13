#include "clase02.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

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