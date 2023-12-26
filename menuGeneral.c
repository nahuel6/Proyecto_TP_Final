
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "cliente.h"
#include "movimientos.h"
#include "arbolCliente.h"

#define ESC 27

//int mostrarOpciones()
//{
//    int i=0;
//    printf("\n ==========================================");
//    printf("\n 1 = Para dar de ALTA cliente");
//    printf("\n 2 = Para dar de BAJA cliente");
//    printf("\n 3 = Para MODIFICAR un cliente");
//    printf("\n 4 = Para BUSCAR un cliente");
//    printf("\n 5 = Para MOSTRAR TODOS los cliente");
//    printf("\n 6 = Para mostrar MOVIMIENTOS");
//
//    printf("\n ==========================================");
//    printf("\n Ingrese la opcion a elegir: ");
//    scanf("%d",&i);
//    return i;
//}


void menuGeneralA(nodoArbolCliente* arbol)
{
    char opSalir;
    int opcion=0;
    int flag=0;

    //cargarRandom();
    do
    {

        opcion=mostrarOpciones();
        switch(opcion)
        {
        case 1:
            //darAltaCliente(ARCHI_CLIENTE,ARCHI_CUENTA);
            system("cls");
            arbol = cargarClienteAArbol(arbol);
            break;
        case 2:
            arbol = borrarCliente(arbol);
            break;
        case 3:
            modificarCliente();
            break;
        case 4:
            //buscarCliente();
            system("cls");
            buscarClienteEnArbolPorDNI(arbol);
            break;
        case 5:
            //muestraArchivo(ARCHI_CLIENTE);
            inOrder(arbol);
            break;
//        case 6:
////            do
////            {
////                muestraArchivoMov(ARCHI_MOVIMIENTOS);
////                printf("\n Ingrese ESC para volver al menu");
////                opSalir=getch();
////            }
////            while(opSalir!=ESC);
////            break;
//        case 7:
//            hacerMovMenu();
//            break;
        }
        printf("\n Ingrese ESC para salir del programa");
        printf("\n Ingrese ENTER para volver al menu");
        opSalir=getch();
        system("cls");
    }
    while(opSalir!=ESC);
}


void movimientoPorFecha()
{
    stMovimiento movimiento;
    int dia=0;
    int mes=0;
    int anio=0;
    int i=0;

    FILE* archiMov=fopen(ARCHI_MOVIMIENTOS,"rb");
    if(archiMov)
    {
        system("cls");
        printf("\n Ingrese el dia: ");
        scanf("%d", &dia);
        printf("\n Ingrese el mes: ");
        scanf("%d", &mes);
        printf("\n Ingrese el a�o: ");
        scanf("%d", &anio);
        while(fread(&movimiento,sizeof(stMovimiento),1,archiMov)>0)
        {
            if(movimiento.dia==dia && movimiento.mes==mes && movimiento.anio==anio)
            {
                mostrarMovimiento(movimiento);
                i++;
            }
        }
        if(i==0)
        {
            printf("\n No se hizo ningun movimiento en ese dia");
        }
        fclose(archiMov);
    }
}


