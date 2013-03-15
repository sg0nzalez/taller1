#ifndef ABB_CLIENTES_H_INCLUDED
#define ABB_CLIENTES_H_INCLUDED

#include "cliente.h"

typedef struct nodo_cliente {
    cliente cli;
    nodo_cliente *nodo_izquierda;
    nodo_cliente *nodo_derecha;
} nodo_abb_clientes;

typedef nodo_abb_clientes *abb_clientes;

// crea el abb
void crear_abb_clientes(abb_clientes &clientes);

// precondicion: la cedula no debe existir del usuario dado
//
// inserta el cliente en el abb
void abb_insertar_cliente(abb_clientes &clientes, cliente cli);

// precondicion: debe existir un cliente con la cedula dada
//
// busca un cliente en el abb y lo devuelve
cliente abb_buscar_cliente(abb_clientes clientes, long int cedula_cliente);

// imprime en pantalla todos los clientes del abb
void listar_clientes(abb_clientes clientes);

// Devuelve true si el abb clientes está vacío
boolean abb_cliente_es_vacio(abb_clientes clientes);

// devuelve true si la cédula dada existe
boolean abb_existe_cliente(abb_clientes clientes, long int cedula);

#endif // ABB_CLIENTES_H_INCLUDED
