#ifndef LISTA_LINEAS_H_INCLUDED
#define LISTA_LINEAS_H_INCLUDED

#include "linea.h"

const int CANTIDAD_MAX_LINEAS = 10;

typedef struct {
    linea lineas[CANTIDAD_MAX_LINEAS];
    int tope;
} arreglo_lineas;

// agrega la linea dada al arreglo
void agregar_linea_al_arreglo(arreglo_lineas lineas, linea &lin);

// devuelve true si el arreglo tiene menos de 10 lineas
boolean validar_cant_lineas(arreglo_lineas lineas);

// devuelve el importe de la factura
int importe_arreglo_lineas(arreglo_lineas lineas);

// devuelve el importe + el iva (importe total) de la factura
float importe_total_arreglo_lineas(arreglo_lineas lineas);

// devuelve el iva de la factura
float iva_arreglo_lineas(arreglo_lineas lineas);

// AGREGAR AL DOC
// devuelve el tope del arreglo
int obtener_arreglo_lineas_tope(arreglo_lineas lineas);

#endif // LISTA_LINEAS_H_INCLUDED
