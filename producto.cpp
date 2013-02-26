#include "producto.h"

void obtener_nombre_producto(producto prod, string &nombre) {
    copiar_string(nombre, prod.nombre);
}

int obtener_codigo_producto(producto prod) {
    return prod.codigo;
}

boolean validar_precio_producto(int precio) {
    boolean esPositivo = FALSE;

    if (precio >= 0) {

        esPositivo = TRUE;
    }

    return esPositivo;
}
