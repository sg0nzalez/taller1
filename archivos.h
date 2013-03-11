#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "lista_facturas.h"
#include "abb_productos.h"
#include "abb_clientes.h"
#include "arreglo_lineas.h"

const string ARCHIVO_CLIENTES = "/home/santi/Desktop/clientes.txt";
const string ARCHIVO_PRODUCTOS = "/home/santi/Desktop/productos.txt";

// devuelve true si nombre_archivo termina en .dat
boolean validar_nombre_archivo(string nombre_archivo);

// devuelve true si el nombre del archivo dado ya existe en nuestro disco
boolean existe_archivo(string nombre_archivo);

// dado un cliente y un FILE, guarda dicho cliente en el archivo dado
void bajar_cliente(cliente cli, FILE *f);

// dado un cliente y un FILE, obtiene el cliente en el archivo dado que este
// en la posicion actual del puntero dentro del archivo y dicho cliente
// lo guarda en el cliente dado
void levantar_cliente(cliente &clie, FILE *f);

// abre el archivo y baja todos los clientes del abb, luego cierra el archivo
void bajar_abb_cliente(abb_clientes clientes, FILE *f);

// recursivamente va bajando cliente por cliente
void bajar_abb_cliente_aux(abb_clientes clientes, FILE *f);

// abre el archivo, obtiene todos los clientes y luego lo cierra
void levantar_abb_cliente(abb_clientes &clientes, FILE *f);

// dado un producto y un FILE, guarda dicho producto en el archivo dado
void bajar_producto(producto prod, FILE *f);

// dado un producto y un FILE, obtiene el producto en el archivo dado que este
// en la posicion actual del puntero dentro del archivo y dicho producto
// lo guarda en el producto dado
void levantar_producto(producto &prod, FILE *f);

// abre el archivo y baja todos los productos del abb, luego cierra el archivo
void bajar_abb_producto(abb_productos productos, FILE *f);

// recursivamente va bajando producto por producto
void bajar_abb_producto_aux(abb_productos productos, FILE *f);

// abre el archivo, obtiene todos los productos y luego lo cierra
void levantar_abb_producto(abb_productos &productos, FILE *f);

// dado un string y un FILE, guarda dicho string en el archivo dado
void bajar_string(string str, FILE *f);

// dado un string y un FILE, carga el string dado con un string que
// este en la posicion del puntero en el archivo dado
void levantar_string(string &str, FILE *f);


#endif // ARCHIVOS_H_INCLUDED
