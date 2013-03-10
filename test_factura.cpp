/*
linea lin1;
linea lin2;

lin1.codigo_producto = 1;
lin1.cant_productos = 5;
lin1.precio_unitario = 9;

lin2.codigo_producto = 2;
lin2.cant_productos = 3;
lin2.precio_unitario = 11;

arreglo_lineas lineas;
lineas.tope = 0;

agregar_linea_al_arreglo(lineas, lin1);
agregar_linea_al_arreglo(lineas, lin2);

factura fac;

fac.numero = 1;
fac.cedula_cliente = 34905341;
fac.estado_pendiente = TRUE;
fac.lineas_factura = lineas;

arreglo_lineas lineas2;
lineas.tope = 0;

int numFact = obtener_numero_factura(fac);

if(numFact==fac.numero){
    printf("\nEL NUMERO DE FACTURA OBTENIDO ES EL CORRECTO\n");
} else {
    printf("\nEL NUMERO DE FACTURA OBTENIDO NO ES EL CORRECTO\n");
}

int cedulaCliente = obtener_cedula_cliente_factura(fac);

if(cedulaCliente==fac.cedula_cliente){
    printf("\nLA CEDULA DEL CLIENTE ES CORRECTA\n");
} else {
    printf("\nLA CEDULA DEL CLIENTE NO ES CORRECTA\n");
}

boolean estFact = obtener_estado_factura(fac);

if(estFact==fac.estado_pendiente){
    printf("\nEL ESTADO DE LA FACTURA ES CORRECTO\n");
} else {
    printf("\nEL ESTADO DE LA FACTURA NO ES CORRECTO\n");
}

obtener_arreglo_lineas_factura(fac, lineas2);

int cant_lineas = 2;

if(obtener_arreglo_lineas_tope(lineas2)==cant_lineas){
    printf("\nEL TOPE DEL ARREGLO ES CORRECTO\n");
} else {
    printf("\nEL TOPE DEL ARREGLO NO ES CORRECTO\n");
}
*/
