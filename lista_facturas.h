#ifndef LISTA_FACTURAS_H_INCLUDED
#define LISTA_FACTURAS_H_INCLUDED

#include "factura.h"

typedef struct nodo_siguiente_factura {
    factura fac;
    nodo_siguiente_factura *sig_factura;
} nodo_factura;

typedef nodo_factura *lista_facturas;

// devuelve true si el c˜digo dado ya esta ingresado en la lista de facturas
boolean existe_numero_factura(lista_facturas facturas, int numFactura);

void modificar_factura(lista_facturas &lista_fact, factura factura_modificada);

// precondicion: existe la factura
//
// retorna la factura asociada al numero dado
factura obtener_factura(lista_facturas facturas, int numFactura);

// crea una nueva lista
void crear_lista_factura(lista_facturas &lista);

// inserta la factura dada en la lista de facturas dada
void lista_insertar_factura(lista_facturas &lista_fact, factura &fact, int numero_anterior);

#endif // LISTA_FACTURAS_H_INCLUDED
