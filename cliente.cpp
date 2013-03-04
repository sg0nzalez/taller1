#include "cliente.h"

long int obtener_cedula_cliente(cliente cli) {
    return cli.cedula;
}

void modificar_cedula_cliente(cliente &cli, long int cedula) {
    cli.cedula = cedula;
}

void obtener_nombre_cliente(cliente cli, string &nombre) {
    copiar_string(nombre, cli.nombre);
}

void modificar_nombre_cliente(cliente &cli, string nombre) {

    copiar_string(cli.nombre, nombre);
}
