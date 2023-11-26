#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED

#include "arbolCliente.h"
#include "ArregloDeCuentas.h"
//CLIENTES
int pasarArchivoArreglo(stCliente clienteA[],char nombreArchi[],int dim);
nodoArbolCliente* arregloAarbol(stCliente cliente[], int inicio, int fin, nodoArbolCliente* arbol);
nodoArbolCliente* cargarArbolCliente( nodoArbolCliente* arbol, char nombreArchivo[] );

//CUENTAS
int cargarCuentasPorCliente( nodoArbolCliente* arbol, char nombreArchivo[] );
int agregarCuentasACliente( nodoArbolCliente* arbol, FILE* f );

int cargarDatos( nodoArbolCliente* arbol );

#endif // CONTROLADOR_H_INCLUDED
