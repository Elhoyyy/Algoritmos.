#include <stdio.h>
#define TAM 512000
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int vector[TAM];
    int ultimo;
}monticulo;

void ord_monticulo(int vec[], int n);
void inicializar_semilla();
void aleatorio(int v [], int n);
void intercambiar(int vec[], int a, int b);
void copiarvectores(const int a[], int b[], int tamano);
void hundir (monticulo *m, int i);
void crear_monticulo (int vector[], monticulo *m);
void test();
int eliminar_mayor(monticulo *m);


void inicializar_semilla() {
    srand(time(NULL));
}
void aleatorio(int v [], int n) {/* se generan números pseudoaleatorio entre -n y +n */
    int i, m=2*n+1;
    for (i=0; i < n; i++)
        v[i] = (rand() % m) - n;
}

int main (){
    inicializar_semilla();
    test();
}


void test(){
    int v1[15], i;
    printf("\nORDENACION DE MONTICULO CON INICIALIZACION ALEATORIA.:\n");
    aleatorio(v1,15);
    for (i = 0; i < 15; i++) {
        printf(" %d ", v1[i]);
    }
    ord_monticulo(v1,15);
    printf("Vector ordenado.\n");
    for (i = 0; i < 15; i++) {
        printf(" %d ", v1[i]);
    }

}



void ord_monticulo(int vec[], int n) {
    int i; monticulo *m ;
    crear_monticulo(vec, m );
    for (i = n; i < 1; i--){
        vec[i]=eliminar_mayor(m);
    }
}

void crear_monticulo (int vector[], monticulo *m){
    int n=0,i;
    copiarvectores(vector,m->vector,15);
    m->ultimo=n;
    for(i = m->ultimo/2; i<1;i--){
        hundir(m,i);
    }
}

int eliminar_mayor(monticulo *m){
    int x;
    if (m==NULL){
        return -1;
    }else{
        x=m->vector[1];
        m->vector[1]=m->vector[m->ultimo];
        m->ultimo=m->ultimo-1;
        if(m->ultimo>0){
            hundir(m,1);
        }
        return  x;
    }
}


void hundir (monticulo *m, int i) {
    int hizq, hder, j = 0;
    while (i != j) {
        hizq = 2 * i;
        hder = 2 * i + 1;
        j = 1;
        if (hder <= m->ultimo && m->vector[hder] > m->vector[i]) {
            i = hizq;
        }
        if (hizq <= m->ultimo && m->vector[hizq] > m->vector[i]) {
            i = hizq;
        }
        intercambiar(m->vector, j, i);

    }

}

//Pequeñas funciones auxiliares a otras.

void intercambiar(int vec[], int a, int b){
    int aux;
    aux=vec[a];
    vec[a]=vec[b];
    vec[b]=aux;

}


void copiarvectores(const int a[], int b[], int tamano) {
    for (int i = 0; i < tamano; i++) {
        b[i] = a[i];
    }
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}
