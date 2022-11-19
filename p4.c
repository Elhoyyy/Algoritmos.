/*
TITULO:
Algoritmos Práctica 4
AUTOR 1: Eloy Sastre Sobrino LOGIN 1: eloy.sastre
        AUTOR 2: Daniel Pérez Mosquera LOGIN 2: daniel.pmosquera
        GROUP: 1.1
DATE: 20/11/2022

 */

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <math.h>
#define TAM 512000

typedef struct {
    int vector[TAM];
    int ultimo;
}monticulo;


void ord_monticulo(int vec[], int n);
void inicializar_semilla();
void aleatorio(int v [], int n);
void ascendente(int v [], int n);
void descendente(int v [], int n);

void print_result_ascendente(int n);
void print_result_aleatorio(int n);
void print_result_descendente(int n);

void intercambiar(int vec[], int a, int b);
void hundir (monticulo *m, int i);
void crear_monticulo (const int vector[], int n, monticulo *m);
void test();
int eliminar_mayor(monticulo *m);


void inicializar_semilla() {
    srand(time(NULL));
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}
void aleatorio(int v [], int n) {/* se generan números pseudoaleatorio entre -n y +n */
    int i, m=2*n+1;
    for (i=0; i < n; i++)
        v[i] = (rand() % m) - n;
}
void ascendente(int v [], int n) {
    int i;
    for (i=0; i < n; i++)
        v[i] = i;
}
void descendente(int v[], int n){
    int i,j=0;
    for(i=n; i>0; i--){
        v[j]=i;
        j++;
    }
}

int main (){
    int n1=500, n2=500, n3=500, i;
    inicializar_semilla();
    test();

    printf("\nTABLAS:\n\n");
    /*
    printf("ALEATORIA:\n\n");

    printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
    for(i=0; i<7;i++){
        print_result_descendente(n1);
        n1=n1*2;

    }

    printf("\n");
    printf("ASCENDENTE:\n\n");

    printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
    for (i = 0; i<7; i++){
        print_result_ascendente(n2);
        n2=n2*2;

    }

    printf("\n");
    printf("DESCENDENTE:\n\n");

    printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
    for( i = 0; i<7; i++){
        print_result_aleatorio(n3);
        n3=n3*2;

    }*/


    return 0;
}


void test(){
    int v1[15], i;
    printf("\nORDENACION DE MONTICULO CON INICIALIZACION ALEATORIA:\n");
    aleatorio(v1,15);
    for (i = 0; i < 15; i++) {
        printf(" %d ", v1[i]);
    }
    ord_monticulo(v1,15);
    printf("\nVector ordenado.\n");
    for (i = 0; i < 15; i++) {
        printf(" %d ", v1[i]);
    }
    printf("\nORDENACION DE MONTICULO CON INICIALIZACION ASCENDENTE:\n");
    ascendente(v1,15);
    for (i = 0; i < 15; i++) {
        printf(" %d ", v1[i]);
    }
    ord_monticulo(v1,15);
    printf("\nVector ordenado.\n");
    for (i = 0; i < 15; i++) {
        printf(" %d ", v1[i]);
    }
    printf("\nORDENACION DE MONTICULO CON INICIALIZACION DESCENDENTE:\n");
    descendente(v1,15);
    for (i = 0; i < 15; i++) {
        printf(" %d ", v1[i]);
    }
    ord_monticulo(v1,15);
    printf("\nVector ordenado.\n");
    for (i = 0; i < 15; i++) {
        printf(" %d ", v1[i]);
    }
}
void ord_monticulo(int vec[], int n) {
    int i; monticulo m ;
    crear_monticulo(vec,n, &m );
    for (i = n; i >= 0; i--){
        vec[i]=eliminar_mayor(&m);
    }
}

void crear_monticulo (const int vector[], int n, monticulo *m){
    int i;
    for ( i = 0; i < n; i++) {
        m->vector[i] = vector[i];
    }
    m->ultimo=n-1;
    for(i = m->ultimo/2; i>=1;i--){
        hundir(m,i);
    }
}

int eliminar_mayor(monticulo *m){
    int x;
    if (m==NULL){
        return m->ultimo=-1;
    }else{
        x=m->vector[1];
        m->vector[1]=m->vector[m->ultimo];
        m->ultimo=m->ultimo-1;
        if(m->ultimo>-1){
            hundir(m,1);
        }
        return  x;
    }
}



void hundir (monticulo *m, int i) {
    int hizq, hder, j=0,aux;
    while (j != i) {
        hizq =  2*i ;
        hder =  2*i+1;
        j = i;
        if (hder <= m->ultimo && (m->vector[hder] > m->vector[i])) {
            i = hder;
        }
        if (hizq <= m->ultimo && (m->vector[hizq] > m->vector[i])) {
            i = hizq;
        }
        aux=m->vector[j];
        m->vector[j]=m->vector[i];
        m->vector[i]=aux;

    }

}

void print_result_aleatorio(int n){
    double t1, t2,ta, tb, t, x, y, z;
    int vector[n], k=1000, i;
    aleatorio(vector, n);
    t1 = microsegundos();
    ord_monticulo(vector, n);
    t2 = microsegundos();
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            aleatorio(vector, n);
            ord_monticulo(vector, n);
        }
        tb = microsegundos();
        t1 = (tb - ta);
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            aleatorio(vector, n);
        }
        tb = microsegundos();
        t2 = tb - ta;
        t = (t1 - t2) / k;
        printf("(*)");

    } else {
        printf("   ");
    }
        x = t /n;
        y = t / pow(n, 1.1);
        z = t / pow(n, 1.2);

    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);

}





void print_result_ascendente(int n) {
    double t1, t2,ta, tb, t, x, y, z;
    int vector[n], k=1000, i;
    ascendente(vector, n);
    t1 = microsegundos();
    ord_monticulo(vector,n);
    t2 = microsegundos();
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            ascendente(vector, n);
            ord_monticulo(vector,n);
        }
        tb = microsegundos();
        t1 = (tb - ta);
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            ascendente(vector, n);
        }
        tb = microsegundos();
        t2 = tb - ta;
        t = (t1 - t2) / k;
        printf("(*)");

    } else {
        printf("   ");
    }

    x = t / pow(n, 0.8);
    y = t /n ;
    z = t / pow(n, 1.2);
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);

}


void print_result_descendente(int n){
    double t1, t2,ta, tb, t, x, y, z;
    int vector[n], k=1000, i;
    descendente(vector, n);
    t1 = microsegundos();
    ord_monticulo(vector,n);
    t2 = microsegundos();
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            descendente(vector, n);
            ord_monticulo(vector,n);
        }
        tb = microsegundos();
        t1 = (tb - ta);
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            descendente(vector, n);
        }
        tb = microsegundos();
        t2 = tb - ta;
        t = (t1 - t2) / k;
        printf("(*)");

    } else {
        printf("   ");
    }
    x = t / pow(n, 1.8);
    y = t / pow(n, 2);
    z = t / pow(n, 2.2);

    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);

}

//Pequeñas funciones auxiliares a otras.

/*void intercambiar(int vec[], int a, int b){
    int aux;
    aux=vec[a];
    vec[a]=vec[b];
    vec[b]=aux;

}
*/
/*
void copiarvectores( int a[], monticulo *m, int tamano) {
    int i;
    for ( i = 0; i < tamano; i++) {
        m->vector[i] = a[i];
    }
    for (int i = 0; i < tamano; i++) {
        printf("%i", m->vector[i]);
    }
}
*/
