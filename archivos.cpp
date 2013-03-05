#include "archivos.h"


/*void Bajar_String (string s, FILE * f)
{
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite (&s[i], sizeof(char), 1, f);
}

void Levantar_String (string &s, FILE * f)
{
    int i=0;
    string aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    strcop(s,aux);
delete [] aux;
}



void Bajar_Fact (factura fac, FILE * f )
{
    fwrite (&fac.cedula_cliente, sizeof(long int), 1, f);
    fwrite (&fac.numero, sizeof(long int), 1, f);
    fwrite (&fac.estado_pendiente, sizeof(long int), 1, f);
}

void Levantar_Fact (factura &fact, FILE * f )
{
    fread (&fac.cedula_cliente, sizeof(long int), 1, f);
    fread (&fac.numero, sizeof(long int), 1, f);
    fread (&fac.estado_pendiente, sizeof(long int), 1, f);



void Bajar_Prod (producto prod, FILE * f )
{
    Bajar_String (prod.nombre, f);
    fwrite (&prod.codigo, sizeof(long int), 1, f);
    //falta boolean validar_precio
}

void Levantar_Con (producto &prod, FILE * f )
{
        Levantar_String (prod.nombre, f);
        fread (&prod.codigo, sizeof(long int), 1, f);
        //falta boolean validar_precio
}


void Bajar_ABB (Arbol_f a)
{
    FILE * f = fopen ("c:\\factura.txt","wb");
    Bajar_ABB_Aux (a, f);
    fclose(f);
}

void Levantar_ABB (Arbol_f &a){
    FILE * f = fopen ("c:\\factura.txt","rb");
    factura buffer;
    Levantar_Fact()(buffer,f);
    while (!feof(f))
    {
        agregarfactura (a, buffer);
        Levantar_Fact(buffer,f);
    }
fclose(f);
}
*/
