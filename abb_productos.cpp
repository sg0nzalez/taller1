#include "abb_productos.h"


// crea un nuevo abb de productos
void crear_abb_productos(abb_productos &productos)
{
    productos = NULL;
}



// inserta el producto dado en el abb de productos
void abb_insertar_producto(abb_productos &productos, producto prod)
{

    boolean existe_producto;
    existe_producto = abb_existe_codigo(productos, obtener_codigo_producto(prod));
    if (existe_producto==FALSE)
    {

        if (productos ==NULL)
        {

            productos = new nodo_abb_productos;
            productos->prod=prod;
            productos->nodo_izquierda=NULL;
            productos->nodo_derecha=NULL;

        }
        else
        {

            if (obtener_codigo_producto(prod) < obtener_codigo_producto(productos->prod))
            {

                abb_insertar_producto(productos->nodo_izquierda, prod);
            }

            else
            {

                abb_insertar_producto(productos->nodo_derecha, prod);
            }
        }
    }
    else
    {
      printf("\nEL PRODUCTO NO FUE INGRESADO PORQUE YA EXISTE.\n");
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

























