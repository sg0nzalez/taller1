#include "parser.h"
#include "archivo.h"
#include "lista_facturas.h"
#include "abb_clientes.h"
#include "cliente.h"

int main() {

    cliente cli;

    cli.nombre = "Santiago";
    cli.cedula = 4511851;

    string nombre2 = "Tony";
    long int cedula2 = 34905341;

    string nombre_cliente;
    obtener_nombre_cliente(cli, nombre_cliente);

    printf("Debe retornar el nombre del cliente dado: \n");

    if (comparar_2_strings(nombre_cliente, cli.nombre) == TRUE)
        printf(" + PASO\n\n");
    else
        printf(" - FALLO\n\n");

    printf("Debe retornar el nombre modificado del cliente dado: \n");

    modificar_nombre_cliente(cli, nombre2);

    if (comparar_2_strings(cli.nombre, nombre2) == TRUE)
        printf(" + PASO\n\n");
    else
        printf(" - FALLO\n\n");

    printf("Debe retornar la cedula del cliente dado: \n");

    if (obtener_cedula_cliente(cli) == cli.cedula)
        printf(" + PASO\n\n");
    else
        printf(" - FALLO\n\n");


    printf("Debe retornar la cedula modificada del cliente dado: \n");

    modificar_cedula_cliente(cli, cedula2);

    if (obtener_cedula_cliente(cli) == cedula2)
        printf(" + PASO\n\n");
    else
        printf(" - FALLO\n\n");

/*
abb_clientes clientes;

crear_abb_clientes(clientes);

cliente cli;
cliente cli2;

cli.cedula = 34905341;

printf("\nIngrese el nombre: ");
cargar_string(cli.nombre);

desplegar_string(cli.nombre);
*/
/*
abb_insertar_cliente(clientes, cli);

boolean esVacio = abb_cliente_es_vacio(clientes);

boolean existeCliente = abb_existe_cliente(clientes, cli.cedula);

if(existeCliente) {
    printf("\nEL CLIENTE EXISTE\n");
} else {
    printf("\nEL CLIENTE NO EXISTE\n");
}

cli2 = abb_buscar_cliente(clientes, cli.cedula);

printf("\nCedula = %d", cli2.cedula);
printf("\nNombre = ");
desplegar_string(cli2.nombre);
*/
}
