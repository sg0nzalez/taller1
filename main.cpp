#include "parser.h"
#include "archivo.h"
#include "lista_facturas.h"

int main() {

    int precioNegativo = -2;
    int precioPositivo = 0;

    boolean esPositivo = validar_precio(precioNegativo);

    if(esPositivo == FALSE) {
        printf("\nEL PRECIO INGRESADO NO ES CORRECTO. VALIDACION CORRECTA\n");
    } else {
        printf("\nVALIDACION DEL PRECIO INCORRECTA\n");
    }

    esPositivo = validar_precio(precioPositivo);

    if(esPositivo) {
        printf("\nEL PRECIO INGRESADO ES CORRECTO. VALIDACION CORRECTA\n");
    } else {
        printf("\nVALIDACION DEL PRECIO INCORRECTA\n");
    }

    linea lineaPrueba;

    int codigo = 10;
    int cant_prod = 5;
    float precio = 299;

    float linea_importe = cant_prod * precio;
    float linea_iva = linea_importe * IVA;
    float importe_total = linea_importe + linea_iva;

    lineaPrueba.codigo_producto = codigo;
    lineaPrueba.cant_productos = cant_prod;
    lineaPrueba.precio_unitario = precio;

    if(obtener_codigo_producto_linea(lineaPrueba)==codigo) {
        printf("\nEL CODIGO DEL PRODUCTO OBTENIDO ES CORRECTO\n");
    } else {
        printf("\nEL CODIGO DEL PRODUCTO OBTENIDO ES INCORRECTO\n");
    }

    if(obtener_cantidad_productos_linea(lineaPrueba)==cant_prod) {
        printf("\nLA CANTIDAD DE PRODUCTOS OBTENIDA ES LA CORRECTA\n");
    } else {
        printf("\nLA CANTIDAD DE PRODUCTOS OBTENIDA ES INCORRECTA\n");
    }

    if(obtener_precio_unitario_linea(lineaPrueba)==precio) {
        printf("\nEL PRECIO OBTENIDO ES EL CORRECTO\n");
    } else {
        printf("\nEL PRECIO OBTENIDO ES INCORRECTO\n");
    }

    if(importe_linea(lineaPrueba)==linea_importe) {
        printf("\nEL IMPORTE CALCULADO ES CORRECTO\n");
    } else {
        printf("\nEL IMPORTE CALCULADO ES INCORRECTO\n");
    }

    printf("\nHAY DIFERENCIAS EN LOS VALORES DESPUES DE LA COMA, POR ESO LA COMPARACION ENTRE LOS VALORES NO ES CORRECTA PERO SE PUEDE APRECIAR QUE CON SOLAMENTE DOS DIGITOS DESPUES DE LA COMA LOS RESULTADOS SON IGUALES\n");

    printf("\nIVA CALC = %.2f\n", iva_linea(lineaPrueba));
    printf("\nIVA = %.2f\n", linea_iva);

    if(iva_linea(lineaPrueba)==linea_iva) {
        printf("\nEL IVA CALCULADO ES CORRECTO\n");
    } else {
        printf("\nEL IVA CALCULADO ES INCORRECTO\n");
    }
    printf("\nIMPORTE CALC= %.2f\n", importe_total_linea(lineaPrueba));
    printf("\nIMPORTE = %.2f\n", importe_total);

    if(importe_total_linea(lineaPrueba)==importe_total) {
        printf("\nEL IMPORTE TOTAL CACULADO ES CORRECTO\n");
    } else {
        printf("\nEL IMPORTE TOTAL CACULADO ES INCORRECTO\n");
    }

}
