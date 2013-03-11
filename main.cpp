#include "parser.h"
#include "archivos.h"
#include "lista_facturas.h"
#include "arreglo_lineas.h"
#include "abb_clientes.h"
#include "abb_productos.h"

void crear_cliente(arreglo_string params, abb_clientes &clientes, error &err);

int main() {

    /*
    abb_clientes clientes = NULL;

    levantar_abb_cliente(clientes);


    string prueba;
    cargar_string(prueba);

    boolean valido = validar_nombre_archivo(prueba);

    if(valido) {
        printf("\nEL NOMBRE DEL ARCHIVO ES CORRECTO\n");
    } else {
        printf("\nEL NOMBRE DEL ARCHIVO NO ES CORRECTO\n");
    }

    boolean existeArchivo = existe_archivo(prueba);

    if(existeArchivo) {
        printf("\nEL ARCHIVO EXISTE\n");
    } else {
        printf("\nEL ARCHIVO NO EXISTE\n");
    }

}
    */
    // crear los abb de clientes y productos
    abb_clientes clientes;
    crear_abb_clientes(clientes);

    // crear variables para errores, comandos, etc
    string usuario_string;
    arreglo_string parametros;

    error error_obtenido;
    comando comando_obtenido;

    printf("Ingrese comando: ");
    cargar_string(usuario_string);

    parsear_comando(usuario_string, parametros, comando_obtenido, error_obtenido);

    while (comando_obtenido != EXIT) {
        destruir_string(usuario_string);

        if (error_obtenido == COMANDO_VALIDO) {
            switch (comando_obtenido) {
                case HELP:
                    listar_comandos();
                    break;

                case CREAR_CLIENTE:
                    error error_cliente;
                    crear_cliente(parametros, clientes, error_cliente);

                    if (error_cliente == FORMATO_INCORRECTO || error_cliente == ERROR_DE_SINTAXIS )
                        printf("Cliente no fue creado.");
                    else
                        printf("Cliente creado exitosamente.");
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
            }
        } else {
            printf("\nComando Invalidoo\n");
        }

        printf("\nIngrese comando: ");
        cargar_string(usuario_string);
        parsear_comando(usuario_string, parametros, comando_obtenido, error_obtenido);
    }

    printf("ADIOS :D");
}

// parametros
//   [0] = comando
//   [1] = cedula
//   [2] = nombre producto

void crear_cliente(arreglo_string params, abb_clientes &clientes, error &err) {
    if (comparar_cant_params_por_comando(CREAR_CLIENTE, params.tope) == TRUE) {
        // validar cedula de tipo entero y nombre string valido
        if (validar_formato_entero(params.arre[1]) == TRUE &&
            validar_formato_string(params.arre[2]) == TRUE) {
            cliente nuevo_cliente;

            nuevo_cliente.cedula = 222;
            nuevo_cliente.nombre = params.arre[2];

            abb_insertar_cliente(clientes, nuevo_cliente);
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}

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

       printf("\nIngrese comando: ");
        cargar_string(usuario_string);
        parsear_comando(usuario_string, parametros, comando_obtenido, error_obtenido);
    }

    printf("ADIOS :D");
}*/

// parametros
//   [0] = comando
//   [1] = cedula
//   [2] = nombre producto
