#include "lista_facturas.h"

void crear_lista_factura(lista_facturas &lista_fac) {
    lista_fac = NULL;
}

void lista_insertar_factura(lista_facturas &lista_fact, factura fact) {

    if (lista_fact == NULL) {
        lista_fact = new nodo_factura;

        lista_fact->fac = fact;
        lista_fact->sig_factura = NULL;
    }
    else {
        lista_insertar_factura(lista_fact->sig_factura, fact);
    }
}

boolean existe_numero_factura(lista_facturas facturas, int numFactura) {
    lista_facturas aux = facturas;

    while (aux != NULL) {
        if (aux->fac.numero == numFactura)
            return TRUE;

        aux = aux->sig_factura;
    }

    return FALSE;
}
