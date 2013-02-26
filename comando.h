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
    CONFIRMAR_FACTURA,
    SAVE,
    LOAD,
    EXIT
} comando;

#endif // COMANDO_H_INCLUDED
