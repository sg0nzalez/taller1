#include "abb_clientes.h"

// crea el abb
void crear_abb_clientes(abb_clientes &clientes){
    clientes = NULL;
}

// inserta el cliente en el abb
void abb_insertar_cliente(abb_clientes &clientes, cliente cli){
    if (clientes == NULL) {
        clientes = new nodo_abb_clientes;
        clientes->cli = cli;
        clientes->nodo_izquierda = NULL;
        clientes->nodo_derecha = NULL;
    } else {
        if (obtener_cedula_cliente(cli) < obtener_cedula_cliente(clientes->cli)) {
            abb_insertar_cliente(clientes->nodo_izquierda, cli);
        }
        else {
            abb_insertar_cliente(clientes->nodo_derecha, cli);
        }
    }
}

// precondicion: debe existir un cliente con la cedula dada
//
// busca un cliente en el abb y lo devuelve
cliente abb_buscar_cliente(abb_clientes clientes, long int cedula_cliente){

    if (cedula_cliente == obtener_cedula_cliente(clientes->cli))
    {
        return clientes->cli;
    }
    else
    {
        if (cedula_cliente < obtener_cedula_cliente(clientes->cli))
        {
            return abb_buscar_cliente(clientes->nodo_izquierda, cedula_cliente);
        }
        else
        {
            return abb_buscar_cliente(clientes->nodo_derecha, cedula_cliente);
        }
    }
}

// Devuelve true si el abb clientes está vacío
boolean abb_cliente_es_vacio(abb_clientes clientes){

    return (boolean)(clientes == NULL);
}

// devuelve true si la cédula dada existe
boolean abb_existe_cliente(abb_clientes clientes, long int cedula){

    boolean es_vacio = abb_cliente_es_vacio(clientes);

    if(es_vacio==FALSE){
        if (cedula == obtener_cedula_cliente(clientes->cli)) {
            return TRUE;
        }
        else {
            if (cedula < obtener_cedula_cliente(clientes->cli)) {
                return abb_existe_cliente(clientes->nodo_izquierda, cedula);
            }
            else {
                return abb_existe_cliente(clientes->nodo_derecha, cedula);
            }
        }

        return FALSE;
    } else {
        return FALSE;
    }
}
