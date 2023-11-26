#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED

#include "cliente.h"

typedef struct{
    int id;
    int idCliente;
    int nroCuenta;
    int tipoDeCuenta;
    float costoMensual;
    int eliminado;
}stCuenta;

int mostrarOpcionDeCuenta();
int nroCuentaA(int nroCuenta);
int nroCuentaB();
stCuenta cargarCuenta(int id, int nroCcliente, int opcion);
stCuenta cargarCuentaRandom(stCliente cliente, int i,int cuentaId,int nroCuenta);
void mostrarCuenta();

#endif // CUENTA_H_INCLUDED
