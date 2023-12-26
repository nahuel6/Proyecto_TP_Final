#include "arbolCliente.h"


nodoArbolCliente * inicArbol ()
{
    return NULL;
}

nodoArbolCliente * crearNodoArbol (stCliente dato)
{

    nodoArbolCliente* nuevo=(nodoArbolCliente*) malloc(sizeof(nodoArbolCliente));
    nuevo->izq=NULL;
    nuevo->der=NULL;
    nuevo->Dato=dato;
    nuevo->arregloCuentas[3];


    return nuevo;
}

nodoArbolCliente* agregarNodoArbol (nodoArbolCliente * arbol, nodoArbolCliente * nuevo)
{
    if(!arbol)
    {
        arbol=nuevo;
    }
    else
    {
        if(atoi(nuevo->Dato.dni) > atoi(arbol->Dato.dni))
        {
            arbol->der=agregarNodoArbol(arbol->der,nuevo);
        }
        else
        {
            arbol->izq=agregarNodoArbol(arbol->izq,nuevo);
        }
    }
    return arbol;
}

nodoArbolCliente * buscarClienteXdni (nodoArbolCliente * arbol, char Dni[])
{
    nodoArbolCliente * rta=NULL;
    if(arbol)
    {
        if(strcasecmp(arbol->Dato.dni, Dni) == 0)
        {
            rta=arbol;
        }
        else
        {
            rta=buscarClienteXdni(arbol->izq,Dni);
            if(!rta)
            {
                rta=buscarClienteXdni(arbol->der,Dni);
            }

        }
    }
    return rta;
}

void inOrder (nodoArbolCliente * arbol)
{
    if(arbol)
    {
        inOrder(arbol->izq);
        mostrarCliente(arbol->Dato);
        inOrder(arbol->der);
    }
}

nodoArbolCliente* cargarClienteAArbol( nodoArbolCliente* arbol )
{
    //39294102
    nodoArbolCliente* nodoCliente;
    stCliente cliente;
    stCuenta cuenta;

    char DNI[12];

    printf("Ingrese el DNI del cliente:");
    scanf( "%s", DNI );

    nodoCliente = buscarClienteXdni( arbol, DNI );

    if(!nodoCliente)
    {
        cliente = cargarCliente(DNI);

        nodoCliente = crearNodoArbol( cliente );

        arbol = agregarNodoArbol( arbol, nodoCliente );

        agregarCuentaAClienteEnArbol( cliente );

    }
    else
    {
        printf("\nYa existe un cliente con ese DNI.\n");
    }

    return arbol;


}

void agregarCuentaAClienteEnArbol( nodoArbolCliente* cliente )
{
    celdaCuentas* celdaCuenta;
    stCuenta cuenta;
    cuenta.nroCuenta = nroCuentaA(100000);
    cuenta.idCliente = cliente->Dato.id;
    cuenta.costoMensual = 1000;
    int opcion;
    printf("\nElija el tipo de cuenta \n");
    opcion = mostrarOpcionDeCuenta();

    cuenta.tipoDeCuenta = opcion;

    celdaCuenta = (celdaCuentas*)malloc(sizeof(celdaCuentas));
    celdaCuenta->dato = cuenta;

    cliente->arregloCuentas[opcion-1] = celdaCuenta;

    printf("\nCuenda creada exitosamente\n");


}

nodoArbolCliente* borrarNodoArbol(nodoArbolCliente* arbol, char dni[])
{

    if (arbol == NULL)
    {
        return arbol;
    }
    if (atoi(dni) < atoi(arbol->Dato.dni))
    {
        arbol->izq = borrarNodoArbol(arbol->izq, dni);
    }
    else if (atoi(dni) > atoi(arbol->Dato.dni))
    {
        arbol->der = borrarNodoArbol(arbol->der, dni);
    }
    else
    {

        if (arbol->izq == NULL)
        {
            nodoArbolCliente* aux = arbol->der;
            free(arbol);
            return aux;
        }
        else if (arbol->der == NULL)
        {
            nodoArbolCliente* aux = arbol->izq;
            free(arbol);
            return aux;
        }

        nodoArbolCliente* min = arbol->der;
        while (min->izq != NULL)
        {
            min = min->izq;
        }

        strcpy(arbol->Dato.dni,min->Dato.dni);
        arbol->der = borrarNodoArbol(arbol->der, min->Dato.dni);
    }

    return arbol;
}

nodoArbolCliente* borrarCliente(  nodoArbolCliente* arbol )
{
    char dni[20];
    nodoArbolCliente* cliente;

    printf("\nIngrese el DNI del cliente a borrar: ");
    scanf("%s", dni);

    cliente = buscarClienteXdni(arbol, dni);
    if(cliente)
    {
        for( int i = 0; i < 2; i++ )
        {
            if(cliente->arregloCuentas[i])
            {
                borrarCuenta( cliente->arregloCuentas[i] );
            }
        }

        arbol = borrarNodoArbol( arbol, cliente->Dato.dni );

        printf("\Baja de cliente exitosa\n");

    }
    else
    {
        printf("\nCliente no registrado\n");
    }

    return arbol;

}

void mostrarInformacionCliente( nodoArbolCliente* cliente )
{
    mostrarCliente(cliente->Dato);
    printf("\nCUENTAS\n");
    for( int i = 0; i < 2; i++ )
    {
        if(cliente->arregloCuentas[i])
        {
            printf("Cuenta nro.: %d\t", cliente->arregloCuentas[i]->dato.nroCuenta);
            printf("Total movimientos: %d\n", contarMovimientos( cliente->arregloCuentas[i]->ListaMovimientos ));
        }
    }
}

void ArbolesToArchivo(nodoArbolCliente* arbol, char nombreArchivo[])
{

    stCliente cliente;

    //char nombreArchivo[50];
        printf("!!!!\n");
    strcpy(nombreArchivo, strcat(nombreArchivo,".dat"));

    FILE * archi = fopen(nombreArchivo,"ab");
    if(archi)
    {
        arbolToArchi(arbol,archi);
        fclose(archi);
    }


}
void arbolToArchi(nodoArbolCliente * arbol, FILE * archi)
{

    if(arbol)
    {
        arbolToArchi(arbol->izq,archi);
        fwrite(&arbol->Dato,sizeof(stCliente),1,archi);
        //fwrite(&arbol->arregloCuentas,sizeof(celdaCuentas),1,archi);
        arbolToArchi(arbol->der,archi);
    }


}
