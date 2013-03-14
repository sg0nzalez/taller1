#include "parser.h"

void parsear_comando(string comando_string, arreglo_string &arr_params, comando &com, error &err) {
    // obtener todos los parametros
    separar_por_espacio(comando_string, arr_params);

    // dado el primer parametro averiguar que comando fue ingresado
    obtener_comando(arr_params.arre[0], com, err);
}

boolean comparar_cant_params_por_comando(comando com, int cant_param) {
    if ((com == HELP && cant_param != 1) ||
        (com == CREAR_CLIENTE && cant_param != 3) ||
        (com == CREAR_PRODUCTO && cant_param != 3) ||
        (com == LISTAR_CLIENTES && cant_param != 1) ||
        (com == LISTAR_PRODUCTOS && cant_param != 1) ||
        (com == CREAR_FACTURA && cant_param != 2) ||
        (com == AGREGAR_LINEA && cant_param != 5) ||
        (com == DESPLEGAR_FACTURA && cant_param != 2) ||
        (com == CONFIRMAR_FACTURA && cant_param != 2) ||
        (com == SAVE && cant_param != 2) ||
        (com == LOAD && cant_param != 2) ||
        (com == EXIT && cant_param != 1)) {
        return FALSE;
    }

    return TRUE;
}

boolean validar_formato_string(string string_a_chequear) {
    int i = 0;

    while ((string_a_chequear[i] != '\0') && (i < MAX)) {
        if ((string_a_chequear[i] < 65 || string_a_chequear[i] > 90) &&
            (string_a_chequear[i] < 97 || string_a_chequear[i] > 122) &&
            (string_a_chequear[i] != 95))
            return FALSE;

        i++;
    }

    return TRUE;
}

boolean validar_formato_entero(string string_a_chequear) {
    int i = 0;

    while ((string_a_chequear[i] != '\0') && (i < MAX)) {
        if (string_a_chequear[i] < 48 || string_a_chequear[i] > 57)
            return FALSE;

        i++;
    }

    return TRUE;
}

void obtener_comando(string comando_string, comando &com, error &err) {
    err = COMANDO_VALIDO;

    if (comparar_2_strings(comando_string, "help") == TRUE) {
        com = HELP;
    } else if (comparar_2_strings(comando_string, "crearcliente") == TRUE) {
        com = CREAR_CLIENTE;
    } else if (comparar_2_strings(comando_string, "crearproducto") == TRUE) {
        com = CREAR_PRODUCTO;
    } else if (comparar_2_strings(comando_string, "listarclientes") == TRUE) {
        com = LISTAR_CLIENTES;
    } else if (comparar_2_strings(comando_string, "listarproductos") == TRUE) {
        com = LISTAR_PRODUCTOS;
    } else if (comparar_2_strings(comando_string, "crearfactura") == TRUE) {
        com = CREAR_FACTURA;
    } else if (comparar_2_strings(comando_string, "agregarlinea") == TRUE) {
        com = AGREGAR_LINEA;
    } else if (comparar_2_strings(comando_string, "desplegarfactura") == TRUE) {
        com = DESPLEGAR_FACTURA;
    } else if (comparar_2_strings(comando_string, "confirmarfactura") == TRUE) {
        com = CONFIRMAR_FACTURA;
    } else if (comparar_2_strings(comando_string, "save") == TRUE) {
        com = SAVE;
    } else if (comparar_2_strings(comando_string, "load") == TRUE) {
        com = LOAD;
    } else if (comparar_2_strings(comando_string, "exit") == TRUE) {
        com = EXIT;
    } else {
        err = COMANDO_INVALIDO;
    }
}
