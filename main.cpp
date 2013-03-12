#include <cstdlib>

#include "parser.h"
#include "archivos.h"
#include "lista_facturas.h"
#include "arreglo_lineas.h"
#include "abb_clientes.h"
#include "abb_productos.h"

void crear_cliente(arreglo_string params, abb_clientes &clientes, error &err);
void crear_producto(arreglo_string params, abb_productos &productos, error &err);
void listar_clientes(abb_clientes clientes);
void listar_productos(abb_productos productos);

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
    //
    abb_productos productos;
    crear_abb_productos(productos);

    //
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
                    error_cliente = COMANDO_VALIDO;
                    crear_cliente(parametros, clientes, error_cliente);

                    if (error_cliente == FORMATO_INCORRECTO || error_cliente == ERROR_DE_SINTAXIS)
                        printf("Cliente no fue creado.");
                    else
                        printf("Cliente creado exitosamente.");
                    break;

                case CREAR_PRODUCTO:
                    error error_producto;
                    error_producto = COMANDO_VALIDO;
                    crear_producto(parametros, productos, error_producto);

                    if (error_producto == FORMATO_INCORRECTO || error_producto == ERROR_DE_SINTAXIS)
                        printf("Producto no fue creado.");
                    else
                        printf("Producto creado exitosamente.");
                    break;

                case LISTAR_CLIENTES:
                    listar_clientes(clientes);
                    break;

                case LISTAR_PRODUCTOS:
                    listar_productos(productos);
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
//   [2] = nombre cliente
void crear_cliente(arreglo_string params, abb_clientes &clientes, error &err) {
    if (comparar_cant_params_por_comando(CREAR_CLIENTE, params.tope) == TRUE) {
        // validar cedula de tipo entero y nombre string valido
        if (validar_formato_entero(params.arre[1]) == TRUE &&
            validar_formato_string(params.arre[2]) == TRUE) {
            cliente nuevo_cliente;

            nuevo_cliente.cedula = atoi(params.arre[1]);
            nuevo_cliente.nombre = params.arre[2];

            abb_insertar_cliente(clientes, nuevo_cliente);
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}

// parametros
//   [0] = comando
//   [1] = codigo
//   [2] = nombre producto
void crear_producto(arreglo_string params, abb_productos &productos, error &err) {
    if (comparar_cant_params_por_comando(CREAR_PRODUCTO, params.tope) == TRUE) {
        if (validar_formato_entero(params.arre[1]) == TRUE &&
            validar_formato_string(params.arre[2]) == TRUE) {
            producto nuevo_producto;

            nuevo_producto.codigo = atoi(params.arre[1]);
            nuevo_producto.nombre = params.arre[2];

            abb_insertar_producto(productos, nuevo_producto);
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}

void listar_clientes(abb_clientes clientes) {
    if (clientes != NULL)
    {
        listar_clientes(clientes->nodo_izquierda);

        printf("%i - ", obtener_cedula_cliente(clientes->cli));

        string nombre_cliente;
        obtener_nombre_cliente(clientes->cli, nombre_cliente);
        desplegar_string(nombre_cliente);
        printf("\n");

        listar_clientes(clientes->nodo_derecha);
    }
}

void listar_productos(abb_productos productos) {
    if (productos != NULL)
    {
        listar_productos(productos->nodo_izquierda);

        printf("%i - ", obtener_codigo_producto(productos->prod));

        string nombre_producto;
        obtener_nombre_producto(productos->prod, nombre_producto);
        desplegar_string(nombre_producto);
        printf("\n");

        listar_productos(productos->nodo_derecha);
    }
}
