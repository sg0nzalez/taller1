/*
    // abb de clientes
    abb_clientes clientes;
    abb_clientes clientes2;
    crear_abb_clientes(clientes);
    crear_abb_clientes(clientes2);

    // abb de productos
    abb_productos productos;
    abb_productos productos2;
    crear_abb_productos(productos);
    crear_abb_productos(productos2);

    cliente cli;
    cliente cli2;
    cliente cli3;

    producto prod;
    producto prod2;
    producto prod3;

    cli.cedula = 34905341;
    cli.nombre = "Tony_the_Fat";

    cli2.cedula = 234566781;
    cli2.nombre = "Enzo";

    cli3.cedula = 12345555;
    cli3.nombre = "Peteco_Carbajal";

    prod.codigo = 1;
    prod.nombre = "Bombones Garoto";

    prod2.codigo = 2;
    prod2.nombre = "Chicles";

    prod3.codigo = 3;
    prod3.nombre = "Caramelos";

    abb_insertar_cliente(clientes2, cli);
    abb_insertar_cliente(clientes2, cli2);
    abb_insertar_cliente(clientes2, cli3);

    abb_insertar_producto(productos2, prod);
    abb_insertar_producto(productos2, prod2);
    abb_insertar_producto(productos2, prod3);

    bajar_abb(clientes2, productos2, "prodCli.dat");
    levantar_abb(clientes, productos, "prodCli.dat");

    if (existe_archivo("prodCli.dat") == TRUE) {
        printf("\nEL ARCHIVO EXISTE\n");
    } else {
        printf("\nEL ARCHIVO NO EXISTE\n");
    }

    printf("\nCLIENTES\n");
    listar_clientes(clientes);
    printf("\n\nPRODUCTOS\n");
    listar_productos(productos);
*/
