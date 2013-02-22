#ifndef ARREGLO_STRING_H_INCLUDED
#define ARREGLO_STRING_H_INCLUDED

#include "string.h"

typedef string arre[MAX];

typedef struct {
        arre arreglo;
        int tope;
    } arreglo_string;

#endif // ARREGLO_STRING_H_INCLUDED
