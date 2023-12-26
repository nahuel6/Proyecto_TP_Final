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



//void cargarArchivoCliente(char nombreArchivo[], int dim);

//
void menuGeneralA(nodoArbolCliente* arbol);
//
//
//int main()
//{
//    menuGeneralA(nuevoArbol);
////
//    return 0;
//}



//    nodoArbolCliente* nuevoArbol;
//    nuevoArbol = inicArbol();
//
//    nuevoArbol=  cargarDatos( nuevoArbol );


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);


int main()
{
    nodoArbolCliente* nuevoArbol;
    nuevoArbol = inicArbol();

    nuevoArbol=  cargarDatos( nuevoArbol );

    system("mode con: cols=90 lines=30");
    system("COLOR B0");
    dibujarCuadro(0,0,78,24);
    dibujarCuadro(1,1,77,3);
    gotoxy(30,2);
    printf("MENU GENERAL");
    system("cls");
    printf("\t\t\t\t\t   ===========================\n");
    printf("\t\t\t\t\t        SISTEMA BANCARIO     \n");
    printf("\t\t\t\t\t   ===========================\n\n\n");

    menuGeneralA(nuevoArbol);

    gotoxy (2,12);
    system("pause");

    //ArbolesToArchivo(nuevoArbol, "clientes_bkp");

    return 0;
}

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}



void dibujarCuadro(int x1,int y1,int x2,int y2)
{
    int i;

    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("\304");
        gotoxy(i,y2);
        printf("\304");
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("\263");
        gotoxy(x2,i);
        printf("\263");
    }

    gotoxy(x1,y1);
    printf("\332");
    gotoxy(x1,y2);
    printf("\300");
    gotoxy(x2,y1);
    printf("\277");
    gotoxy(x2,y2);
    printf("\331");
}

int mostrarOpciones()
{
    int i=0;
    printf("\n ==========================================");
    printf("\n 1 = Para dar de ALTA cliente");
    printf("\n 2 = Para dar de BAJA cliente");
    printf("\n 3 = Para MODIFICAR un cliente");
    printf("\n 4 = Para BUSCAR un cliente");
    printf("\n 5 = Para MOSTRAR TODOS los cliente");
    printf("\n ==========================================");
    printf("\n Ingrese la opcion a elegir: ");
    scanf("%d",&i);
    return i;
}