void modificarCliente()
{
    stCliente cliente;
    char dni[12];
    int flag = 0;
    char option = 's';
    char opcion = 0;
    char opcion2 = 's';
    int limpiar = 0;

    FILE* archi=fopen(ARCHI_CLIENTE,"rb");
    if(archi)
    {

        do
        {
            system("cls");
            printf("\n Ingrese el DNI del cliente a modificar: ");
            fflush(stdin);
            gets(dni);
            flag=buscarDni(archi,dni);
            if(flag==0)
            {
                printf("\n El DNI no se encuentra registrado...");
            }
            else
            {
                fseek(archi,0,SEEK_SET);
                while(flag==1 && fread(&cliente,sizeof(stCliente),1,archi)>0)
                {
                    if(strcmp(dni,cliente.dni)==0)
                    {
                        mostrarCliente(cliente);
                        do
                        {
                            if(limpiar == 1)
                            {
                                system("cls");
                            }
                            printf("\n 1 = Modificar el nombre");
                            printf("\n 2 = Modificar el apellido");
                            printf("\n 3 = Modificar el dni");
                            printf("\n 4 = Modificar el email");
                            printf("\n 5 = Modificar el domicilio");
                            printf("\n 6 = Modificar el telefono\n");
                            printf("\n Ingrese una opcion: ");
                            fflush(stdin);
                            opcion = getch();
                            switch(opcion)
                            {
                            case 49:
                                printf("\n Ingrese un nuevo nombre: ");
                                scanf("%s",&cliente.nombre);
                                int pos=ftell(archi)-sizeof(stCliente);
                                fseek(archi,pos,SEEK_SET);
                                fwrite(&cliente, sizeof(stCliente), 1, archi);
                                printf("\nSe modifico el nombre.\n");
                                printf("\n Nombre:..............: %s", cliente.nombre);
                                break;
                            case 50:
                                printf("\n Ingrese un nuevo apellido: ");
                                scanf("%s",&cliente.apellido);
                                int pos2=ftell(archi)-sizeof(stCliente);
                                fseek(archi,pos2,SEEK_SET);
                                fwrite(&cliente, sizeof(stCliente), 1, archi);
                                printf(" Se modifico el apellido.\n");
                                printf("\n Apellido:..............: %s", cliente.apellido);
                                break;
                            case 51:
                                printf("\n Ingrese un nuevo dni: ");
                                scanf("%s",&cliente.dni);
                                int pos3=ftell(archi)-sizeof(stCliente);
                                fseek(archi,pos3,SEEK_SET);
                                fwrite(&cliente, sizeof(stCliente), 1, archi);
                                printf(" Se modifico el dni.\n");
                                printf("\n Dni:..............: %s", cliente.dni);
                                mostrarCliente(cliente);
                                break;

                            case 52:
                                printf("\n Ingrese un nuevo email: ");
                                scanf("%s",&cliente.email);
                                int pos4=ftell(archi)-sizeof(stCliente);
                                fseek(archi,pos4,SEEK_SET);
                                fwrite(&cliente, sizeof(stCliente), 1, archi);
                                printf(" Se modifico el email.\n");
                                printf("\n Email:..............: %s", cliente.email);
                                mostrarCliente(cliente);
                                break;

                            case 53:
                                printf("\n Ingrese un nuevo domicilio: ");
                                scanf("%s",&cliente.domicilio);
                                int pos5=ftell(archi)-sizeof(stCliente);
                                fseek(archi,pos5,SEEK_SET);
                                fwrite(&cliente, sizeof(stCliente), 1, archi);
                                printf(" Se modifico el domicilio.\n");
                                printf("\n Domicilio:..............: %s", cliente.domicilio);
                                mostrarCliente(cliente);
                                break;

                            case 54:
                                printf("\n Ingrese un nuevo telefono: ");
                                scanf("%s",&cliente.telefono);
                                int pos6=ftell(archi)-sizeof(stCliente);
                                fseek(archi,pos6,SEEK_SET);
                                fwrite(&cliente, sizeof(stCliente), 1, archi);
                                printf(" Se modifico el telefono.\n");
                                printf("\n Telefono:..............: %s", cliente.telefono);
                                mostrarCliente(cliente);
                            }
                            printf("\n Desea realizar otra modificacion? s/n: ");
                            opcion2 = getch();
                            limpiar = 1;
                        }
                        while(opcion2 == 's');

                        flag=0;
                    }
                }
            }
            printf("\n Desea buscar otro dni? s/n: ");
            fflush(stdin);
            option = getch();
        }
        while(option == 's');

        fclose(archi);
    }
}







int buscarClienteEnArbolPorDNI(nodoArbolCliente* arbol){
    //38354542
    char DNI[12];
    nodoArbolCliente* result = NULL;
    printf("Ingrese el DNI del cliente: ");
    scanf("%s", DNI);

    result = buscarClienteXdni(arbol, DNI);

    if(result){
        printf("\nCliente Encontrado!\n");
        //mostrarCliente( result->Dato );
        mostrarInformacionCliente(result);
    }else{
        printf("Cliente no registrado.\n");
    }

    return 1;

}

void bajaCliente()
{
    stCliente cliente;
    stCuenta cuenta;
    //stMovimiento movimiento;
    int flag=0;
    char dni[12];
    int id=0;
    int flagC=0;

    FILE* archi=fopen(ARCHI_CLIENTE,"r+b");
    FILE* archiCuen=fopen(ARCHI_CUENTA,"r+b");
    //FILE* archiMov=fopen(ARCHI_MOVIMIENTOS,"r+b");
    if(archi && archiCuen)
    {
        system("cls");
        printf("\n Ingrese el DNI del cliente: ");
        fflush(stdin);
        gets(dni);
        flag=buscarDni(archi,dni);
        if(flag==0)
        {
            printf("\n El DNI no se encuentra registrado...");
        }
        else
        {
            fseek(archi,0,SEEK_SET);
            while(id==0 && fread(&cliente,sizeof(stCliente),1,archi)>0)
            {
                if(strcmp(dni,cliente.dni)==0)
                {
                    fseek(archi,sizeof(stCliente)*(-1),SEEK_CUR);
                    id=cliente.id;
                    cliente.eliminado=-1;
                    fwrite(&cliente,sizeof(stCliente),1,archi);
                    fclose(archi);
                }
            }
            while(flagC==0 && fread(&cuenta,sizeof(stCuenta),1,archiCuen)>0)
            {
                if(id==cuenta.id)
                {
                    fseek(archiCuen,sizeof(stCuenta)*(-1),SEEK_CUR);
                    cuenta.eliminado=-1;
                    fwrite(&cuenta,sizeof(stCuenta),1,archiCuen);
                    flagC=1;
                    fclose(archiCuen);
                }
            }
            /*while(fread(&movimiento,sizeof(stMovimiento),1,archiMov)>0){
                if(id==movimiento.id){
                    printf("\n ghola");
                    fseek(archiMov,sizeof(stMovimiento),SEEK_CUR);
                    movimiento.eliminado=-1;
                    fwrite(&movimiento,sizeof(stMovimiento),1,archiMov);
                }
            }*/
            printf("\n El cliente a sido dado de BAJA con exito!");
        }
        //fclose(archiMov);
    }
}

