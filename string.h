#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "boolean.h"

// String dinámico

const int MAX = 80;

typedef char *string;

// Metodos

// crea el string dado
void crear_string (string &texto);

// elimina los caracteres  cargados en el string dado
void destruir_string(string &texto);

// carga el string dado
void cargar_string(string &texto);

// muestra en pantalla el string
void desplegar_string(string texto);

// copia el segundo string en el primero
void copiar_string(string &s1, string s2);

// devuelve el largo del string dado
int largo_string(string s);

// comparar dos strings si son iguales
boolean comparar_2_strings(string s1, string s2);

// concatena el segundo string al primero
void concatenar_string(string &s1, string s2);

#endif // STRING_H_INCLUDED
