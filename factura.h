#ifndef FACTURA_H_INCLUDED
#define FACTURA_H_INCLUDED

#include "arreglo_lineas.h"

typedef struct {
    int numero;
    long int cedula_cliente;
    boolean estado_pendiente;
    arreglo_lineas lineas_factura;
} factura;

void agregar_linea_al_arreglo(factura fac, linea lin);

// devuelve el numero de factura
int obtener_numero_factura(factura fac);

// devuelve la cedula del cliente asociada a la factura dada
long int obtener_cedula_cliente_factura(factura fac);

// devuelve el estado de la factura dada
//
// TRUE si la factura esta en estado pendiente
// FALSE si la factura paso a confirmada
boolean obtener_estado_factura(factura fac);

//
void modificar_arreglo_lineas_factura(factura &fac, arreglo_lineas arr_lineas);

// asigna el arreglo de lineas de la factura dada al arreglo_lineas dado
void obtener_arreglo_lineas_factura(factura fac, arreglo_lineas &lineas);

#endif // FACTURA_H_INCLUDED
