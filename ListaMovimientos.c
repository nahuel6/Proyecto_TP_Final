#include "ListaMovimientos.h"

nodoListaMovimiento * inicLista(){
return NULL;
}

nodoListaMovimiento * crearNodo(stMovimiento dato){
nodoListaMovimiento* nuevo=(nodoListaMovimiento*)malloc(sizeof(nodoListaMovimiento));
nuevo->dato=dato;
nuevo->sig=NULL;

return nuevo;
}
nodoListaMovimiento* agregarAlPrincipio (nodoListaMovimiento * lista, nodoListaMovimiento * nuevo){
if(lista==NULL){
    lista=nuevo;
}else{
    nuevo->sig=lista;
    lista=nuevo;
}
return lista;
}

nodoListaMovimiento * agregarEnOrdenPorFecha (nodoListaMovimiento* lista, nodoListaMovimiento * nuevo){
if(lista==NULL){
    lista=nuevo;
}else{
    if(nuevo->dato.anio < lista->dato.anio){
    lista=agregarAlPrincipio(lista,nuevo);

}else if(nuevo->dato.anio == lista->dato.anio && nuevo->dato.mes < lista->dato.mes){
        lista=agregarAlPrincipio(lista,nuevo);

}else if(nuevo->dato.anio == lista->dato.anio && nuevo->dato.mes == lista->dato.mes && nuevo->dato.dia <= lista->dato.dia ){
        lista=agregarAlPrincipio(lista,nuevo);
}else{
    nodoListaMovimiento* aux=lista->sig;
    nodoListaMovimiento* ante=lista;

    while(aux && nuevo->dato.anio > lista->dato.anio){
        aux=aux->sig;
        ante=aux;
    }
   while(aux && nuevo->dato.mes > lista->dato.mes){
    aux=aux->sig;
    ante=aux;
}
while(aux && nuevo->dato.dia > lista->dato.dia){
    aux=aux->sig;
    ante=aux;
}
if(aux){
    nuevo->sig=aux;
    ante->sig=nuevo;
}
}
}
return lista;
}
