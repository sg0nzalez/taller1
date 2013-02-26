#include "arreglo_lineas.h"

void agregar_linea_al_arreglo(arreglo_lineas &lins, linea lin) {
    lins.tope++;
    lins.lineas[lins.tope] = lin;
}

boolean validar_cant_lineas(arreglo_lineas lineas) {
    return boolean(lineas.tope < 10);
}

int importe_arreglo_lineas(arreglo_lineas lins) {
    int resultado = 0;

    for(int i = 0; i < lins.tope; i++) {
        resultado += importe_linea(lins.lineas[i]);
    }

    return resultado;
}

float importe_total_arreglo_lineas(arreglo_lineas lins) {
    float resultado = 0;

    for(int i = 0; i < lins.tope; i++) {
        resultado += importe_total_linea(lins.lineas[i]);
    }

    return resultado;
}

float iva_arreglo_lineas(arreglo_lineas lins) {
    float resultado = 0;

    for(int i = 0; i < lins.tope; i++) {
        resultado += iva_linea(lins.lineas[i]);
    }

    return resultado;
}

int obtener_arreglo_lineas_tope(arreglo_lineas lineas) {
    return lineas.tope;
}
