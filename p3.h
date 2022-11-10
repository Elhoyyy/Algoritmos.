

#ifndef P3_ALGORITMOS_P3_H
#define P3_ALGORITMOS_P3_H

struct nodo {
    int elem;
    int num_repeticiones;
    struct nodo *izq, *der;
};
typedef struct nodo *posicion;
typedef struct nodo *arbol;

static struct nodo *crearnodo(int e) {
    struct nodo *p = malloc(sizeof(struct nodo));
    if (p == NULL) {
        printf("memoria agotada\n"); exit(EXIT_FAILURE);
    }
    p->elem = e;
    p->num_repeticiones = 1;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

int max(int altura, int altura1);
void escribir(arbol a);

arbol insertar(int e, arbol a){
    if (a == NULL)
        return crearnodo(e);
    else if (e < a->elem)
        a->izq = insertar(e, a->izq);
    else if (e > a->elem)
        a->der = insertar(e, a->der);
    else
        a->num_repeticiones++;
    return a;
}

arbol creararbol(){
    arbol a=NULL;
    return a;
}

int arbolvacio(arbol a){
    if( a==NULL){
        return 1;
    }else{
        return 0;
    }
}

posicion buscar(int e, arbol a){
    if(arbolvacio(a)){
        return NULL;
    }else if(e==a->elem){
        return a;
    }else if(e< a->elem){
        return buscar(e,a->izq);
    }else{
        return buscar(e, a->der);
    }
}


arbol eliminararbol(arbol a){
    if (a==NULL){
        return NULL;
    }
    if(a->izq!=NULL) {
        a->izq= eliminararbol(a->izq);

    }
    if(a->der!=NULL){
        a->der=eliminararbol(a->der);
    }
    free(a);
    return a=NULL;

}

posicion hijoizquierdo(arbol a){
    return a->izq;
}
posicion hijoderecho(arbol a){
    return a->der;
}

int elemento (posicion pos){
    return pos->elem;
}
int numrepeticion (posicion pos){
    return pos->num_repeticiones;
}

int altura(arbol a) {
    if (arbolvacio(a)) {
        return -1;

    }else{
        return 1+ max (altura(a->izq), altura(a->der));
    }
}

int max(int altura, int altura1) {
    if(altura>altura1){
        return altura;
    }else{
        return altura1;
    }
}

void visualizar(arbol a){
    if (!arbolvacio(a)){
        printf("Arbol:");
        escribir(a);
    }else{
        printf("Arbol vacio: ()\n");
    }
}

void escribir(arbol a){
    if(a->izq!=NULL){
        printf("(");
        escribir(a->izq);
        printf(")");
    }
    printf(" %d ",a->elem);
    if(a->der!=NULL){
        printf("(");
        escribir(a->der);
        printf(")");
    }
}
#endif //P3_ALGORITMOS_P3_H
