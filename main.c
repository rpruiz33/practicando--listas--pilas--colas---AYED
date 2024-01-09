#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///crear una lista insertarListaOrdenado y buscar elementos siempre apuntando hacia void

typedef struct NodoE * NodoPtr;
typedef struct ListaE * ListaPtr;

struct NodoE{
void *dato;
NodoPtr sgte;

};
struct ListaE{
NodoPtr primero;
};

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

    if (lista->primero == NULL || lista->primero->dato >dato) {
        no->sgte = lista->primero;
        lista->primero = no;
        return 1;
    }

    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;

    while (actual != NULL && actual->dato < dato) {
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
        printf("%d ", actual->dato);
        actual = actual->sgte;
    }
}

int buscarElementos(ListaPtr lista , void * busco){
    int pos=0;
    NodoPtr aux=crearNodo(NULL);
    aux=lista->primero;
    do{
         aux=aux->sgte;
         pos++;
    }while(aux->dato!=busco && aux!=NULL );
    printf("encontro el dato que es %d", aux->dato);

    return pos;
}

int remover(ListaPtr l,void *dato){

NodoPtr proximoCpy;

NodoPtr aux=crearNodo(NULL);
int pos=buscarElementos(l , dato);
printf ("------1\n");

for (int i=0;i<pos;i++){
        if (i==0){
            aux=l->primero;
        }
        else{
         aux=aux->sgte;
        }

}
printf ("------1\n");
proximoCpy = aux->sgte->sgte; // 'proximoCpy' aponta para o elemento posterior ao que será removido
printf ("------1\n");
        memcpy(dato, proximoCpy->dato, sizeof(dato));

printf ("------1\n");
    free(aux->sgte->dato); // Remove o VALOR do elemento (Célula) entre 'f' e 'proximoCpy', que pertence justamente o elemento que o usuário deseja remover
    free(aux->sgte); // Remove o ELEMENTO entre 'f' e 'proximoCpy', que é justamente o elemento que o usuário deseja remover
    /*aux->sgte = proximoCpy; // Portanto lique 'f' em 'proximoCpy'
printf ("------1\n");*/

return 1;
}


/*
int remover (Lista lista, int pos, void *backup) {

    if (!lista || lista->tamanio<= 0 || pos < 0 || pos >= lista->tamanio) // lista vazia ou nula ou posição inválida
        return FALSE;

    // Remove da última posição
    if (pos == lista->tamanio - 1)
        return removerFinal(lista, backup);

    // O usiário deseja remover um elemento do início
    if (pos == 0)
        return removerInicio(lista, backup);

    // Remover algum elemento no MEIO da lista
    Nodo f = NULL, proximoCpy;
    for (int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->proximo;
    }
    // Nesse momento 'f' aponta para o elemento anterior ao que será removido

    proximoCpy = f->proximo->proximo; // 'proximoCpy' aponta para o elemento posterior ao que será removido
    memcpy(backup, f->proximo->data, lista->tamDelDatoEnBytes);

    free(f->proximo->data); // Remove o VALOR do elemento (Célula) entre 'f' e 'proximoCpy', que pertence justamente o elemento que o usuário deseja remover
    free(f->proximo); // Remove o ELEMENTO entre 'f' e 'proximoCpy', que é justamente o elemento que o usuário deseja remover
    f->proximo = proximoCpy; // Portanto lique 'f' em 'proximoCpy'
    lista->tamanio--;
    return TRUE;
}*/
int main()
{
ListaPtr l=crearLista();
insertarListaOrdenado(l,23);
insertarListaOrdenado(l,24);
insertarListaOrdenado(l,26);
insertarListaOrdenado(l,25);
buscarElementos(l,24);
mostrarLista(l);

remover(l,24);

mostrarLista(l);
    return 0;
}
