#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Invierte un texto
E: el texto
S: el texto pero al revés
R: debe ser char
*/
char* invertir_texto(char* texto){


    int largo = strlen(texto);

    char* textoNuevo = (char*) calloc(largo+1,sizeof(char));

    for (int i = 0; i < largo; i ++){
        textoNuevo[i] = texto[largo - i - 1];

    }
    return textoNuevo;
}

/*
Invierte un número
E: un número
S: el número al revés
R: debe ser int
*/

int invertir_numero(int numero){

    int numero2 = numero;
    int valor = 0;
    int potencia = 1;
    int valor2 = 0;

    //Calcula el número de dígitos
    while(numero > 0){
        numero = numero / 10;
        valor ++;
    }
    valor2 = valor;
    
    /*
    calcula la primera potencia
    para multiplicar los dígitos
    */
    while(valor > 1){

        potencia = potencia * 10;
        valor --;
    }

    
    
    while(valor2 != 0){
    
        numero += numero2%10 * potencia;
        numero2 = numero2/10;
        potencia = potencia/10;
        valor2 --;

    }
    return numero;
}



int buscar_numero(int num, int* arreglo, int longitud){
    
    for(int i = 0; i <= longitud; i++){
        if(arreglo[i] == num){
            printf("El numero está en la posición %d\n",i+1);
            return 0;
        }
    }
    printf("El numero no está en la lista\n");
    return 0;
}


/*
Elimina un prefijo de un texto
E: Un texto y un prefijo 
S: Un texto sin el prefijo
R: deben ser textos
*/
char* eliminar_prefijo(char* prefijo, char*texto){


    char* texto_modificable = (char*)calloc(strlen(texto)+1,sizeof(char));

    strcpy(texto_modificable,texto);
    
    int contador = 0;

    for(int i = 0; i < strlen(prefijo); i++){
        
        if(texto[i] == prefijo[i]){
            contador ++;
        }

        
    }

    if(contador == strlen(prefijo)){
            
        }else{
     
        }

}


int main(){
    int numeros[] = {1,2,3,4,5};
    //para calcular cuánto mide el arreglo
    //se le resta 1 para la posición
    int len = 0;
    len = sizeof(numeros) / sizeof(numeros[0]) - 1;

    eliminar_prefijo("ho","hola");

    return 0;
}



