#include "arreglo_string.h"

void separar_por_espacio(string texto, arreglo_string &parametros) {

    string aux = new char[MAX];
    int i = 0;
    int k = 0;

    parametros.tope = 0;

    while ((texto[i] != '\0') && (i < MAX)) {
        if(texto[i]==' '){
            if(texto[i-1]!=' ' && texto[i+1]!=' ' && texto[i-1]!=NULL){

                aux[k] = '\0';
                parametros.arre[parametros.tope] = aux;
                aux = new char[MAX];
                k = 0;
                parametros.tope++;

            } else {
                if(texto[i-1]!=' ' && texto[i-1] != NULL) {

                    aux[k] = '\0';
                    parametros.arre[parametros.tope] = aux;
                    aux = new char[MAX];
                    k = 0;
                    parametros.tope++;
                }
            }
        } else {
            aux[k] = texto[i];

            k++;
        }

        i++;
    }

    if(aux[0]!=NULL) {
        aux[k] = '\0';
        copiar_string(parametros.arre[parametros.tope], aux);
        parametros.tope++;
    }

    destruir_string(aux);
}

int obtener_tope_arreglo_string(arreglo_string parametros) {
    return parametros.tope;
}