void hacerMovMenu()
{
    stMovimiento movimiento;
    stCliente cliente;
    stCuenta cuenta;
    char dni[12];
    char detalle[100];
    int flag=0;
    int cuentaId;
    char op;
    float importe;

    FILE* archiCuen=fopen(ARCHI_CUENTA,"rb");
    FILE* archiMov=fopen(ARCHI_MOVIMIENTOS,"a+b");
    FILE* archi=fopen(ARCHI_CLIENTE,"rb");
    if(archi && archiMov && archiCuen)
    {
        system("cls");
        printf("\n Ingrese el DNI del cliente: ");
        fflush(stdin);
        gets(dni);
        flag=buscarDni(archi,dni);
        if(flag==0)
        {
            printf("\n El DNI no se encuentra registrado...");
        }
        else
        {
            printf("\n Ingrese el importe a transferir(si es salida ponga un - adelante del numero): ");
            scanf("%f", &importe);
            printf("\n Ingrese el detalle: ");
            fflush(stdin);
            gets(detalle);
            cuentaId=mostrarOpcionDeCuenta();
        }
        fseek(archi,0,SEEK_SET);
        while(flag==1 && fread(&cliente,sizeof(stCliente),1,archi)>0)
        {
            if(strcmp(dni,cliente.dni)==0)
            {
                while(flag==1 && fread(&cuenta,sizeof(stCuenta),1,archiCuen)>0)
                {
                    if(cliente.id==cuenta.id)
                    {
                        system("cls");
                        movimiento=cargarUnMovimiento(cliente.id,cuentaId,detalle,importe);
                        fseek(archiMov,sizeof(stMovimiento)*(-1),SEEK_END);
                        fwrite(&movimiento,sizeof(stMovimiento),1,archiMov);
                        printf("\n El movimiento se a cargado con exito!");
                        flag=2;
                    }
                }
            }

        }
        fclose(archi);
        fclose(archiMov);
    }
}

//void darAltaCliente(char nombreArchivo[],char nombreCuentaArchi[])
//{
//    stCliente cliente;
//    stCuenta cuenta;
//    char op;
//    char dni[12];
//    int opcion=0;
//    int flag=0;
//    FILE* archi=fopen(nombreArchivo,"a+b");
//    FILE* archiCuenta=fopen(nombreCuentaArchi,"a+b");
//    if(archi && archiCuenta)
//    {
//        while(op!=ESC)
//        {
//            system("cls");
//            printf("\n Ingrese el DNI a cargar: ");
//            fflush(stdin);
//            gets(dni);
//            flag=buscarDni(archi,dni);
//            if(flag==0)
//            {
//                cliente=cargarCliente();
//                fseek(archi,sizeof(stCliente)*(-1),SEEK_END);
//                fwrite(&cliente,sizeof(stCliente),1,archi);
//                opcion=mostrarOpcionDeCuenta();
//                switch(opcion)
//                {
//                case 1:
//                    cuenta=cargarCuenta(cliente.id,cliente.nroCliente,opcion);
//                    fseek(archiCuenta,sizeof(stCuenta)*(-1),SEEK_END);
//                    fwrite(&cuenta,sizeof(stCuenta),1,archiCuenta);
//                    break;
//                case 2:
//                    cuenta=cargarCuenta(cliente.id,cliente.nroCliente,opcion);
//                    fseek(archiCuenta,sizeof(stCuenta)*(-1),SEEK_END);
//                    fwrite(&cuenta,sizeof(stCuenta),1,archiCuenta);
//                    break;
//                case 3:
//                    cuenta=cargarCuenta(cliente.id,cliente.nroCliente,opcion);
//                    fseek(archiCuenta,sizeof(stCuenta)*(-1),SEEK_END);
//                    fwrite(&cuenta,sizeof(stCuenta),1,archiCuenta);
//                    break;
//                }
//            }
//            else
//            {
//                printf("\n El DNI ingresado ya se encuentra en la base de datos");
//            }
//            printf("\n Ingresa ESC para volver al menu principal");
//            printf("\n Ingresa ENTER para intentar con otro DNI");
//            op=getch();
//            fclose(archi);
//            fclose(archiCuenta);
//            FILE* archi=fopen(nombreArchivo,"a+b");
//            FILE* archiCuenta=fopen(nombreCuentaArchi,"a+b");
//        }
//        fclose(archi);
//        fclose(archiCuenta);
//    }
//}

int buscarDni(char nombreArchivo[], char dni[10])
{
    int flag=0;
    stCliente cliente;

    while(flag==0 && fread(&cliente,sizeof(stCliente),1,nombreArchivo)>0)
    {
        if(strcmp(cliente.dni,dni)==0)
        {
            flag=1;
        }
    }
    return flag;
}
