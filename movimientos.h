#ifndef MOVIMIENTOS_H_INCLUDED
#define MOVIMIENTOS_H_INCLUDED

#include "cuenta.h"
typedef struct{
    int id;
    int idCuenta;
    int anio;
    int mes;
    int dia;
    char detalle[100];
    float importe;
    int eliminado;
}stMovimiento;

typedef struct{
    int dia;
    int mes;
    int anio;
}stTiempo;

//MOVIMIENTO.C
stMovimiento cargarUnMovimiento(int id, int idCuenta, char detalle[100],float importe);
stMovimiento cargarMovimientoRandom(stCuenta cuenta,int movId);
void mostrarMovimiento(stMovimiento movimiento);
stTiempo tiempo();

#endif // MOVIMIENTOS_H_INCLUDED
