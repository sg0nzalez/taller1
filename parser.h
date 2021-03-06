#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "comando.h"
#include "error.h"

// dado un string asigna un comando y los parametros o un error a los parametros dados
void parsear_comando(string str_comando, arreglo_string &param, comando &com, error &err);

// devuelve la cantidad de parametros separados por espacios en blanco
int cantidad_de_parametros(string str);

// devuelve true si la cantidad de parametros son la correcta para dado comando
boolean comparar_cant_params_por_comando(comando com, int cant_param);

// si el nombre dado es un string alfanumerico incluyendo _
// asigna STRING_VALIDO sino asigna STRING_INVALIDO a err
boolean validar_formato_string(string string_a_chequear);

// si el string dado es un entero
// asigna ENTERO_VALIDO sino asigna ENTERO_INVALIDO a err
boolean validar_formato_entero(string string_a_chequear);

// dado un string determina que comando fue dado o asigna un error
void obtener_comando(string comando_string, comando &com, error &err);

// convierte un string a entero y lo devuelve
int convertir_string_a_entero(string str);

#endif // PARSER_H_INCLUDED
