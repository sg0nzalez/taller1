#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include "arreglo_string.h"

typedef struct {
    long int cedula;
    string nombre;
} cliente;

// devuelve la cedula del cliente dado
long int obtener_cedula_cliente(cliente cli);

// asigna al parametro &nom el nombre del cliente dado
void obtener_nombre_cliente(cliente cli, string &nom);

#endif // CLIENTE_H_INCLUDED
