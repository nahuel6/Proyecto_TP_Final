#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cuenta.h"

#define ESC 27

// ACA SE ENCUENTRA TODO LO RELACIONADO CON EL ARCHIVO CUENTA
int mostrarOpcionDeCuenta(){
    int i=0;
    printf("\n ================================================");
    printf("\n 1 = Caja de ahorro en Pesos - Costo: $1000/mes");
    printf("\n 2 = Caja de ahorro en Dolares - Costo: $1000/mes");
    printf("\n 3 = Cuenta Corriente en Pesos - Costo: $1000/mes");
    printf("\n =================================================");
    printf("\n Ingrese la opcion a elegir: ");
    scanf("%d",&i);
    return i;
}

stCuenta cargarCuenta(int id, int nroCliente, int opcion){
    stCuenta cuenta;

    cuenta.id=id;

    cuenta.idCliente=nroCliente;

//    cuenta.nroCuenta=nroCuentaA();

    cuenta.tipoDeCuenta=opcion;

    cuenta.costoMensual=1000;

    cuenta.eliminado=0;

    return cuenta;
}

void mostrarCuenta(stCuenta cuenta){
    printf("\n ====================");
    printf("\n id:............ %d",cuenta.id);
    printf("\n idCuenta:...... %d",cuenta.idCliente);
    printf("\n NroCuenta:..... %d",cuenta.nroCuenta);
    printf("\n Tipo de Cuenta: %d",cuenta.tipoDeCuenta);
    printf("\n Costo mensual:. %.2f",cuenta.costoMensual);
    printf("\n Eliminado:..... %d",cuenta.eliminado);
    printf("\n ====================");
}

/*int nroCuentaA(){
    stCuenta cuenta;
    int id=nroCuentaB();
    FILE *archi = fopen(ARCHI_CUENTA, "rb");
    if(archi){
        fseek(archi, sizeof(stCuenta)*(-1),SEEK_END);
        if(fread(&cuenta ,sizeof(stCuenta),1,archi) > 0){
            id = cuenta.nroCuenta;
        }
        fclose(archi);
    }
return id+2;
}*/

int nroCuentaA(int nroCuenta){
    int id=nroCuentaB();
    if(nroCuenta > 0){
        id = nroCuenta;
    }
return id+2;
}

int nroCuentaB(){
    static int i = 100000;
    return i;
}

stCuenta cargarCuentaRandom(stCliente cliente, int i,int cuentaId,int nroCuenta){
    stCuenta cuenta;
    int costMen=0;
    if(i==1){
        costMen=500;
    }else{
        if(i==2){
            costMen=1000;
        }else{
            costMen=1500;
        }
    }
    cuenta.id=idautoincremental(cuentaId);
    cuenta.idCliente=cliente.nroCliente;
    cuenta.nroCuenta=nroCuentaA(nroCuenta);
    cuenta.eliminado=0;
    cuenta.costoMensual=costMen;
    cuenta.tipoDeCuenta=i;

    return cuenta;
}
