#include "linea.h"
#include "boolean.h"

boolean validar_cantidad_productos(int cantidad) {
    return boolean(cantidad >= 0);
}

boolean validar_precio(int precio) {
    return boolean(precio >= 0);
}

// devuelve el codigo del producto asociado a la linea dada
int obtener_codigo_producto_linea(linea lin) {

    return lin.codigo_producto;
}

// devuelve la cantidad de productos asociados a la linea dada
int obtener_cantidad_productos_linea(linea lin) {

    return lin.cant_productos;
}

// devuelve el precio unitario asociado a la linea dada
int obtener_precio_unitario_linea(linea lin) {

    return lin.precio_unitario;
}

// devuelve el codigo del producto asociado a la linea dada
void modificar_codigo_producto_linea(linea &lin, int codigo) {
    lin.codigo_producto = codigo;
}

// devuelve la cantidad de productos asociados a la linea dada
void modificar_cantidad_productos_linea(linea &lin, int cantidad) {
    lin.cant_productos = cantidad;
}

// devuelve el precio unitario asociado a la linea dada
void modificar_precio_unitario_linea(linea &lin, int precio) {
    lin.precio_unitario = precio;
}

// devuelve la multiplicación entre precio unitario y cantidad
float importe_linea(linea lin) {

	return lin.precio_unitario * lin.cant_productos;
}

// devuelve la suma entre importe_linea y iva_linea
float importe_total_linea(linea lin) {

	return importe_linea(lin) + iva_linea(lin);
}

// devuelve la multiplicación entre importe y IVA
float iva_linea(linea lin) {

    return importe_linea(lin) * IVA;
}
