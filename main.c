#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define NULL ((void*)0)
#include "cliente.h"
#include "cuenta.h"

#include "movimientos.h"
#include "arbolCliente.h"
#include <time.h>
#define ESC 27

#include "controlador.h"



void cargarArchivoCliente(char nombreArchivo[], int dim);
void muestraArchivo(char nombreArchivo[]);
void muestraArchivoCuenta(char nombreArchivoCuenta[]);
void muestraArchivoMov(char nombreArchivoMov[]);
void MenuGeneral();
void menuGeneralA();


int main()
{
    //MenuGeneral();
    nodoArbolCliente* nuevoArbol;
    nuevoArbol = inicArbol();

    cargarDatos( nuevoArbol );

   // menuGeneralA();

    return 0;
}


void cargarArchivoCliente(char nombreArchivo[],int dim){
    int i = 0;
    char op=0;
    stCliente cliente;
    FILE* archi=fopen(nombreArchivo,"ab");
    if(archi){
        while(op!=ESC){
            system("cls");
            cliente=cargarCliente();
            i++;
            fwrite(&cliente,sizeof(stCliente),1,archi);
            printf("\n Ingrese ESC para dejar de cargar...");
            op=getch();
            fclose(archi);
            FILE* archi=fopen(nombreArchivo,"ab");
        }
        fclose(archi);
    }
}

void muestraArchivo(char nombreArchivo[]){
    stCliente cliente;
    FILE* archi=fopen(nombreArchivo,"rb");
    if(archi){
        while(fread(&cliente,sizeof(stCliente),1,archi)>0){
            mostrarCliente(cliente);
        }
        fclose(archi);
    }
}

void muestraArchivoCuenta(char nombreArchivoCuenta[]){
    stCuenta cuenta;
    FILE* archiCuenta=fopen(nombreArchivoCuenta,"rb");
    if(archiCuenta){
        while(fread(&cuenta,sizeof(stCuenta),1,archiCuenta)>0){
            mostrarCuenta(cuenta);
        }
        fclose(archiCuenta);
    }
}

void muestraArchivoMov(char nombreArchivoMov[]){
    stMovimiento movimiento;
    FILE* archiMov=fopen(nombreArchivoMov,"rb");
    if(archiMov){
        while(fread(&movimiento,sizeof(stMovimiento),1,archiMov)>0){
            mostrarMovimiento(movimiento);
        }
        fclose(archiMov);
    }
}


int posMenor (stCliente cliente[], int pos, int v)
{
    stCliente menor = cliente[pos];
    int posmenor = pos;
    int i = pos +1;
    while (i<v)
    {
        if (atoi (menor.dni) > atoi (cliente[i].dni))
        {
            menor = cliente[i];
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}

void ordenacionPorSeleccion (stCliente cliente[], int v)
{
    int posmenor;
    stCliente aux;
    int i = 0;
    while (i<v-1)
    {
        posmenor = posMenor(cliente,i,v);
        aux = cliente[posmenor];
        cliente[posmenor]=cliente[i];
        cliente[i]= aux;
        i++;
    }
}

void muestraArreglo (stCliente cliente[], int v){

for (int i=0; i<v; i++){
    mostrarCliente(cliente[i]);
}

}


