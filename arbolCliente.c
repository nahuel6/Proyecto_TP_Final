#include "arbolCliente.h"


nodoArbolCliente * inicArbol (){
return NULL;
}

nodoArbolCliente * crearNodoArbol (stCliente dato){

nodoArbolCliente* nuevo=(nodoArbolCliente*) malloc(sizeof(nodoArbolCliente));
nuevo->izq=NULL;
nuevo->der=NULL;
nuevo->Dato=dato;
nuevo->arregloCuentas[3];


return nuevo;
}

nodoArbolCliente* agregarNodoArbol (nodoArbolCliente * arbol, nodoArbolCliente * nuevo){
if(!arbol){
    arbol=nuevo;
}else{
        if(atoi(nuevo->Dato.dni) > atoi(arbol->Dato.dni)){
            arbol->der=agregarNodoArbol(arbol->der,nuevo);
        }else{
        arbol->izq=agregarNodoArbol(arbol->izq,nuevo);
        }
}
return arbol;
}

nodoArbolCliente * buscarClienteXdni (nodoArbolCliente * arbol, int Dni){
    nodoArbolCliente * rta=NULL;
    if(arbol){
        if(arbol->Dato.dni==Dni){
            rta=arbol;
        }else{
        rta=buscarClienteXdni(arbol->izq,Dni);
        if(!rta){
            rta=buscarClienteXdni(arbol->der,Dni);
        }

        }
    }
    return rta;
}

void inOrder (nodoArbolCliente * arbol){
if(arbol){
    inOrder(arbol->izq);
    mostrarCliente(arbol->Dato);
    printf("\n Hola");
    inOrder(arbol->der);
}
}
