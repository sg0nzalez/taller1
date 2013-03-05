#ifndef ARREGLO_STRING_H_INCLUDED
#define ARREGLO_STRING_H_INCLUDED

#include "string.h"

// Es la cantidad maxima de parametros que puede enviar un usuario
// al ejecutar un comando.
//
// Ejemplo:
//
// crearproducto 111111 222222
//       0          1      2
//
// el ejemplo anterior tiene 3 parametros

const int CANTIDAD_MAX_PARAMS = 5;

typedef struct {
    string arre[CANTIDAD_MAX_PARAMS];
    int tope;
} arreglo_string;


// dado un string, lo divide en un arreglo de strings por cada espacio en blanco
void separar_por_espacio(string texto, arreglo_string &parametros);

// devuelve el tope asociado
int obtener_tope_arreglo_string(arreglo_string parametros);

#endif // ARREGLO_STRING_H_INCLUDED
