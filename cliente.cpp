#include "cliente.h"

long int obtener_cedula_cliente(cliente cli) {
    return cli.cedula;
}

void obtener_nombre_cliente(cliente cli, string &nom) {
    copiar_string(nom, cli.nombre);
}
