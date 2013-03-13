#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include "arreglo_string.h"

typedef enum {
    HELP,
    CREAR_CLIENTE,
    CREAR_PRODUCTO,
    LISTAR_CLIENTES,
    LISTAR_PRODUCTOS,
    CREAR_FACTURA,
    AGREGAR_LINEA,
    DESPLEGAR_FACTURA,
    CONFIRMAR_FACTURA,
    SAVE,
    LOAD,
    EXIT
} comando;

// imprime los comandos disponibles
void listar_comandos();

#endif // COMANDO_H_INCLUDED
