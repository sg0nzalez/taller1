#include "string.h"

void crear_string(string &s) {

    s = new char[1];
    s[0] = '\0';
}

void destruir_string(string &s) {

    delete [] s;
    s = NULL;
}

void cargar_string(string &texto) {

    string aux = new char[MAX];
    int i = 0;
    char c;

    scanf("%c",&c);

    while ((c != '\n') && (i < MAX)) {
        aux[i] = c;
        i++;
        scanf("%c", &c);
    }

    aux[i] = '\0';

    copiar_string(texto,aux);
    destruir_string(aux);
}

void desplegar_string(string texto) {

    int i = 0;

    while(texto[i] != '\0') {
        printf("%c",texto[i]);

        i++;
    }
}

void copiar_string(string &s1, string s2) {
    int i = 0;

    int largo = largo_string(s2) + 1;

    s1 = NULL;

    delete [] s1;

    s1 = new char[largo];

    while (s2[i] != '\0'){
        s1[i] = s2[i];
        i++;
    }

    s1[i] = '\0';
}

int largo_string(string s) {

    int i = 0;

    while (s[i] != '\0')

        i++;

    return i;
}

boolean comparar_2_strings(string s1,string s2) {

    int i = 0;
    boolean iguales = TRUE;

    while (iguales && (s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] != s2[i])
            iguales = FALSE;

        i++;
    }

    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;

    return iguales;
}

void concatenar_string(string &s1,string s2) {

    string aux;
    crear_string(aux);
    copiar_string(aux, s1);

    int largo = largo_string(s1) + largo_string(s2) + 1;

    if (largo > MAX)
        largo = MAX;

    s1 = NULL;
    delete [] s1;
    s1 = new char[largo];

    int i=0;
    while (aux[i] != '\0') {
        s1[i] = aux[i];
        i++;
    }

    int j=0;
    while (s2[j] != '\0' && i < MAX-1) {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    destruir_string(aux);
}

