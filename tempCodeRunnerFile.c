

struct nodo{

    int valor;
    struct nodo* sigt;

};

struct lista{
    struct nodo* inicio;
};

struct nodo* crear_nodo(int valor){
    struct nodo* n_nodo = calloc(1,sizeof(struct nodo));

    return n_lista;
};

int imprimir_lista(struct lista* lista){

    struct nodo* actual = NULL;
    actual = lista -> inicio;

    while(actual != NULL){
        printf("%d\n",actual -> valor);

        actual = actual -> sigt;
    }
    return 0;
}

int insertar_final(struct lista* lista, int valor){
    struct nodo* n_nodo = crear_nodo(valor);

    struct nodo* actual = NULL;

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