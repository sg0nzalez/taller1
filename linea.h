#ifndef LINEA_H_INCLUDED
#define LINEA_H_INCLUDED

#include "arreglo_string.h"

const float IVA = 0.22;

typedef struct {
    int codigo_producto;
    int cant_productos;
    float precio_unitario;
} linea;

// devuelve true si la cantidad dada es positiva
boolean validar_cantidad_productos(int cantidad);

// devuelve true si el precio es positivo
boolean validar_precio(int precio);

// devuelve el codigo del producto asociado a la linea dada
int obtener_codigo_producto_linea(linea lin);

// devuelve la cantidad de productos asociados a la linea dada
int obtener_cantidad_productos_linea(linea lin);

// devuelve el precio unitario asociado a la linea dada
float obtener_precio_unitario_linea(linea lin);

// devuelve la multiplicación entre precio unitario y cantidad
float importe_linea(linea lin);

// devuelve la suma entre importe_linea y iva_linea
float importe_total_linea(linea lin);

// devuelve la multiplicación entre importe y IVA
float iva_linea(linea lin);

#endif // LINEA_H_INCLUDED

