#ifndef ABB_CLIENTES_H_INCLUDED
#define ABB_CLIENTES_H_INCLUDED

#include "cliente.h"

typedef struct nodo_abb_clientes {
    cliente cli;
    nodo_abb_clientes *nodo_izquierda;
    nodo_abb_clientes *nodo_derecha;
} abb_clientes;

// crea el abb
void abb_crear_cliente(abb_clientes &clientes);

// inserta el cliente en el abb
void abb_insertar_cliente(abb_clientes clientes, cliente &cli);

// precondicion: debe existir un cliente con la cedula dada
//
// busca un cliente en el abb y lo devuelve
cliente abb_buscar_cliente(abb_clientes &clientes, long int cedula_cliente);

// Devuelve true si el abb clientes est� vac�o
boolean abb_cliente_es_vacio(abb_clientes clientes);

// devuelve true si la c�dula dada existe
boolean existe_cedula(abb_clientes clientes, long int cedula);

#endif // ABB_CLIENTES_H_INCLUDED
