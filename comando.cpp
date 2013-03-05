#include "comando.h"

void listar_comandos() {
    printf("\t+ help\n");
    printf("\t+ crearcliente\n");
    printf("\t+ crearproducto\n");
    printf("\t+ listarclientes\n");
    printf("\t+ listarproductos\n");
    printf("\t+ crearfactura\n");
    printf("\t+ agregarlinea\n");
    printf("\t+ confirmarfactura\n");
    printf("\t+ load\n");
    printf("\t+ exit\n");
}

boolean validar_comando(string comando_a_validar) {
    if (comparar_2_strings(comando_a_validar, "help") ||
        comparar_2_strings(comando_a_validar, "crearcliente") ||
        comparar_2_strings(comando_a_validar, "crearproducto") ||
        comparar_2_strings(comando_a_validar, "listarclientes") ||
        comparar_2_strings(comando_a_validar, "listarproductos") ||
        comparar_2_strings(comando_a_validar, "crearfactura") ||
        comparar_2_strings(comando_a_validar, "agregarlinea") ||
        comparar_2_strings(comando_a_validar, "confirmarfactura") ||
        comparar_2_strings(comando_a_validar, "load") ||
        comparar_2_strings(comando_a_validar, "exit")) {
        return TRUE;
    }

    return FALSE;
}

comando obtener_comando(string comando_string) {
    if (comparar_2_strings(comando_string, "help") == TRUE) {
        return HELP;
    } else if (comparar_2_strings(comando_string, "crearcliente") == TRUE) {
        return CREAR_CLIENTE;
    } else if (comparar_2_strings(comando_string, "crearproducto") == TRUE) {
        return LISTAR_CLIENTES;
    } else if (comparar_2_strings(comando_string, "listarclientes") == TRUE) {
        return LISTAR_PRODUCTOS;
    } else if (comparar_2_strings(comando_string, "listarproductos") == TRUE) {
        return CREAR_FACTURA;
    } else if (comparar_2_strings(comando_string, "crearfactura") == TRUE) {
        return CREAR_FACTURA;
    } else if (comparar_2_strings(comando_string, "agregarlinea") == TRUE) {
        return AGREGAR_LINEA;
    } else if (comparar_2_strings(comando_string, "confirmarfactura") == TRUE) {
        return CONFIRMAR_FACTURA;
    } else if (comparar_2_strings(comando_string, "load") == TRUE) {
        return LOAD;
    } else if (comparar_2_strings(comando_string, "exit") == TRUE) {
        return EXIT;
    }
}
