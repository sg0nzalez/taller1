#include "lista_facturas.h"

void crear_lista_factura(lista_facturas &lista_fac) {
    //lista_fac = NULL;
}

void lista_insertar_factura(lista_facturas &facturas, factura fact) {
/*    lista_facturas aux = new nodo_factura;

    aux->info = fact;
    aux->sig = facturas;
    facturas = aux;

    aux = NULL;*/
}

boolean existe_numero_factura(lista_facturas facturas, int numFactura) {
    /*lista_facturas aux = facturas;

    while (aux != NULL) {
        if (aux == numFactura)
            return TRUE;

        aux = aux->sig;
    }

    return FALSE;*/
}

void borrar(lista_facturas &lista_fac) {
    /*lista aux;
    aux = lista_fac;
    lista_fac = lista_fac->sig;

    delete aux;*/
}
