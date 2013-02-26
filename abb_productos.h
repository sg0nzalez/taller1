#ifndef ABB_PRODUCTOS_H_INCLUDED
#define ABB_PRODUCTOS_H_INCLUDED

#include "producto.h"

typedef struct nodo_abb_productos {
    producto prod;
    nodo_abb_productos *nodo_izquierda;
    nodo_abb_productos *nodo_derecha;
} abb_productos;

// crea un nuevo abb de productos
void abb_crear_producto(abb_productos &productos);

// inserta el producto dado en el abb de productos dado
void abb_insertar_producto(abb_productos productos, producto &prod);

// precondicion: el codigo debe ser valido
//
// devuelve el producto con el codigo dado si existe alguno
producto abb_buscar_producto(abb_productos productos, int codigo);

// devuelve true si el abb de productos es vacio
boolean abb_producto_es_vacio(abb_productos productos);

// devuelve true si hay algun producto con el codigo dado
boolean abb_existe_codigo(abb_productos productos, int codigo);

#endif // ABB_PRODUCTOS_H_INCLUDED
