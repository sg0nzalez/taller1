#include "abb_productos.h"


// crea un nuevo abb de productos
void crear_abb_productos(abb_productos &productos)
{
    productos = NULL;
}

// inserta el producto dado en el abb de productos
void abb_insertar_producto(abb_productos &productos, producto prod) {
    if (productos == NULL) {
        productos = new nodo_abb_productos;
        productos->prod=prod;
        productos->nodo_izquierda=NULL;
        productos->nodo_derecha=NULL;
    } else {
        if (obtener_codigo_producto(prod) < obtener_codigo_producto(productos->prod)) {
            abb_insertar_producto(productos->nodo_izquierda, prod);
        } else {
            abb_insertar_producto(productos->nodo_derecha, prod);
        }
    }
}

// precondicion: el codigo debe ser valido
//
// devuelve el producto con el codigo dado si existe alguno
 producto abb_buscar_producto(abb_productos productos, int codigo)
{

    if (codigo == obtener_codigo_producto(productos->prod))
    {
        return productos->prod;
    }
    else
    {
        if (codigo < obtener_codigo_producto(productos->prod))
        {
            return abb_buscar_producto(productos->nodo_izquierda,codigo);
        }

        else
        {
            abb_buscar_producto(productos->nodo_derecha,codigo);
        }

   }
}

void listar_productos(abb_productos productos) {
    if (productos != NULL) {
        listar_productos(productos->nodo_izquierda);

        if (productos->nodo_izquierda != NULL)
            printf("\n");

        printf("%li - ", obtener_codigo_producto(productos->prod));

        string nombre_producto;
        obtener_nombre_producto(productos->prod, nombre_producto);
        desplegar_string(nombre_producto);
        destruir_string(nombre_producto);

        if (productos->nodo_derecha != NULL)
            printf("\n");

        listar_productos(productos->nodo_derecha);
    }
}

// devuelve true si el abb de productos es vacio
boolean abb_producto_es_vacio(abb_productos productos)
{
    return (boolean)(productos == NULL);
}

// devuelve true si hay algun producto con el codigo dado
boolean abb_existe_codigo(abb_productos productos, int codigo)
{
    boolean es_vacio = abb_producto_es_vacio(productos);
       if(es_vacio==FALSE){
        if (codigo == obtener_codigo_producto(productos->prod))
        {
            return TRUE;
        }
        else
        {
            if (codigo < obtener_codigo_producto(productos->prod))
            {
                return abb_existe_codigo(productos->nodo_izquierda,codigo);
            }
            else
            {
                return abb_existe_codigo(productos->nodo_derecha,codigo);
            }
        }

        return FALSE;
    } else {
        return FALSE;
    }
}
