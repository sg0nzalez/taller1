#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "arreglo_string.h"

typedef struct {
    long int cedula;
    string nombre;
} cliente;

// devuelve la cedula del cliente dado
long int obtener_cedula_cliente(cliente cli);

// modifica la cedula del cliente
void modificar_cedula_cliente(cliente &cli, long int cedula);

// asigna al parametro &nombre el nombre del cliente dado
void obtener_nombre_cliente(cliente cli, string &nombre);

// modifica el nombre del cliente
void modificar_nombre_cliente(cliente &cli, string nombre);



#endif // CLIENTE_H_INCLUDED
