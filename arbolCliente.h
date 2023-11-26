#ifndef ARBOLCLIENTE_H_INCLUDED
#define ARBOLCLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "ArregloDeCuentas.h"

typedef struct _nodoArbolCliente{

    stCliente Dato;
    celdaCuentas * arregloCuentas;

    struct _nodoArbolCliente *izq;
    struct _nodoArbolCliente *der;

}nodoArbolCliente;


#endif // ARBOLCLIENTE_H_INCLUDED
