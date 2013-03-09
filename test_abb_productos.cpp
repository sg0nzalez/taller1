/*

abb_productos productos;

crear_abb_productos(productos);

producto prod;
producto prod2;

prod.codigo = 133;
prod.nombre = "Pelota";

abb_insertar_producto(productos, prod);

boolean esVacio = abb_producto_es_vacio(productos);

if(esVacio) {
    printf("\nEL ABB DE PRODUCTOS ESTA VACIO\n");
} else {
    printf("\nEL ABB DE PRODUCTOS NO ESTA VACIO\n");
}

boolean existeCodigo = abb_existe_codigo(productos, 133);

if(existeCodigo) {
    printf("\nEL PRODUCTO BUSCADO EXISTE\n");
} else {
    printf("\nEL PRODUCTO BUSCADO NO EXISTE\n");
}

prod2 = abb_buscar_producto(productos, 133);

if(prod2.codigo==prod.codigo && comparar_2_strings(prod.nombre, prod2.nombre)==TRUE) {
    printf("\nEL PRODUCTO DEVUELTO ES EL CORRECTO\n");
}

printf("\nEL PRODUCTO BUSCADO ES EL SIG: \n");
printf("\nCODIGO = %d\n", prod2.codigo);
printf("\nNOMBRE = ");
desplegar_string(prod2.nombre);

*/
