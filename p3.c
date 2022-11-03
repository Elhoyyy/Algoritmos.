
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
#include "p3.h"

void aleatorio(int v [], int n);
void inicializar_semilla();
void test(int vec[]);
void print_result_insercion(int n,arbol a);
void print_result_busqueda(int n,arbol a);
void print_tiempo_insercion(int n, arbol a);
void print_tiempo_busqueda(int n , arbol a);

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
    int j, n1, n2, n3, i;
    arbol a;
    a= creararbol();
    inicializar_semilla();
        n1 = 500, n2 = 500, n3=500;

        printf("TABLAS DE TIEMPO:\n\n");

        printf("\t   n\t     t_ins(n)\t    t_bus(n)\n");
        for(i=0; i<7; i++){
            print_tiempo_insercion(n3, a);
            print_tiempo_busqueda(n3,a);
            n3=n3*2;
        }



        printf("\nINSERCION EN ARBOL VACIO:\n\n");


        printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_insercion(n1, a);
            n1 = n1 * 2;
        }
        printf("\n");
        printf("BUSQUEDA EN ESE MISMO ARBOL:\n\n");


        printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_busqueda(n2, a);
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
    /*eliminararbol(a);
    if(!arbolvacio(a)) {
        printf("Arbol:");
        visualizar(a);
    }else{
        printf("Arbol vacio:");
        visualizar(a);
    }

    printf("Altura del arbol : %d\n", altura(a));*/
    
}



void print_result_insercion(int n, arbol a){
    double t1, t2,ta, tb, t, x, y, z;
    int vector[n], k=1000, i;
        aleatorio(vector, n);

        t1 = microsegundos();
        a= insertar(vector[n], a);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            ta = microsegundos();
            for ( i = 0; i < k; i++) {
                aleatorio(vector, n);
                insertar(vector[n], a);
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
        x = t / pow(n, 1.8);
        y = t / pow(n, 2);
        z = t / pow(n, 2.2);
        printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);

}

void print_result_busqueda(int n, arbol a){

    double t1, t2,ta, tb, t, x, y, z;

    int vector[n], k=1000, i;
    aleatorio(vector, n);

    t1 = microsegundos();
    a= buscar(vector[n], a);
    t2 = microsegundos();
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            aleatorio(vector, n);
            buscar(vector[n], a);
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
    x = t / pow(n, 1.8);
    y = t / pow(n, 2);
    z = t / pow(n, 2.2);
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);

}

void print_tiempo_insercion(int n , arbol a){
    double t1, t2,ta, tb, t;

    int vector[n], k=1000, i;
    aleatorio(vector, n);

    t1 = microsegundos();
    a= insertar(vector[n], a);
    t2 = microsegundos();
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            aleatorio(vector, n);
            a=insertar(vector[n], a);
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

    } else {
        printf("   ");
    }
    printf("%12d%15.3f", n, t);

}

void print_tiempo_busqueda(int n , arbol a) {
    double t1, t2, ta, tb, t;

    int vector[n], k = 1000, i;
    aleatorio(vector, n);

    t1 = microsegundos();
    buscar(vector[n], a);
    t2 = microsegundos();
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for (i = 0; i < k; i++) {
            aleatorio(vector, n);
            buscar(vector[n], a);
        }
        tb = microsegundos();
        t1 = (tb - ta);
        ta = microsegundos();
        for (i = 0; i < k; i++) {
            aleatorio(vector, n);
        }
        tb = microsegundos();
        t2 = tb - ta;
        t = (t1 - t2) / k;

    } else {
        printf("   ");
    }
    printf("%15.3f\n", t);
}







