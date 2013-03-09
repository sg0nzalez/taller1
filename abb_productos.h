#ifndef ABB_PRODUCTOS_H_INCLUDED
#define ABB_PRODUCTOS_H_INCLUDED

#include "producto.h"

typedef struct nodo_producto {
    producto prod;
    nodo_producto *nodo_izquierda;
    nodo_producto *nodo_derecha;
} nodo_abb_productos;

typedef nodo_abb_productos *abb_productos;

// crea un nuevo abb de productos
void crear_abb_productos(abb_productos &productos);

// inserta el producto dado en el abb de productos dado
void abb_insertar_producto(abb_productos &productos, producto prod);

// precondicion: el codigo debe ser valido
//
// devuelve el producto con el codigo dado si existe alguno
producto abb_buscar_producto(abb_productos productos, int codigo);

// devuelve true si el abb de productos es vacio
boolean abb_producto_es_vacio(abb_productos productos);

// devuelve true si hay algun producto con el codigo dado
boolean abb_existe_codigo(abb_productos productos, int codigo);

#endif // ABB_PRODUCTOS_H_INCLUDED
