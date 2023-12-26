#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARCHI_CLIENTE "cliente.dat"
#define ARCHI_CUENTA "cuenta.dat"
#define ARCHI_MOVIMIENTOS "movimientos.dat"

//ACA SE INVOCAN TODAS LAS ESTRUCTURAS, Y SE PROTOTIPEAN TODAS LAS FUNCIONES
typedef struct{
    int id;
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char telefono[12];
    int eliminado;
} stCliente;
//CLIENTE.C
int nroClienteB();
int nroClienteA();
stCliente cargarCliente(char dni[]);
stCliente cargarClienteRandom(int clienteId, int nroCliente,int num, int numDni);
void mostrarCliente(stCliente cliente);
int logearse(char nombreArchivo[]);
int idautoincremental ();
int idAuto();

//MENU GENERAL
int mostrarOpciones();
//void darAltaCliente(char nombreArchivo[],char nombreCuentaArchi[]);
int buscarDni(char nombreArchivo[], char dni[10]);
void hacerMovMenu();
void bajaCliente();
void movimientoPorFecha();

//RANDOM.C
void cargarRandom();
int buscarNumero(int numero, int a[]);
void getName(char n[],int numRan);
void getLastname(char l[],int numRan);
void getDni(char d[],int numRan);
void getEmail(char e[],int numRan);
void getDomicilio(char d[],int numRan);
void getTelefono(char d[],int numRan);
//void moviemientoRand();
#endif // CLIENTE_H_INCLUDED
