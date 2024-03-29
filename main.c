#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///crear una lista insertarListaOrdenado y buscar elementos siempre apuntando hacia void y castendo como una struct


typedef struct NodoE * NodoPtr;
typedef struct ListaE * ListaPtr;
typedef struct PersonaE * PersonaPtr;
typedef struct ColaE * ColaPtr;
typedef struct PilaE * PilaPtr;
typedef struct NodoA * NodoAptr;
///ahora trabajamos con arboles avl
struct NodoA{
int fe;
void * ptrDato;
NodoAptr izq;
NodoAptr der;
};

struct PersonaE{
int edad;
char nombre[30];

};
struct NodoE{
void *dato;
NodoPtr sgte;

};
struct ListaE{
NodoPtr primero;
};

struct ColaE{
NodoPtr inicio;
};
struct PilaE{
NodoPtr principio;
};

NodoPtr crearNodo(void* dato);


ColaPtr crearCola(){
ColaPtr cola=malloc (sizeof(struct ColaE));
cola->inicio=NULL;
return cola;
}

int encolar(ColaPtr cola, void* dato){
    if(cola==NULL){
        return 0;
    }

    if (dato==NULL){

        return 0;
    }

NodoPtr no=crearNodo(dato);
if (cola->inicio==NULL){
cola->inicio=no;
printf("%s---encolando\n",((PersonaPtr)no->dato)->nombre);

return 1;
}

NodoPtr aux=cola->inicio;

    while(aux->sgte!=NULL){
        aux=aux->sgte;
    }
printf("%s---encolando\n",((PersonaPtr)no->dato)->nombre);
     aux->sgte=no;
     no->sgte=NULL;
    return 1;
}



void mostrarColaFrente(ColaPtr cola){
    NodoPtr actual = cola->inicio;
        printf("%s ", ((PersonaPtr)actual->dato)->nombre);
}

int mostrarColaFinal(ColaPtr cola){
     if (cola->inicio == NULL) {
        return 0;
    }
NodoPtr actual=cola->inicio;
while(actual!=NULL){
        if(actual->sgte==NULL)
         printf("%s---final\n ", ((PersonaPtr)actual->dato)->nombre);
        actual=actual->sgte;

}

return 1;
}

int desencolar(ColaPtr cola) {
    if (cola->inicio == NULL) {
        return 0;
    }

    NodoPtr aux = cola->inicio;
    while (aux != NULL) {
        printf("\n----%s nombre desencolado----\n", ((PersonaPtr)aux->dato)->nombre);

        NodoPtr aux2 = aux;
        aux = aux->sgte;
        free(aux2);
    }

    cola->inicio = NULL;  // Despu�s de desencolar todo, establecer el inicio a NULL

    return 1;  // �xito
}



PersonaPtr crearPersona(int edad,char nombre[30]){
PersonaPtr p=malloc(sizeof(struct PersonaE));
p->edad=edad;
strcpy(p->nombre, nombre);
return p;

}
char * getNombre(PersonaPtr p){

return p->nombre;
}

NodoPtr crearNodo(void * dato) {
    NodoPtr no = malloc(sizeof(struct NodoE));
    no->dato = dato;
    no->sgte = NULL;
    return no;
}

ListaPtr crearLista(){
ListaPtr lista=malloc (sizeof (struct ListaE));
lista->primero=NULL;
return lista;
}

int insertarListaOrdenado(ListaPtr lista, void *dato) {
    if (lista == NULL) {
        return 0;
    }
    if (dato == NULL) {
        return 0;
    }

    NodoPtr no = crearNodo(dato);

if (lista->primero == NULL || strcmp(((PersonaPtr)lista->primero->dato)->nombre, ((PersonaPtr)no->dato)->nombre) > 0){
        no->sgte = lista->primero;
        lista->primero = no;

        return 1;
    }

    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;

    while (actual != NULL &&  strcmp(((PersonaPtr)actual->dato)->nombre,  ((PersonaPtr)no->dato)->nombre)<0) {

        anterior = actual;
        actual = actual->sgte;
    }

    no->sgte = actual;

    if (anterior != NULL) {
        anterior->sgte = no;
    } else {
        lista->primero = no;
    }

    return 1;
}

