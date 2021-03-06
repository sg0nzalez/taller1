#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

typedef enum {
    ARCHIVO_INEXISTENTE,
    COMANDO_INVALIDO,
    COMANDO_VALIDO,
    FORMATO_INCORRECTO,
    FORMATO_CORRECTO,
    ERROR_DE_SINTAXIS,
    CODIGO_EXISTENTE,
    CODIGO_INEXISTENTE,
    CEDULA_EXISTENTE,
    CEDULA_INEXISTENTE,
    FACTURA_EXISTENTE,
    FACTURA_INEXISTENTE,
    FACTURA_CONFIRMADA,
    FACTURA_CANT_LINEAS_ERROR,
    FACTURA_CANT_LINEAS_VALIDO,
    ENTERO_VALIDO,
    ENTERO_INVALIDO,
    STRING_INVALIDO,
    STRING_VALIDO
} error;

#endif // ERROR_H_INCLUDED
