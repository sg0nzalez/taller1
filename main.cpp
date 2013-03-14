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
void crear_linea(arreglo_string params, lista_facturas &facturas, factura &factura_asociada, abb_productos productos, error &err);
void desplegar_factura(arreglo_string params, lista_facturas facturas, abb_productos productos, abb_clientes clientes, error &err);
void confirmar_factura(arreglo_string params, lista_facturas &facturas, factura &factura_asociada, error &err);
void guardar_archivo(arreglo_string params, abb_clientes clientes, abb_productos productos, error &err);
void cargar_archivo(arreglo_string params, abb_clientes clientes, abb_productos productos, error &err);

int main() {
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
                    factura factura_asociada;

                    crear_linea(parametros, facturas, factura_asociada, productos, error_obtenido);

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
                    case FACTURA_CANT_LINEAS_ERROR:
                        printf("Se llego al limite de lineas(10).");
                        break;
                    case ENTERO_INVALIDO:
                        printf("Precio y Cantidad deben ser positivos.");
                        break;
                    case CODIGO_INEXISTENTE:
                        printf("No exitse un producto con el codigo ingresado.");
                        break;
                    case FACTURA_INEXISTENTE:
                        printf("La factura ingresada no exitse.");
                        break;
                    case FACTURA_CONFIRMADA:
                        printf("La factura ingresada esta confirmada.");
                        break;
                    default:
                        printf("Linea agregada a Factura de Venta nro: %i.", obtener_numero_factura(nueva_factura));
                    }
                    break;
                case DESPLEGAR_FACTURA:
                    desplegar_factura(parametros, facturas, productos, clientes, error_obtenido);

                    switch(error_obtenido) {
                    case FORMATO_INCORRECTO:
                        printf("Parametro con formato incorrecto.");
                        break;
                    case ERROR_DE_SINTAXIS:
                        printf("Cantidad de parametros erronea.");
                        break;
                    case FACTURA_INEXISTENTE:
                        printf("La factura no existe en el sistema.");
                        break;
                    }
                    break;
                case CONFIRMAR_FACTURA:
                    factura factura_a_confirmar;
                    confirmar_factura(parametros, facturas, factura_a_confirmar, error_obtenido);

                    switch(error_obtenido) {
                    case FORMATO_INCORRECTO:
                        printf("Parametro con formato incorrecto.");
                        break;
                    case ERROR_DE_SINTAXIS:
                        printf("Cantidad de parametros erronea.");
                        break;
                    case FACTURA_INEXISTENTE:
                        printf("La factura no existe en el sistema.");
                        break;
                    default:
                        printf("Factura de Venta nro: %i confirmada.", obtener_numero_factura(factura_a_confirmar));
                    }
                    break;
                case SAVE:
                    guardar_archivo(parametros, clientes, productos, error_obtenido);

                    switch(error_obtenido) {
                        case ERROR_DE_SINTAXIS:
                            printf("Cantidad de parametros erronea.");
                            break;
                        case FORMATO_INCORRECTO:
                            printf("Parametro con formato incorrecto.");
                        break;
                        default:
                            printf("Archivo guardado exitosamente");
                    }
                    break;
                case LOAD:
                    cargar_archivo(parametros, clientes, productos, error_obtenido);

                    switch(error_obtenido) {
                        case ERROR_DE_SINTAXIS:
                            printf("Cantidad de parametros erronea.");
                            break;
                        case ARCHIVO_INEXISTENTE:
                            printf("El archivo no existe en el sistema.");
                            break;
                        case FORMATO_INCORRECTO:
                            printf("Parametro con formato incorrecto.");
                            break;
                        default:
                            printf("Archivo cargado exitosamente");
                    }
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

    printf("Hasta la proxima.");
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
            lineas.tope = 0;

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

