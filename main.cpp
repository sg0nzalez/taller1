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
void crear_factura(arreglo_string params, lista_facturas &facturas, abb_clientes clientes, factura &nueva_factura, error &err);

int main() {

    // abb de clientes
/*    abb_clientes clientes;
    crear_abb_clientes(clientes);

    cliente cli;

    cli.cedula = 34905341;
    cli.nombre = "Peteco";

    abb_insertar_cliente(clientes, cli);

    // abb de productos
    abb_productos productos;
    crear_abb_productos(productos);

//    if (existe_archivo("clientes.txt") == FALSE)
//        bajar_abb_cliente(clientes, "clientes.txt");
//
//    if (existe_archivo("productos.txt") == FALSE)
//        bajar_abb_producto(productos, "productos.txt");

    bajar_abb_cliente(clientes, "clientes.dat");
    bajar_abb_producto(productos, "productos.dat");

    levantar_abb_cliente(clientes, "clientes.dat");
*/
/*
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

    // abb de clientes
    abb_clientes clientes;
    crear_abb_clientes(clientes);

    // abb de productos
    abb_productos productos;
    crear_abb_productos(productos);

    // lista de facturas
    lista_facturas facturas;
    crear_lista_factura(facturas);

    //
    string usuario_string;

    arreglo_string parametros;

    // setea el tope a 0
    crear_arreglo_string(parametros);

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
                    crear_cliente(parametros, clientes, error_obtenido);

                    switch(error_obtenido) {
                    case FORMATO_INCORRECTO:
                        printf("Parametro con formato incorrecto.");
                        break;
                    case ERROR_DE_SINTAXIS:
                        printf("Cantidad de parametros erronea.");
                        break;
                    case CEDULA_EXISTENTE:
                        printf("El usuario ya existe.");
                        break;
                    default:
                        printf("Cliente creado exitosamente.");
                    }
                    break;

                case CREAR_PRODUCTO:
                    crear_producto(parametros, productos, error_obtenido);

                    switch(error_obtenido) {
                    case FORMATO_INCORRECTO:
                        printf("Parametro con formato incorrecto.");
                        break;
                    case ERROR_DE_SINTAXIS:
                        printf("Cantidad de parametros erronea.");
                        break;
                    case CEDULA_EXISTENTE:
                        printf("El producto ya existe.");
                        break;
                    default:
                        printf("Producto creado exitosamente.");
                    }
                    break;

                case LISTAR_CLIENTES:
                    if (clientes != NULL) {
                    listar_clientes(clientes);
                    } else {
                        printf("No hay clientes disponibles.");
                    }
                    break;

                case LISTAR_PRODUCTOS:
                    if (productos != NULL) {
                        listar_productos(productos);
                    } else {
                        printf("No hay productos disponibles.");
                    }
                    break;

                case CREAR_FACTURA:

                    factura nueva_factura;

                    crear_factura(parametros, facturas, clientes, nueva_factura, error_obtenido);

                    switch(error_obtenido) {
                    case FORMATO_INCORRECTO:
                        printf("Parametro con formato incorrecto.");
                        break;
                    case ERROR_DE_SINTAXIS:
                        printf("Cantidad de parametros erronea.");
                        break;
                    case CEDULA_INEXISTENTE:
                        printf("La cedula no existe en el sistema.");
                        break;
                    default:
                        printf("Factura de Venta nro: %i creada.", obtener_numero_factura(nueva_factura));
                    }
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
            printf("Comando invalido.");

        }

        borrar_arreglo_string(parametros);
        crear_arreglo_string(parametros);

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

            if (abb_existe_cliente(clientes, obtener_cedula_cliente(nuevo_cliente)) == FALSE) {
                abb_insertar_cliente(clientes, nuevo_cliente);
            } else {
                err = CEDULA_EXISTENTE;
            }
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

            if (abb_existe_codigo(productos, obtener_codigo_producto(nuevo_producto)) == FALSE) {
                abb_insertar_producto(productos, nuevo_producto);
            } else {
                err = CEDULA_EXISTENTE;
            }
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}

void listar_clientes(abb_clientes clientes) {
    if (clientes != NULL) {
        listar_clientes(clientes->nodo_izquierda);

        if (clientes->nodo_izquierda != NULL)
            printf("\n");

        printf("%i - ", obtener_cedula_cliente(clientes->cli));

        string nombre_cliente;
        obtener_nombre_cliente(clientes->cli, nombre_cliente);
        desplegar_string(nombre_cliente);
        destruir_string(nombre_cliente);

        if (clientes->nodo_derecha != NULL)
            printf("\n");

        listar_clientes(clientes->nodo_derecha);
    }
}

void listar_productos(abb_productos productos) {
    if (productos != NULL) {
        listar_productos(productos->nodo_izquierda);

        if (productos->nodo_izquierda != NULL)
            printf("\n");

        printf("%i - ", obtener_codigo_producto(productos->prod));

        string nombre_producto;
        obtener_nombre_producto(productos->prod, nombre_producto);
        desplegar_string(nombre_producto);
        destruir_string(nombre_producto);

        if (productos->nodo_derecha != NULL)
            printf("\n");

        listar_productos(productos->nodo_derecha);
    }
}

void crear_factura(arreglo_string params, lista_facturas &facturas, abb_clientes clientes, factura &nueva_factura, error &err) {
    if (comparar_cant_params_por_comando(CREAR_FACTURA, params.tope) == TRUE) {
        if (validar_formato_entero(params.arre[1]) == TRUE) {
            arreglo_lineas lineas;

            nueva_factura.cedula_cliente = atoi(params.arre[1]);
            nueva_factura.estado_pendiente = TRUE;
            nueva_factura.lineas_factura = lineas;

            if (abb_existe_cliente(clientes, obtener_cedula_cliente_factura(nueva_factura)) == TRUE) {
                lista_insertar_factura(facturas, nueva_factura, 0);
            } else {
                err = CEDULA_INEXISTENTE;
            }
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}
