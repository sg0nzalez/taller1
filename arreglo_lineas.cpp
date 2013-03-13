#include "arreglo_lineas.h"

void agregar_linea_al_arreglo(arreglo_lineas &arre_lineas, linea lin) {
    arre_lineas.lineas[arre_lineas.tope] = lin;
    arre_lineas.tope++;
}

boolean validar_cant_lineas(arreglo_lineas arre_lineas) {
    return boolean(arre_lineas.tope < 10);
}

float importe_arreglo_lineas(arreglo_lineas arre_lineas) {
    float resultado = 0;

    for(int i = 0; i < arre_lineas.tope; i++) {
        resultado += importe_linea(arre_lineas.lineas[i]);
    }

    return resultado;
}

float importe_total_arreglo_lineas(arreglo_lineas arre_lineas) {
    float resultado = 0;

    for(int i = 0; i < arre_lineas.tope; i++) {
        resultado += importe_total_linea(arre_lineas.lineas[i]);
    }

    return resultado;
}

float iva_arreglo_lineas(arreglo_lineas arre_lineas) {
    float resultado = 0;

    for(int i = 0; i < arre_lineas.tope; i++) {
        resultado += iva_linea(arre_lineas.lineas[i]);
    }

    return resultado;
}

int obtener_arreglo_lineas_tope(arreglo_lineas arre_lineas) {
    return arre_lineas.tope;
}
