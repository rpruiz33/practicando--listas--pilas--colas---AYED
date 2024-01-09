#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///crear una lista insertarListaOrdenado y buscar elementos siempre apuntando hacia void y castendo como una struct

typedef struct NodoE * NodoPtr;
typedef struct ListaE * ListaPtr;
typedef struct PersonaE * PersonaPtr;

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


PersonaPtr crearPersona(int edad,char nombre[30]){
PersonaPtr p=malloc(sizeof(struct PersonaE));
p->edad=edad;
strcpy(p->nombre, nombre);
return p;

}
char * getNombre(PersonaPtr p){

return p->nombre;
}

NodoPtr crearNodo(void* dato){

if(dato==NULL){
    return 0;
}

NodoPtr no=malloc(sizeof(struct NodoE));
no->dato=dato;
no->sgte=NULL;
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
        printf("-----------------x1\n");
        return 1;
    }

    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;

    while (actual != NULL &&  strcmp(((PersonaPtr)actual->dato)->nombre,  ((PersonaPtr)no->dato)->nombre)<0) {
            printf("-----------------x2\n");
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


void mostrarLista(ListaPtr l){
    NodoPtr actual = l->primero;

    while (actual != NULL){
        printf("%s ", ((PersonaPtr)actual->dato)->nombre);
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
    };
    printf("encontro el dato que es %d", ((PersonaPtr)aux->dato)->edad);

    return pos;
}

int remover(ListaPtr l,void *dato){

NodoPtr anterior=NULL;
NodoPtr actual=l->primero;
while(actual!=NULL && ((PersonaPtr)actual->dato)->edad!=((PersonaPtr)dato)->edad){
    anterior=actual;
    actual=actual->sgte;
    }
    if(anterior==NULL){
        l->primero=actual;
    }
    else{
        anterior->sgte=actual->sgte;
    }

}
int main()
{
PersonaPtr p1=crearPersona(33,"rober");
PersonaPtr p2=crearPersona(32,"carlos");
printf("-----------------------------1");

PersonaPtr p3=crearPersona(3,"tony");

PersonaPtr p4=crearPersona(44,"marcia");

ListaPtr l=crearLista();
insertarListaOrdenado(l,p1);
insertarListaOrdenado(l,p2);
insertarListaOrdenado(l,p3);
insertarListaOrdenado(l,p4);
mostrarLista(l);
printf("-----\n");
buscarElementos(l,p1);
printf("-----\n");
mostrarLista(l);
printf("-----\n");
remover(l,p3);
printf("-----\n");
mostrarLista(l);
    return 0;
}
