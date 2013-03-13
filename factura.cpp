#include "factura.h"

int obtener_numero_factura(factura fac) {
    return fac.numero;
}

long int obtener_cedula_cliente_factura(factura fac) {
    return fac.cedula_cliente;
}

boolean obtener_estado_factura(factura fac) {
    return fac.estado_pendiente;
}

void modificar_arreglo_lineas_factura(factura &fac, arreglo_lineas arr_lineas) {
    int cantidad_lineas = obtener_arreglo_lineas_tope(arr_lineas);

    fac.lineas_factura.tope = cantidad_lineas;

    for(int i = 0; i < cantidad_lineas; i++) {
        fac.lineas_factura.lineas[i] = arr_lineas.lineas[i];
    }
}

void obtener_arreglo_lineas_factura(factura fac, arreglo_lineas &arr_lineas) {
    int cantidad_lineas = obtener_arreglo_lineas_tope(fac.lineas_factura);

    arr_lineas.tope = cantidad_lineas;

    for(int i = 0; i < cantidad_lineas; i++) {
        arr_lineas.lineas[i] = fac.lineas_factura.lineas[i];
    }
}
