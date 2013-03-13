#include "lista_facturas.h"

void crear_lista_factura(lista_facturas &lista_fac) {
    lista_fac = NULL;
}

void lista_insertar_factura(lista_facturas &lista_fact, factura &fact, int numero_anterior) {
    if (lista_fact == NULL) {
        lista_fact = new nodo_factura;

        fact.numero = numero_anterior + 1;

        lista_fact->fac = fact;
        lista_fact->sig_factura = NULL;
    } else {
        lista_insertar_factura(lista_fact->sig_factura, fact, obtener_numero_factura(fact));
    }
}

void modificar_factura(lista_facturas &lista_fact, factura factura_modificada) {
    if (lista_fact != NULL) {
        if (obtener_numero_factura(lista_fact->fac) == obtener_numero_factura(factura_modificada)) {
            lista_fact->fac = factura_modificada;
        } else {
            modificar_factura(lista_fact->sig_factura, factura_modificada);
        }
    }
}

factura obtener_factura(lista_facturas facturas, int numFactura) {
    lista_facturas aux = facturas;

    while (aux != NULL) {
        if (aux->fac.numero == numFactura)
            return aux->fac;

        aux = aux->sig_factura;
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
