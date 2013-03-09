#include "parser.h"
#include "archivo.h"
#include "lista_facturas.h"
#include "arreglo_lineas.h"
#include "abb_clientes.h"
#include "abb_productos.h"

int main() {

/*
//TEST FACTURA
factura fac;

fac.numero = 1;
fac.cedula_cliente = 34905341;
fac.estado_pendiente = TRUE;

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

// asigna el arreglo de lineas de la factura dada al arreglo_lineas dado
//void obtener_arreglo_lineas_factura(factura fac, arreglo_lineas &lineas);

*/
/*
    string com;
    error err;
    comando coman;
    arreglo_string arr_str;

    printf("comando: ");
    cargar_string(com);
    parsear_comando(com, arr_str, coman, err);

    while (coman != EXIT) {
        destruir_string(com);

        if (err == COMANDO_VALIDO) {
            switch (coman) {
                case HELP:
                    listar_comandos();
                    break;
                case CREAR_CLIENTE:
                    printf("\ncrear cliente\n");
                    break;
                case CREAR_PRODUCTO:
                    printf("\ncrear producto\n");
                    break;
                case LISTAR_CLIENTES:
                    printf("\nlistar clientes\n");
                    break;
                case LISTAR_PRODUCTOS:
                    printf("\nlistar productos\n");
                    break;
                case CREAR_FACTURA:
                    printf("\ncrear factura\n");
                    break;
                case AGREGAR_LINEA:
                    printf("\nagregar linea\n");
                    break;
                case CONFIRMAR_FACTURA:
                    printf("\nconfirmar factura\n");
                    break;
                case LOAD:
                    printf("\nload\n");
                    break;
                case EXIT:
                    printf("\nADIOS :D");
                    break;
            }
        } else {
            printf("\nCOMANDo INVALIdo\n");
        }

        printf("comando: ");
        cargar_string(com);
        parsear_comando(com, arr_str, coman, err);
    }

    printf("ADIOS :D");
*/
}
