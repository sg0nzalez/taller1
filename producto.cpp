#include "producto.h"

// modifica el valor del par‡metro nombre por el nombre del producto dado
void obtener_nombre_producto(producto prod, string &nombre) {
    copiar_string(nombre, prod.nombre);
}

// devuelve la cŽdula del cliente dado
int obtener_codigo_producto(producto prod) {
    return prod.codigo;
}

// devuleve true si es positivo
boolean validar_precio_producto(int precio) {
    return boolean(precio >= 0);
}

// modifica el nombre del producto
void modificar_nombre_producto(producto &prod, string nombre) {
    copiar_string(prod.nombre, nombre);
}

// modifica el codigo del producto
void modificar_codigo_producto(producto &prod, int codigo) {
    prod.codigo = codigo;
}
