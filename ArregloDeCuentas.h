#ifndef ARREGLODECUENTAS_H_INCLUDED
#define ARREGLODECUENTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "cuenta.h"
#include "ListaMovimientos.h"
#include "ArregloDeCuentas.h"


typedef struct
{

    stCuenta dato;

    nodoListaMovimiento * ListaMovimientos;

} celdaCuentas;

int agregar (celdaCuentas adl[],int v, stCuenta cuenta);

void borrarCuenta( celdaCuentas* cuenta );


#endif // ARREGLODECUENTAS_H_INCLUDED
