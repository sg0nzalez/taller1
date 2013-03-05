#include "parser.h"

void parsear_comando(string comando_string, arreglo_string &param, comando &com, error &err) {
    // obtener todos los parametros
    separar_por_espacio(comando_string, param);

    if (validar_comando(param.arre[0]) == TRUE) {
        err = COMANDO_VALIDO;
        com = obtener_comando(param.arre[0]);
    } else {
        err = COMANDO_INVALIDO;
    }
}

boolean comparar_cant_params_por_comando(comando com, int cant_param) {
    if (com == HELP && cant_param > 1) {
        return FALSE;
    } else if (com == LOAD && cant_param > 1) {
        return FALSE;
    } else if (com == EXIT && cant_param > 1) {
        return FALSE;
    }

    return TRUE;
}

int convertir_string_a_entero(string str, error &err) {

}

boolean validar_formato_string(string string_a_chequear, error &err) {

}

boolean validar_formato_entero(string string_a_chequear, error &err) {

}
