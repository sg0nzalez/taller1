#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "comando.h"
#include "error.h"

// dado un string asigna un comando y los parametros o un error a los parametros dados
void parsear_comando(string comando, arreglo_string &param, comando &com, error &err);

// devuelve la cantidad de parametros separados por espacios en blanco
int cantidad_de_parametros(string str);

// devuelve true si la cantidad de parametros son la correcta para dado comando
boolean comparar_cant_params_por_comando(comando com, int cant_param);

// precondicion: el string dado debe ser un entero
//
// dado un string devuelve el entero
int convertir_string_a_entero(string str, error &err);

// si el nombre dado es un string alfanumerico incluyendo _
// asigna STRING_VALIDO sino asigna STRING_INVALIDO a err
boolean validar_formato_string(string string_a_chequear, error &err);

// si el string dado es un entero
// asigna ENTERO_VALIDO sino asigna ENTERO_INVALIDO a err
boolean validar_formato_entero(string string_a_chequear, error &err);

#endif // PARSER_H_INCLUDED