ListaPtr duplicarLista(ListaPtr l){
if (l==NULL){
    return NULL;
}
NodoPtr aux=NULL;
aux=l->primero;
ListaPtr listadupli=crearLista();
while (aux!=NULL){

   insertarListaOrdenado(listadupli,aux->dato);
    aux=aux->sgte;
}

return listadupli;

}
int triplicarLista(ListaPtr l){
if(l==NULL){
return 0;
}
ListaPtr lis3=crearLista();
ListaPtr lis=duplicarLista(l);
NodoPtr aux=NULL;
aux=lis->primero;
while (aux!=NULL){

   insertarListaOrdenado(lis3,aux->dato);
    aux=aux->sgte;
}

return 1;

}
void mostrarLista(ListaPtr l){
    NodoPtr actual = l->primero;

    while (actual != NULL){
        printf("%s ", ((PersonaPtr)actual->dato)->nombre);
        actual = actual->sgte;
    }
}
void mostrarListaXedad(ListaPtr l){

    NodoPtr actual = l->primero;

    while (actual != NULL){
        printf("nombre-->%s-->edad-->%d \n", ((PersonaPtr)actual->dato)->nombre,((PersonaPtr)actual->dato)->edad);
        actual = actual->sgte;
    }
}
int buscarElementos(ListaPtr lista , void * busco){
    int pos=0;
    NodoPtr aux=crearNodo(NULL);
    aux=lista->primero;

    while(((PersonaPtr)aux->dato)->edad != ((PersonaPtr)busco)->edad && aux!=NULL ){
         aux=aux->sgte;
         pos++;

            }
               if (aux==NULL){
                printf(" no encontro el dato ");
                return 0;
            }
        printf(" encontro el dato que es %d", ((PersonaPtr)aux->dato)->edad);
        return pos;
    }



void ordenarElementosListaXedad(ListaPtr  l){
NodoPtr ordenar=l->primero;
NodoPtr aux=NULL;
while(ordenar!=NULL){
        NodoPtr siguiente=ordenar->sgte;

    while(siguiente!=NULL){
        if(((PersonaPtr)ordenar->dato)->edad <((PersonaPtr)ordenar->sgte->dato)->edad){

            aux=ordenar->dato;
            ordenar->dato=siguiente->dato;
            siguiente->dato=aux;


        }

siguiente=siguiente->sgte;


}
ordenar = ordenar->sgte;
}
}

void ordenarElementosListaXnombre(ListaPtr  l){
NodoPtr ordenar=l->primero;
NodoPtr aux=NULL;
while(ordenar!=NULL){
        NodoPtr siguiente=ordenar->sgte;

    while(siguiente!=NULL){
        if(strcmp(((PersonaPtr)ordenar->dato)->nombre ,((PersonaPtr)siguiente->dato)->nombre)>0){///de menor a mayor

            aux=siguiente->dato;
            siguiente->dato=ordenar->dato;
            ordenar->dato=aux;


        }

siguiente=siguiente->sgte;


}
ordenar = ordenar->sgte;
}
}
void eliminarNodo(ListaPtr lista, void *dato) {
    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;
    while (actual != NULL && actual->dato != dato) {
        anterior = actual;
        actual = actual->sgte;
    }
   if (anterior == NULL) {
        lista->primero = actual->sgte;
    } else {
        anterior->sgte= actual->sgte;
    }
    free(actual);
}

PilaPtr crearPila(){
PilaPtr pi=malloc(sizeof(struct PilaE));
pi->principio=NULL;


return pi;
};

int apilar(PilaPtr p ,void * dato){
if(p==NULL || dato==NULL){
   return 0;
}
NodoPtr nodo=crearNodo(dato);
if(p->principio == NULL){
    p->principio=nodo;

}
else{
nodo->sgte=p->principio;
p->principio=nodo;
}
return 1;
}

