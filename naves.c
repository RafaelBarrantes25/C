#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h> //Para una semilla aleatoria del random


//Crea un nodo 
struct nodo{
    int valor;
    int vida;
    int ataque;
    int equipo;
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
struct nodo* crear_nodo(int valor, int vida, int ataque, int equipo){
    struct nodo* n_nodo = calloc(1,sizeof(struct nodo));
    if(n_nodo != NULL) {
        n_nodo->valor = valor;
        n_nodo->vida = vida;
        n_nodo->ataque = ataque;
        n_nodo->equipo = equipo;
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
        printf("%s%d%s%d%s%d%s%d\n","Nave: ",actual -> valor," Vida: ",
            actual->vida," Ataque: ",actual->ataque," Equipo: ",actual->equipo);

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
int insertar_final(struct lista* lista, int valor, int vida, int ataque,int equipo){
    struct nodo* n_nodo = crear_nodo(valor,vida,ataque,equipo);
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
int insertar_inicio(struct lista* lista, int valor, int vida, int ataque, int equipo){
    struct nodo* n_nodo = crear_nodo(valor,vida,ataque,equipo);
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
int insertar_ordenado(struct lista* lista, int valor, int vida, int ataque, int equipo){
    struct nodo* n_nodo = crear_nodo(valor,vida,ataque,equipo);


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
int eliminar_elemento(struct lista* lista, int vida){

    //Error si no hay elementos
    if(lista->inicio == NULL){
        return 1;
    }

    struct nodo* actual = lista->inicio;

    while(actual != NULL && actual->vida > vida){
        actual = actual->sigt;
    }

    //si llega al final  y no encuentra el valor
    if(actual == NULL){
        return 0; 
    }

    //si no hay anterior es que es el primero, entonces
    //elimina y cambia punteros
    printf("%s%d\n","Se eliminó la nave ",actual->valor);
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


int atacar_nave(struct lista* lista, int valor){

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
        return 2; 
    }


    if(actual->valor == valor){
        //Error si es enemigo
        if(actual->equipo == 2){
            return 3;
        }
        //Si es el primero
        if(actual->ant == NULL){
            actual->sigt->vida = actual->sigt->vida - actual->ataque;
            return 0;
        }

        //Si es el último
        if(actual->sigt == NULL){
            actual->ant->vida = actual->ant->vida - actual->ataque;
            return 0;
        }
        // si está en cualquier otro lado, ataca al anterior y al siguiente
        actual->ant->vida = actual->ant->vida - actual->ataque;
        actual->sigt->vida = actual->sigt->vida - actual->ataque;
    }
    
    return 0;

}

int atacar_nave_CPU(struct lista* lista, int valor){

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
        return 2; 
    }


    if(actual->valor == valor){
        //Error si es enemigo
        if(actual->equipo == 1){
            return 3;
        }
        //Si es el primero
        if(actual->ant == NULL){
            actual->sigt->vida = actual->sigt->vida - actual->ataque;
            return 0;
        }

        //Si es el último
        if(actual->sigt == NULL){
            actual->ant->vida = actual->ant->vida - actual->ataque;
            return 0;
        }
        // si está en cualquier otro lado, ataca al anterior y al siguiente
        actual->ant->vida = actual->ant->vida - actual->ataque;
        actual->sigt->vida = actual->sigt->vida - actual->ataque;
    }
    
    return 0;

}

int revisar_ganadores(struct lista* lista, int equipo){

    //Los dos perdieron
    if(lista->inicio == NULL){
        return 2;
    }

    struct nodo* actual = lista->inicio;

    while(actual != NULL && actual->equipo != equipo){
        actual = actual->sigt;
    }

    
    //si llega al final  y no encuentra el valor
    if(actual == NULL){
        //No encontró naves del equipo
        return 1; 
    }
    
    return 0;

}

int main(){

    srand(time(NULL));
    struct lista naves;
    //Genera un número entre 4 y 7 para el número de naves
    int aleatorio = (rand() % 3)+5;
    
    //Crea la lista de naves
    for(int i = 1;i<aleatorio+1;i++){
        //Vida y ataque aleatorios a cada nave entre 5 y 9
        int aleatorioV = (rand() % 6)+4;
        //El ataque es menor porque sino se mueren de un solo y no tiene gracia
        int aleatorioA = (rand() % 2)+2;

        //Equipo 1 o 2, 1 es amigos y 2 es enemigos
        int equipo = (rand()%2)+1;
        insertar_final(&naves,i,aleatorioV,aleatorioA,equipo);

    }
    imprimir_lista(&naves);
    int juego = 1;
    int turno = 1;
    while(juego == 1){
        //Turno del jugador
        while(turno == 1){
            int numNave = 0;
            printf("Escoja un número de nave para que ataque: \n");
            scanf("%d", &numNave);

            //Revisa si se pudo atacar o no
            int estadoAtaque = atacar_nave(&naves,numNave);
            if(estadoAtaque == 3){
                printf("%s\n","La nave escogida es de los enemigos."); 
                while (getchar() != '\n');
                
            } else if(estadoAtaque == 2){
                printf("%s\n","La nave escogida no existe.");
                while (getchar() != '\n');
                }
            
            else{
                printf("%s%d%s\n","La nave ",numNave," atacó a las naves de la par.");
                break;
            }

        }
        //Se revisa 2 veces porque un disparo podría matar 2 naves
        for(int i = 0;i != 2;i++){
            eliminar_elemento(&naves,0);
        }
        imprimir_lista(&naves);

        //Se revisa si hay ganadores
        int revAli = revisar_ganadores(&naves,1);
        int revEne = revisar_ganadores(&naves,2);

        if(revAli == 2){
            printf("%s\n","Ambos equipos se quedar3on sin naves");
            juego = 0;
        }
        if(revAli == 1){
            printf("%s\n","Los aliados se quedaron sin naves, los enemigos ganan.");
            juego = 0;
        }
        if(revEne == 1){
            printf("%s\n","Los enemigos se quedaron sin naves, los aliados ganan.");
            juego = 0;
        }
        printf("\n");
        turno = 2;
        

        //Turno enemigoAAA
        
        while(turno == 2){
            int numNaveCPU = 0;
            
            numNaveCPU = (rand()%aleatorio)+1;

            //Revisa si se pudo atacar o no
            int estadoAtaqueCPU = atacar_nave_CPU(&naves,numNaveCPU);
            
            if(estadoAtaqueCPU != 2 && estadoAtaqueCPU != 3){
                printf("%s%d%s\n","La nave ",numNaveCPU," atacó a las naves de la par.");
                break;
            }else{
                continue;
            }

        }
        //Se revisa 2 veces porque un disparo podría matar 2 naves
        for(int i = 0;i != 2;i++){
            eliminar_elemento(&naves,0);
        }
        imprimir_lista(&naves);

        //Se revisa si hay ganadores
        revAli = revisar_ganadores(&naves,1);
        revEne = revisar_ganadores(&naves,2);

        if(revAli == 2){
            printf("%s\n","Ambos equipos se quedaron sin naves");
            juego = 0;
        }
        if(revAli == 1){
            printf("%s\n","Los aliados se quedaron sin naves, los enemigos ganan.");
            juego = 0;
        }
        if(revEne == 1){
            printf("%s\n","Los enemigos se quedaron sin naves, los aliados ganan.");
            juego = 0;

        }
        turno = 1;
        
    }

    return 0;
}