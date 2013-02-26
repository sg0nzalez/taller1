#include "producto.h"

// modifica el valor del par�metro nombre por el nombre del producto dado
void obtener_nombre_producto(producto prod, string &nombre) {
    copiar_string(nombre, prod.nombre);
}

// devuelve la c�dula del cliente dado
int obtener_codigo_producto(producto prod) {
    return prod.codigo;
}

// devuleve true si es positivo
boolean validar_precio_producto(int precio) {
    return boolean(precio >= 0);
}
