#ifndef LISTAMOVIMIENTOS_H_INCLUDED
#define LISTAMOVIMIENTOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "movimientos.h"

typedef struct _nodoListaMovimiento{

stMovimiento dato;

struct _nodoListaMovimiento * sig;

}nodoListaMovimiento;

nodoListaMovimiento * inicLista();
nodoListaMovimiento * crearNodo(stMovimiento dato);
nodoListaMovimiento* agregarAlPrincipio (nodoListaMovimiento * lista, nodoListaMovimiento * nuevo);
nodoListaMovimiento * agregarEnOrdenPorFecha (nodoListaMovimiento* lista, nodoListaMovimiento * nuevo);


#endif // LISTAMOVIMIENTOS_H_INCLUDED
