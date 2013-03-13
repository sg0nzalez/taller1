#include "comando.h"

void listar_comandos() {
    printf(" - help\n");
    printf(" - crearcliente cedula nombre_apellido\n");
    printf(" - crearproducto codigo nombre\n");
    printf(" - listarclientes\n");
    printf(" - listarproductos\n");
    printf(" - crearfactura cedula_cliente\n");
    printf(" - agregarlinea numero_factura numero_producto cantidad_producto precio_unitario\n");
    printf(" - confirmarfactura numero_factura\n");
    printf(" - desplegarfactura numero_factura\n");
    printf(" - save nombre_archivo\n");
    printf(" - load nombre_archivo\n");
    printf(" - exit");
}