// parametros
//   [0] = comando
//   [1] = numero factura
//   [2] = numero producto
//   [3] = cantidad producto
//   [4] = precio unitario
void crear_linea(arreglo_string params, lista_facturas &facturas, factura &factura_asociada, abb_productos productos, error &err) {
    if (comparar_cant_params_por_comando(AGREGAR_LINEA, params.tope) == TRUE) {
        if (validar_formato_entero(params.arre[1]) == TRUE &&
            validar_formato_entero(params.arre[2]) == TRUE &&
            validar_formato_entero(params.arre[3]) == TRUE &&
            validar_formato_entero(params.arre[4]) == TRUE) {

            int numero_factura = atoi(params.arre[1]);
            int numero_producto = atoi(params.arre[2]);
            int cantidad_productos = atoi(params.arre[3]);
            int precio_producto = atoi(params.arre[4]);

            if (existe_numero_factura(facturas, numero_factura) == TRUE) {
                factura_asociada = obtener_factura(facturas, numero_factura);

                if (abb_existe_codigo(productos, numero_producto) == TRUE) {
                    if (validar_precio(precio_producto) == TRUE &&
                        validar_cantidad_productos(cantidad_productos) == TRUE) {
                        arreglo_lineas lineas;
                        obtener_arreglo_lineas_factura(factura_asociada, lineas);

                        if (obtener_arreglo_lineas_tope(lineas) < 10) {
                            if (obtener_estado_factura(factura_asociada) == TRUE) {
                                linea nueva_linea;

                                nueva_linea.cant_productos = cantidad_productos;
                                nueva_linea.codigo_producto = numero_producto;
                                nueva_linea.precio_unitario = precio_producto;

                                agregar_linea_al_arreglo(lineas, nueva_linea);
                                modificar_arreglo_lineas_factura(factura_asociada, lineas);

                                modificar_factura(facturas, factura_asociada);
                            } else {
                                err = FACTURA_CONFIRMADA;
                            }
                        } else {
                            err = FACTURA_CANT_LINEAS_ERROR;
                        }
                    } else {
                        err = ENTERO_INVALIDO;
                    }
                } else {
                    err = CODIGO_INEXISTENTE;
                }
            } else {
                err = FACTURA_INEXISTENTE;
            }
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}

void desplegar_factura(arreglo_string params, lista_facturas facturas, abb_productos productos, abb_clientes clientes, error &err) {
    if (comparar_cant_params_por_comando(DESPLEGAR_FACTURA, params.tope) == TRUE) {
        if (validar_formato_entero(params.arre[1]) == TRUE) {
            int numero_factura = atoi(params.arre[1]);

            if (existe_numero_factura(facturas, numero_factura) == TRUE) {
                factura factura_asociada = obtener_factura(facturas, numero_factura);
                cliente factura_cliente = abb_buscar_cliente(clientes, obtener_cedula_cliente_factura(factura_asociada));

                printf("Factura Venta nro: %i\n", obtener_numero_factura(factura_asociada));

                printf("Cliente: %i - ", obtener_cedula_cliente(factura_cliente));

                string nombre_cliente;
                obtener_nombre_cliente(factura_cliente, nombre_cliente);
                desplegar_string(nombre_cliente);
                printf("\n");

                if (obtener_estado_factura(factura_asociada) == TRUE) {
                    printf("Estado: Pendiente");
                } else {
                    printf("Estado: Confirmada");
                }

                printf("\n%-5s%-10s%-20s%-10s%-10s%-10s%-10s\n", "Cant", "Codigo", "Producto", "Unitario", "Importe", "IVA", "Total");
                printf("-----------------------------------------------------------------------------");

                for (int i = 0; i < obtener_arreglo_lineas_tope(factura_asociada.lineas_factura); i++) {
                    linea linea_actual = factura_asociada.lineas_factura.lineas[i];
                    producto producto_linea = abb_buscar_producto(productos, linea_actual.codigo_producto);
                    string nombre_producto;

                    obtener_nombre_producto(producto_linea, nombre_producto);

                    printf("\n%-5i%-10i%-20s%-10i$%-10f$%-10f$%-10f\n",
                           obtener_cantidad_productos_linea(linea_actual),
                           obtener_codigo_producto_linea(linea_actual),
                           nombre_producto,
                           obtener_precio_unitario_linea(linea_actual),
                           importe_linea(linea_actual),
                           iva_linea(linea_actual),
                           importe_total_linea(linea_actual));

                    destruir_string(nombre_producto);
                }

                printf("Importe: $%f\n", importe_arreglo_lineas(factura_asociada.lineas_factura));
                printf("IVA: $%f\n", iva_arreglo_lineas(factura_asociada.lineas_factura));
                printf("Total: $%f", importe_total_arreglo_lineas(factura_asociada.lineas_factura));
            } else {
                err = FACTURA_INEXISTENTE;
            }
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}

void confirmar_factura(arreglo_string params, lista_facturas &facturas, factura &factura_asociada, error &err) {
    if (comparar_cant_params_por_comando(DESPLEGAR_FACTURA, params.tope) == TRUE) {
        if (validar_formato_entero(params.arre[1]) == TRUE) {
            int numero_factura = atoi(params.arre[1]);

            if (existe_numero_factura(facturas, numero_factura) == TRUE) {
                factura_asociada = obtener_factura(facturas, numero_factura);
                factura_asociada.estado_pendiente = FALSE;

                modificar_factura(facturas, factura_asociada);
            } else {
                err = FACTURA_INEXISTENTE;
            }
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}

void guardar_archivo(arreglo_string params, abb_clientes clientes, abb_productos productos, error &err) {
    if (comparar_cant_params_por_comando(SAVE, params.tope) == TRUE) {
        if(validar_nombre_archivo(params.arre[1]) == TRUE) {
            bajar_abb(clientes, productos, params.arre[1]);
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}

void cargar_archivo(arreglo_string params, abb_clientes clientes, abb_productos productos, error &err) {
    if (comparar_cant_params_por_comando(LOAD, params.tope) == TRUE) {
        if(validar_nombre_archivo(params.arre[1]) == TRUE) {
            if(existe_archivo(params.arre[1]) == TRUE) {
                crear_abb_clientes(clientes);
                crear_abb_productos(productos);

                levantar_abb(clientes, productos, params.arre[1]);
            } else {
                err = ARCHIVO_INEXISTENTE;
            }
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }
}
