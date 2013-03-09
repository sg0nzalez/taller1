/*



abb_clientes clientes;

crear_abb_clientes(clientes);

cliente cli;
cliente cli2;

cli.cedula = 34905341;
cli.nombre = "Peteco";

abb_insertar_cliente(clientes, cli);

boolean esVacio = abb_cliente_es_vacio(clientes);

if(esVacio) {
    printf("\nEL ABB DE CLIENTES ESTA VACIO\n");
} else {
    printf("\nEL ABB DE CLIENTES NO ESTA VACIO\n");
}

boolean existeCliente = abb_existe_cliente(clientes, 34905341);

if(existeCliente) {
    printf("\nEL CLIENTE EXISTE\n");
} else {
    printf("\nEL CLIENTE NO EXISTE\n");
}

cli2 = abb_buscar_cliente(clientes, cli.cedula);

printf("\nDEVUELVE EL CLIENTE BUSCADO\n");
printf("\nCEDULA = %d", cli2.cedula);
printf("\nNOMBRE = ");
desplegar_string(cli2.nombre);

*/
