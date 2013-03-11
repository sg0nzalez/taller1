#include "archivos.h"

// devuelve true si el nombre_archivo termina en .dat
boolean validar_nombre_archivo(string nombre_archivo) {

    int largo_str = largo_string(nombre_archivo) - 1;

    boolean esValido = FALSE;

    if(nombre_archivo[largo_str-3]=='.' && nombre_archivo[largo_str-2]=='d' &&
       nombre_archivo[largo_str-1]=='a' && nombre_archivo[largo_str]=='t'){
        esValido = TRUE;
    }

    return esValido;
}

// devuelve true si el nombre del archivo dado ya existe en nuestro disco
boolean existe_archivo(string nombre_archivo) {
    boolean existeArchivo = TRUE;

    FILE *f = fopen(nombre_archivo, "rb");

    if (f == NULL)
        existeArchivo = FALSE;

    fclose(f);

    return existeArchivo;
}

// dado un cliente y un FILE, guarda dicho cliente en el archivo dado
void bajar_cliente(cliente cli, FILE *f) {
    fwrite(&cli.cedula, sizeof(long int), 1, f);

    bajar_string(cli.nombre, f);
}

// dado un cliente y un FILE, obtiene el cliente en el archivo dado que este
// en la posicion actual del puntero dentro del archivo y dicho cliente
// lo guarda en el cliente dado
void levantar_cliente(cliente &cli, FILE *f) {
    fread (&cli.cedula, sizeof(long int), 1, f);

    crear_string(cli.nombre);
    levantar_string(cli.nombre, f);
}

// abre el archivo y baja todos los clientes del abb, luego cierra el archivo
void bajar_abb_cliente(abb_clientes clientes, FILE *f) {
    f = fopen(ARCHIVO_CLIENTES, "wb");

    bajar_abb_cliente_aux(clientes, f);

    fclose(f);
}

// recursivamente va bajando cliente por cliente
void bajar_abb_cliente_aux(abb_clientes clientes, FILE *f) {

    if (clientes != NULL) {
        bajar_cliente(clientes->cli, f);
        bajar_abb_cliente_aux(clientes->nodo_izquierda, f);
        bajar_abb_cliente_aux(clientes->nodo_derecha, f);
    }
}

// abre el archivo, obtiene todos los clientes y luego lo cierra
void levantar_abb_cliente(abb_clientes &clientes, FILE *f) {
    f = fopen(ARCHIVO_CLIENTES, "rb");
    cliente buffer;
    levantar_cliente(buffer, f);

    while (!feof(f))
    {
        abb_insertar_cliente(clientes, buffer);

        levantar_cliente(buffer, f);
    }

    fclose(f);
}

// dado un producto y un FILE, guarda dicho producto en el archivo dado
void bajar_producto(producto prod, FILE *f) {
    fwrite(&prod.codigo, sizeof(int), 1, f);

    bajar_string(prod.nombre, f);
}

// dado un producto y un FILE, obtiene el producto en el archivo dado que este
// en la posicion actual del puntero dentro del archivo y dicho producto
// lo guarda en el producto dado
void levantar_producto(producto &prod, FILE *f) {
    fread (&prod.codigo, sizeof(int), 1, f);

    crear_string(prod.nombre);
    levantar_string(prod.nombre, f);
}

// abre el archivo y baja todos los productos del abb, luego cierra el archivo
void bajar_abb_producto(abb_productos productos, FILE *f) {
    f = fopen(ARCHIVO_PRODUCTOS, "wb");

    bajar_abb_producto_aux(productos, f);

    fclose(f);
}

// recursivamente va bajando producto por producto
void bajar_abb_producto_aux(abb_productos productos, FILE *f) {
    if (productos != NULL) {
        bajar_producto(productos->prod, f);
        bajar_abb_producto_aux(productos->nodo_izquierda, f);
        bajar_abb_producto_aux(productos->nodo_derecha, f);
    }
}

// abre el archivo, obtiene todos los productos y luego lo cierra
void levantar_abb_producto(abb_productos &productos, FILE *f) {
    f = fopen(ARCHIVO_PRODUCTOS, "rb");
    producto buffer;
    levantar_producto(buffer, f);

    while (!feof(f))
    {
        abb_insertar_producto(productos, buffer);

        levantar_producto(buffer, f);
    }

    fclose(f);
}

// dado un string y un FILE, guarda dicho string en el archivo dado
void bajar_string(string str, FILE *f) {
    int i=0;

    while (str[i] != '\0')
    {
        fwrite(&str[i], sizeof(char), 1, f);
        i++;
    }

    fwrite(&str[i], sizeof(char), 1, f);
}

// dado un string y un FILE, carga el string dado con un string que
// este en la posicion del puntero en el archivo dado
void levantar_string(string &str, FILE *f) {
    int i=0;
    string aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);

    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    copiar_string(str, aux);
    delete [] aux;
}
