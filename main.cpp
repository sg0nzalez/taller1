#include "string.h"

int main(){

    string s1;
    crear_string(s1);
    string s2;
    crear_string(s2);

    printf("Ingrese un string");
    cargar_string(s1);

    printf("Ingrese un string");
    cargar_string(s2);

    boolean iguales = comparar_2_strings(s1, s2);

    if(iguales) {
        printf("Son iguales");
    } else {
        printf("No son iguales");
    }

    desplegar_string(s1);

    copiar_string(s1, s2);

    desplegar_string(s1);

    largo_string(s1);

    iguales = comparar_2_strings(s1, s2);

    if(iguales) {
        printf("Son iguales");
    } else {
        printf("No son iguales");
    }

    destruir_string(s1);
    destruir_string(s2);

// dado un string, lo divide en un arreglo de strings por cada espacio en blanco
//void separar_por_espacio(string str, arreglo_string &parametros);


}
