#include <cstdlib>

#include "archivos.h"
#include "parser.h"

void crear_cliente(arreglo_string params, abb_clientes &clientes, error &err);
void crear_producto(arreglo_string params, abb_productos &productos, error &err);
void crear_factura(arreglo_string params, lista_facturas &facturas, abb_clientes clientes, factura &nueva_factura, error &err);
void crear_linea(arreglo_string params, lista_facturas &facturas, factura &factura_asociada, abb_productos productos, error &err);
void desplegar_factura(arreglo_string params, lista_facturas facturas, abb_productos productos, abb_clientes clientes, error &err);
void confirmar_factura(arreglo_string params, lista_facturas &facturas, factura &factura_asociada, error &err);
void guardar_archivo(arreglo_string params, abb_clientes clientes, abb_productos productos, error &err);
void cargar_archivo(arreglo_string params, abb_clientes &clientes, abb_productos &productos, error &err);

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

    string cedula;
    string nombre;

    obtener_string_arreglo(params, 1, cedula);
    obtener_string_arreglo(params, 2, nombre);

    if (comparar_cant_params_por_comando(CREAR_CLIENTE, obtener_tope_arreglo_string(params)) == TRUE) {
        // validar cedula de tipo entero y nombre string valido
        if (validar_formato_entero(cedula) == TRUE &&
            validar_formato_string(nombre) == TRUE) {
            cliente nuevo_cliente;

            modificar_cedula_cliente(nuevo_cliente, convertir_string_a_entero(cedula));
            modificar_nombre_cliente(nuevo_cliente, nombre);

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

    string codigo;
    string nombre;

    obtener_string_arreglo(params, 1, codigo);
    obtener_string_arreglo(params, 2, nombre);

    if (comparar_cant_params_por_comando(CREAR_PRODUCTO, obtener_tope_arreglo_string(params)) == TRUE) {
        if (validar_formato_entero(codigo) == TRUE &&
            validar_formato_string(nombre) == TRUE) {
            producto nuevo_producto;

            modificar_nombre_producto(nuevo_producto, nombre);

            modificar_codigo_producto(nuevo_producto, convertir_string_a_entero(codigo));

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

void crear_factura(arreglo_string params, lista_facturas &facturas, abb_clientes clientes, factura &nueva_factura, error &err) {

    string cedula_cli;

    obtener_string_arreglo(params, 1, cedula_cli);

    if (comparar_cant_params_por_comando(CREAR_FACTURA, obtener_tope_arreglo_string(params)) == TRUE) {
        if (validar_formato_entero(cedula_cli) == TRUE) {
            arreglo_lineas lineas;
            lineas.tope = 0;

            modificar_cedula_cliente_factura(nueva_factura, convertir_string_a_entero(cedula_cli));

            modificar_estado_factura(nueva_factura, TRUE);

            modificar_arreglo_lineas_factura(nueva_factura, lineas);

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

    string num_fact;
    string num_prod;
    string cant_prod;
    string precio_prod;

    obtener_string_arreglo(params, 1, num_fact);
    obtener_string_arreglo(params, 2, num_prod);
    obtener_string_arreglo(params, 3, cant_prod);
    obtener_string_arreglo(params, 4, precio_prod);


    if (comparar_cant_params_por_comando(AGREGAR_LINEA, obtener_tope_arreglo_string(params)) == TRUE) {
        if (validar_formato_entero(num_fact) == TRUE &&
            validar_formato_entero(num_prod) == TRUE &&
            validar_formato_entero(cant_prod) == TRUE &&
            validar_formato_entero(precio_prod) == TRUE) {

            int numero_factura = convertir_string_a_entero(num_fact);
            int numero_producto = convertir_string_a_entero(num_prod);
            int cantidad_productos = convertir_string_a_entero(cant_prod);
            int precio_producto = convertir_string_a_entero(precio_prod);

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

                                modificar_codigo_producto_linea(nueva_linea, numero_producto);

                                modificar_cantidad_productos_linea(nueva_linea, cantidad_productos);

                                modificar_precio_unitario_linea(nueva_linea, precio_producto);

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

    string num_fact;
    obtener_string_arreglo(params, 1, num_fact);

    if (comparar_cant_params_por_comando(DESPLEGAR_FACTURA, obtener_tope_arreglo_string(params)) == TRUE) {
        if (validar_formato_entero(num_fact) == TRUE) {
            int numero_factura = convertir_string_a_entero(num_fact);

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

                arreglo_lineas lineas_factura;
                obtener_arreglo_lineas_factura(factura_asociada, lineas_factura);

                for (int i = 0; i < obtener_arreglo_lineas_tope(lineas_factura); i++) {

                    linea linea_actual;

                    obtener_una_linea_de_la_factura(factura_asociada, i, linea_actual);

                    producto producto_linea = abb_buscar_producto(productos, linea_actual.codigo_producto);
                    string nombre_producto;

                    obtener_nombre_producto(producto_linea, nombre_producto);

                    printf("\n%-5i%-10i%-20s%-10i$%-10%.02f$%-10%.02f$%-10%.02f\n",
                           obtener_cantidad_productos_linea(linea_actual),
                           obtener_codigo_producto_linea(linea_actual),
                           nombre_producto,
                           obtener_precio_unitario_linea(linea_actual),
                           importe_linea(linea_actual),
                           iva_linea(linea_actual),
                           importe_total_linea(linea_actual));

                    destruir_string(nombre_producto);
                }
                arreglo_lineas lineas;
                obtener_arreglo_lineas_factura(factura_asociada, lineas);

                printf("Importe: $%.02f\n", importe_arreglo_lineas(lineas));
                printf("IVA: $%.02f\n", iva_arreglo_lineas(lineas));
                printf("Total: $%.02f", importe_total_arreglo_lineas(lineas));
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

    string num_fact;
    obtener_string_arreglo(params, 1, num_fact);

    if (comparar_cant_params_por_comando(DESPLEGAR_FACTURA, obtener_tope_arreglo_string(params)) == TRUE) {
        if (validar_formato_entero(num_fact) == TRUE) {
            int numero_factura = convertir_string_a_entero(num_fact);

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
    string nombre_archivo;
    obtener_string_arreglo(params, 1, nombre_archivo);

    if (comparar_cant_params_por_comando(SAVE, obtener_tope_arreglo_string(params)) == TRUE) {
        if(validar_nombre_archivo(nombre_archivo) == TRUE) {
            bajar_abb(clientes, productos, nombre_archivo);
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }

    destruir_string(nombre_archivo);
}

void cargar_archivo(arreglo_string params, abb_clientes &clientes, abb_productos &productos, error &err) {
    string nombre_archivo;
    obtener_string_arreglo(params, 1, nombre_archivo);

    if (comparar_cant_params_por_comando(LOAD, obtener_tope_arreglo_string(params)) == TRUE) {
        if(validar_nombre_archivo(nombre_archivo) == TRUE) {
            if(existe_archivo(nombre_archivo) == TRUE) {
                crear_abb_clientes(clientes);
                crear_abb_productos(productos);

                levantar_abb(clientes, productos, nombre_archivo);
            } else {
                err = ARCHIVO_INEXISTENTE;
            }
        } else {
            err = FORMATO_INCORRECTO;
        }
    } else {
        err = ERROR_DE_SINTAXIS;
    }

    destruir_string(nombre_archivo);
}
