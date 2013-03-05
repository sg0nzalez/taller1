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

// imprime los comandos disponibles
void listar_comandos();

// devuelve true si el comando dado es un comando valido
boolean validar_comando(string comando);

// precondici—n: debe ser un comando v‡lido (usar validar_comando)
// devuelve el comando
comando obtener_comando(string comando_string);

#endif // COMANDO_H_INCLUDED
