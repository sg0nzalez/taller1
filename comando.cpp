#include "comando.h"

void listar_comandos() {
    printf("\t+ help\n");
    printf("\t+ crearcliente cedula nombre_apellido\n");
    printf("\t+ crearproducto codigo nombre\n");
    printf("\t+ listarclientes\n");
    printf("\t+ listarproductos\n");
    printf("\t+ crearfactura cedula_cliente\n");
    printf("\t+ agregarlinea numero_factura numero_producto cantidad_producto precio_unitario\n");
    printf("\t+ confirmarfactura numero_factura\n");
    printf("\t+ save nombre_archivo\n");
    printf("\t+ load nombre_archivo\n");
    printf("\t+ exit\n");
}
