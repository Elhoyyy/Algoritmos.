
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
#include "p3.h"

void aleatorio(int v [], int n);
void inicializar_semilla();
void test(int vec[]);


void inicializar_semilla() {
    srand(time(NULL));
}


void aleatorio(int v [], int n) {/* se generan números pseudoaleatorio entre -n y +n */
    int i, m=2*n+1;
    for (i=0; i < n; i++)
        v[i] = (rand() % m) - n;
}

void main (){
    int vector[6]={3,1,2,5,4,5};
    test(vector);
}


void test(int vec[]){
    arbol a;
    int i;
    a=creararbol();
    printf("Altura del arbol : %d\n", altura(a));
    for(i=0;i<6;i++) {
        printf("inserto un %d\n", vec[i]);
        a= insertar(vec[i], a);

    }
    if(!arbolvacio(a)) {
        printf("Arbol:");
        visualizar(a);
    }else{
        printf("Arbol vacio:");
        visualizar(a);
    }


    printf("\nAltura del arbol : %d\n", altura(a));
    int vector2[6]={3,1,2,5,4,6};
    for(i=0;i<6;i++){
        if(buscar(vector2[i],a)==NULL){
        printf("busco %d y no encuentro nada\n", vector2[i]);
    }else{
            printf("busco %d y encuentro %d repetido: %d veces\n", vector2[i],vector2[i],numrepeticion(buscar(vector2[i],a)));
        }
    }

    printf("borro todos nodos liberando la memoria: \n");
    eliminararbol(a);
    if(!arbolvacio(a)) {
        printf("Arbol:");
        visualizar(a);
    }else{
        printf("Arbol vacio:");
        visualizar(a);
    }

    printf("Altura del arbol : %d\n", altura(a));



}