int vaciarPila(PilaPtr p) {
    if (p == NULL) {

        return 0;
    }

    while (p->principio != NULL) {
        NodoPtr nodoDesapilado = p->principio;
        p->principio = nodoDesapilado->sgte;
        free(nodoDesapilado);
    }
    return 1;
}
void mostrarPila(PilaPtr l){
    NodoPtr actual = l->principio;

    while (actual != NULL){
        printf("%s ", ((PersonaPtr)actual->dato)->nombre);
        actual = actual->sgte;
    }
}

void rotacionSImpleIzquierda(NodoAptr n, NodoAptr n1){

if (n->fe==2 || n1->fe==0){
    n->der=n1->izq;
    n1->izq=n;
    n=n1;
}
}
void rotacionSImpleDerecha(NodoAptr n,NodoAptr n1){
if((n->fe=-2 )|| (n1->fe<=0)){
n->izq=n1->der;
n1->der=n;
n=n1;

}

}
void rotoacionDobleIzquirdaDerecha(NodoAptr n1,NodoAptr n2 , NodoAptr n ){
    if((n->fe=-2 )|| (n1->fe>0)){
n1->der=n2->izq;
n2->izq=n1;
n->izq=n2->der;
n2->der=n;
n=n2;

}
}
void rotoacionDobleDerechaIzquierda(NodoAptr n1,NodoAptr n2 , NodoAptr n ){
    if((n->fe=-2 )|| (n1->fe<0)){
n1->izq=n2->der;
n2->der=n1;
n->der=n2->izq;
n2->izq=n;
n=n2;

}
}
int main()
{
PersonaPtr p1=crearPersona(33,"rober");
PersonaPtr p2=crearPersona(32,"carlos");
PersonaPtr p3=crearPersona(3,"tony");
PersonaPtr p4=crearPersona(4,"marcia");
PersonaPtr p5=crearPersona(3,"macarena");

ListaPtr l=crearLista();

insertarListaOrdenado(l,p1);
insertarListaOrdenado(l,p2);
insertarListaOrdenado(l,p3);
insertarListaOrdenado(l,p4);

mostrarLista(l);

printf("\n---duplicar la lista--\n");

duplicarLista(l);

mostrarLista(l);
printf("\n---triplicar la lista--\n");

triplicarLista(l);

mostrarLista(l);

printf("\n-----\n");
int r=buscarElementos(l,p3);

printf("\n-->-pos del buscar-->--%d---------\n",r);

printf("\n-----\n");
mostrarLista(l);

printf("\n-->ordenar lista X edad-->----------------\n");
ordenarElementosListaXedad(l);
mostrarListaXedad(l);
printf("\n-----\n");
printf("\n-->ordenar lista X nombre-->----------------\n");
ordenarElementosListaXnombre(l);
mostrarListaXedad(l);


eliminarNodo(l,p3);

printf("\n-----\n");


printf("\n-----------\n");
mostrarLista(l);
printf("\n-----------\n");
eliminarNodo(l, p2);

mostrarLista(l);
printf("\n-----------\n");
ColaPtr co =crearCola();
printf("\nencolando en la cola\n");
encolar (co,p2);
encolar(co,p1);
encolar(co,p3);
encolar(co,p4);
printf("\nmostrar Cola Frente nombre-->");
mostrarColaFrente(co);
printf("\n-----------\n");
printf("\nmostrar Cola final\n");
mostrarColaFinal(co);
printf("\n***********\n");
desencolar(co);
printf("\n***********\n");
printf("\n----crear PILA.....\n");
PilaPtr p=crearPila();
apilar(p,p1);
apilar(p,p2);
apilar(p,p3);
apilar(p,p4);
apilar(p,p5);
printf("\n------mostar pila-------\n");
mostrarPila(p);
vaciarPila(p);
printf("\n------mostar pila vacia-------\n");
mostrarPila(p);
printf("\n------------------------------\n");
    return 0;
}
