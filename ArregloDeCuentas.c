#include "ArregloDeCuentas.h"

int alta (celdaCuentas adl[], int v,stCuenta cuenta, stMovimiento movimiento){
nodoListaMovimiento * nuevo=crearNodo(movimiento);
int pos=buscaPos(adl,v,cuenta);
if(pos==-1){
v=agregar(adl,v,cuenta);
pos=v-1;

}
return v;
}

int buscaPos (celdaCuentas adl[],int v,stCuenta cuenta){
int i=0;
int pos=-1;
while(i<v && pos==-1){
        if(strcmp(adl[i].dato.tipoDeCuenta, cuenta.tipoDeCuenta)==0){
           pos=i;
           }
           i++;

}
return v;
}

int agregar (celdaCuentas adl[],int v, stCuenta cuenta){
strcpy(adl[v].dato.tipoDeCuenta, cuenta.tipoDeCuenta);
adl[v].ListaMovimientos=inicLista();
v++;
return v;
}

void borrarCuenta( celdaCuentas* cuenta ){
    borrarLista( cuenta->ListaMovimientos );
    free(cuenta);
}
