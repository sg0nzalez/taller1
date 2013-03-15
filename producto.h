#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include "arreglo_string.h"

typedef struct {
    int codigo;
    string nombre;
} producto;

// modifica el valor del parametro nombre por el nombre del producto dado
void obtener_nombre_producto(producto prod, string &nombre);

// devuelve la cedula del cliente dado
int obtener_codigo_producto(producto prod);

// devuelve true si el precio es positivo, en otro caso retorna false
boolean validar_precio_producto(int precio);

// modifica el nombre del producto
void modificar_nombre_producto(producto &prod, string nombre);

// modifica el codigo del producto
void modificar_codigo_producto(producto &prod, int codigo);

#endif // PRODUCTO_H_INCLUDED
