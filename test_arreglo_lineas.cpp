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

int importe_arre_lineas = (5*9) + (3*11);

if(importe_arre_lineas==importe_arreglo_lineas(lineas)){
    printf("\nEL IMPORTE DE LA FACTURA SIN IVA ES CORRECTO\n");
} else {
    printf("\nEL IMPORTE DE LA FACTURA SIN IVA NO ES CORRECTO\n");
}

if(validar_cant_lineas) {
    printf("\nEXISTEN MENOS DE 10 LINEAS EN EL ARREGLO. CORRECTO\n");
} else {
    printf("\nEXISTEN MENOS DE 10 LINEAS EN EL ARREGLO. INCORRECTO\n");
}
int iva_linea1 = (5*9)*IVA;
int iva_linea2 = (3*11)*IVA;

int iva_factura = iva_linea1 + iva_linea2;

if(iva_arreglo_lineas(lineas)==iva_factura){
    printf("\nEL IMPORTE DE LA FACTURA ES CORRECTO\n");
} else {
    printf("\nEL IMPORTE DE LA FACTURA NO ES CORRECTO\n");
}

if(importe_total_arreglo_lineas(lineas)==importe_arre_lineas + iva_factura){
    printf("\nEL IMPORTE TOTAL DE LA FACTURA ES CORRECTO\n");
} else {
    printf("\nEL IMPORTE TOTAL DE LA FACTURA NO ES CORRECTO\n");
}

int cant_lineas = 2;

if(obtener_arreglo_lineas_tope(lineas)==cant_lineas){
    printf("\nEL TOPE DEL ARREGLO ES CORRECTO\n");
} else {
    printf("\nEL TOPE DEL ARREGLO NO ES CORRECTO\n");
}
*/
