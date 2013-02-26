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

// es necesario este procedimiento ????
// o podemos tan solo hacer fac.lineas_factura ???
void obtener_arreglo_lineas_factura(factura fac, arreglo_lineas &arr_lineas) {
    int cantidad_lineas = obtener_arreglo_lineas_tope(fac.lineas_factura);

    arr_lineas.tope = 0;

    // no tengo ni idea si esto se hace as’ :D
    for(int i = 0; i < cantidad_lineas; i++) {
        arr_lineas.lineas[i] = fac.lineas_factura.lineas[i];

        arr_lineas.tope++;
    }
}
