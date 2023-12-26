#include "controlador.h"

int pasarArchivoArreglo(stCliente arreglo[],char nombreArchi[],int dim)
{
    stCliente cliente;
    int v=0;
    FILE* archi = fopen(nombreArchi,"rb");
    if(archi)
    {
        while(v<dim && fread(&cliente,sizeof(stCliente),1,archi)>0)
        {
            arreglo[v]= cliente;
            v++;
        }
        fclose(archi);
    }
    else
    {
        printf("ERROR! No se pudo encontrar o abrir %s \n", nombreArchi);
    }
    return v;
}

nodoArbolCliente* arregloAarbol(stCliente cliente[], int inicio, int fin, nodoArbolCliente* arbol)
{
    if(inicio <= fin)
    {
        int posMedio = floor((inicio+fin)/2);
        arbol=agregarNodoArbol(arbol,crearNodoArbol(cliente[posMedio]));
        arbol=arregloAarbol(cliente,inicio,posMedio-1,arbol);
        arbol=arregloAarbol(cliente,posMedio+1,fin,arbol);
    }
    return arbol;
}

nodoArbolCliente* cargarArbolCliente( nodoArbolCliente* arbol, char nombreArchivo[] )
{
    stCliente arregloClientes[DIM];
    int validos = 0;

    validos = pasarArchivoArreglo( arregloClientes, "cliente.dat", DIM );
    if(validos == 0)
        return 0;

    arbol = arregloAarbol( arregloClientes, 0, 19, arbol );

    return arbol;
}



int cargarCuentasPorCliente( nodoArbolCliente* arbol, char nombreArchivo[] )
{
    FILE* f;
    f = fopen( nombreArchivo, "rb" );
    if(f)
    {

        agregarCuentasInOrder( arbol, f );
        fclose(f);
        return 1;

    }
    else
    {
        printf("ERROR! No se pudo encontrar o leer %s\n", nombreArchivo);
        return 0;
    }




}

int agregarCuentasACliente( nodoArbolCliente* arbol, FILE* f )
{

    stCuenta AUX;
    celdaCuentas* AUX_CELDA ;

    if(!arbol)
    {
        return 0;
    }

    //printf("Cliente seleccionado: %d \n", arbol->Dato.nroCliente);

    if(arbol)
    {


        while( fread(&AUX, sizeof(stCuenta), 1, f) > 0 )
        {
            if( AUX.idCliente == arbol->Dato.nroCliente )
            {
                AUX_CELDA = (celdaCuentas*)malloc(sizeof(celdaCuentas));
                AUX_CELDA->dato = AUX;
                arbol->arregloCuentas[ AUX.tipoDeCuenta - 1 ] = AUX_CELDA;
                //printf("Cuenta agregada ID: %d\n",  arbol->arregloCuentas[ AUX.tipoDeCuenta - 1 ]->dato.id);
            }
        }
    }
    fseek(f, 0, SEEK_SET);





    return 1;

}

void agregarCuentasInOrder( nodoArbolCliente* arbol, FILE* f )
{

    if(arbol)
    {
        agregarCuentasInOrder( arbol->der, f );
        agregarCuentasACliente( arbol, f );
        agregarCuentasInOrder( arbol->izq, f );
    }

}


int cargarMovimientosPorCliente( nodoArbolCliente* arbol, char nombreArchivo[] )
{
    FILE* f;
    f = fopen( nombreArchivo, "rb" );
    if(f)
    {

        agregarMovimientosInOrder( arbol, f );
        fclose(f);
        return 1;

    }
    else
    {
        printf("ERROR! No se pudo encontrar o leer %s\n", nombreArchivo);
        return 0;
    }
}

void agregarMovimientosInOrder( nodoArbolCliente* arbol, FILE* f )
{

    if(arbol)
    {
        agregarMovimientosInOrder(arbol->der, f);
        agregarMovimientosACliente( arbol, f );
        agregarMovimientosInOrder(arbol->izq, f);
    }
}

int agregarMovimientosACliente( nodoArbolCliente* cliente, FILE* f )
{
    if(!cliente)
    {
        return 0;
    }

    //printf("Cliente seleccionado: %d \n", arbol->Dato.nroCliente);

    if(cliente)
    {
        for( int i = 0; i < 2; i++ )
        {
            if(cliente->arregloCuentas[i] != 0 )
            {
                agregarMovimientosACuenta( cliente->arregloCuentas[i], f  );
            }
        }
    }

    return 1;
}

int agregarMovimientosACuenta( celdaCuentas* cuenta, FILE* f  )
{
    stMovimiento AUX;
    nodoListaMovimiento* AUX_NODO;

    if(cuenta)
    {
        //printf("Cuenta seleccionada ID %d\n", cuenta->dato.nroCuenta);
        cuenta->ListaMovimientos = inicLista();

        while(fread( &AUX, sizeof(stMovimiento), 1, f ) > 0)
        {
            if(cuenta->dato.nroCuenta == AUX.idCuenta)
            {
                AUX_NODO = crearNodo( AUX );
                cuenta->ListaMovimientos = agregarAlPrincipio( cuenta->ListaMovimientos, AUX_NODO );
                //printf("MOV agregado ID %d\n", AUX.id);
            }
        }
    }
    fseek(f, 0, SEEK_SET);

    return 1;

}

nodoArbolCliente* cargarDatos( nodoArbolCliente* arbol )
{
    printf("Cargando Clientes...");
    arbol = cargarArbolCliente( arbol, "cliente.dat" );
    printf(" OK.\n");

    printf("Cargando Cuentas...");
    cargarCuentasPorCliente(arbol, "cuenta.dat");
    printf(" OK.\n");

    printf("Cargando Movimientos...");
    cargarMovimientosPorCliente(arbol, "movimientos.dat");
    printf(" OK.\n");

    return arbol;
}
