
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
#include "p3.h"

void aleatorio(int v [], int n);
void inicializar_semilla();
void test(int vec[]);
void print_result_insercion(int n);
void print_result_busqueda(int n);
void print_tiempo_insercion(int n);
void print_tiempo_busqueda(int n);

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

int main () {
    int vector[6] = {3, 1, 2, 5, 4, 5};
    test(vector);
    int n1, n2, n3, i=0;
    inicializar_semilla();
    n1 = 500, n2 = 500, n3=500;

    printf("TABLAS DE TIEMPO:\n\n");

    printf("\t   n\t     t_ins(n)\t    t_bus(n)\n");
    for(i=0; i<7; i++){
        print_tiempo_insercion(n3);
        print_tiempo_busqueda(n3);
        n3=n3*2;
    }


    
        printf("\nINSERCION EN ARBOL VACIO:\n\n");


        printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_insercion(n1);
            n1 = n1 * 2;
        }
        printf("\n");
        printf("BUSQUEDA EN ESE MISMO ARBOL:\n\n");


        printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_busqueda(n2);
            n2 = n2 * 2;

    }
    return 0;
    
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
    a=eliminararbol(a);
    if(!arbolvacio(a)) {
        printf("Arbol:");
        visualizar(a);
    }else{
        printf("Arbol vacio:");
        visualizar(a);
    }
    printf("Altura del arbol : %d\n", altura(a));

}



void print_result_insercion(int n){
    double t1, t2,ta, tb, t, x, y, z;
    arbol a;
    int vector[n], k=1000, i,j;
    aleatorio(vector, n);
    a=creararbol();
    t1 = microsegundos();
    for(j=0;j<n;j++){
        a=insertar(vector[j], a);
    }
    t2 = microsegundos();
    a= eliminararbol(a);
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            a=creararbol();
            aleatorio(vector, n);
            for(int p=0;p<n;p++){
                a=insertar(vector[p], a);
            }
            a= eliminararbol(a);
        }
        tb = microsegundos();
        t1 = (tb - ta);
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            a=creararbol();
            aleatorio(vector, n);
            a= eliminararbol(a);
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

void print_result_busqueda(int n){

    double t1, t2,ta, tb, t, x, y, z;
    arbol a;
    int vector[n],vector2[n], k=1000, i,j;
    aleatorio(vector, n);
    aleatorio(vector2,n);
    a=creararbol();
    for(j=0;j<n;j++){
        a=insertar(vector[j], a);
    }
    t1 = microsegundos();
    for(j=0;j<n;j++){
        buscar(vector2[j], a);
    }
    t2 = microsegundos();
    a= eliminararbol(a);
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            a=creararbol();
            aleatorio(vector, n);
            aleatorio(vector2,n);
            for(j=0;j<n;j++){
                a=insertar(vector[j], a);
            }
            for(j=0;j<n;j++){
                buscar(vector2[j], a);
            }
            a= eliminararbol(a);
        }
        tb = microsegundos();
        t1 = (tb - ta);
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            a=creararbol();
            aleatorio(vector, n);
            aleatorio(vector2,n);
            for(j=0;j<n;j++){
                a=insertar(vector[j], a);
            }
            a= eliminararbol(a);
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

void print_tiempo_insercion(int n){
    double t1, t2,ta, tb, t;
    arbol a;
    int vector[n], k=1000, i,j;
    aleatorio(vector, n);
    a=creararbol();
    t1 = microsegundos();
    for(j=0;j<n;j++){
        a=insertar(vector[j], a);
    }
    t2 = microsegundos();
    a= eliminararbol(a);
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            a=creararbol();
            aleatorio(vector, n);
            for(int p=0;p<n;p++){
                a=insertar(vector[p], a);
            }
            a= eliminararbol(a);
        }
        tb = microsegundos();
        t1 = (tb - ta);
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            a=creararbol();
            aleatorio(vector, n);
            a= eliminararbol(a);
        }
        tb = microsegundos();
        t2 = tb - ta;
        t = (t1 - t2) / k;

    } else {
        printf("   ");
    }
    printf("%12d%15.3f",n,t);

}

void print_tiempo_busqueda(int n){

    double t1, t2,ta, tb, t;
    arbol a;
    int vector[n],vector2[n], k=1000, i,j;
    aleatorio(vector, n);
    aleatorio(vector2,n);
    a=creararbol();
    for(j=0;j<n;j++){
        a=insertar(vector[j], a);
    }
    t1 = microsegundos();
    for(j=0;j<n;j++){
        buscar(vector2[j], a);
    }
    t2 = microsegundos();
    a= eliminararbol(a);
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            a=creararbol();
            aleatorio(vector, n);
            aleatorio(vector2,n);
            for(j=0;j<n;j++){
                a=insertar(vector[j], a);
            }
            for(j=0;j<n;j++){
                buscar(vector2[j], a);
            }
            a= eliminararbol(a);
        }
        tb = microsegundos();
        t1 = (tb - ta);
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            a=creararbol();
            aleatorio(vector, n);
            aleatorio(vector2,n);
            for(j=0;j<n;j++){
                a=insertar(vector[j], a);
            }
            a= eliminararbol(a);
        }
        tb = microsegundos();
        t2 = tb - ta;
        t = (t1 - t2) / k;

    } else {
        printf("   ");
    }
    printf("%15.3f\n",t);

}








