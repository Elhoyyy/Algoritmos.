
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
#include "p3.h"

void aleatorio(int v [], int n);
void inicializar_semilla();
void test(int vec[]);
double result_insercion(int n);
double result_busqueda(int n);
void print_time(int n, double insercion[],double busqueda[]);
void print_result(double insercion, int n);

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
    int n1, n2, n3,i;
    double insercion[7],busqueda[7];
    inicializar_semilla();
    n3=2000,n2=2000,n1=2000;
    for(i=0; i<7;i++){
        insercion[i]=result_insercion(n3);
        busqueda[i]=result_busqueda(n3);
        n3=n3*2;
    }

    printf("TABLAS DE TIEMPO:\n\n");

    printf("\t   n\t     t_ins(n)\t    t_bus(n)\n");

    print_time(n1,insercion,busqueda);



    printf("\nINSERCION EN ARBOL VACIO:\n\n");


    printf("\t   n\t        t(n)\t  t(n)/f(n)\t t(n)/g(n)\tt(n)/h(n)\t\n");
    for (i= 0; i < 7; i++) {
        print_result(insercion[i],n2);
        n2=n2*2;
    }
    printf("\n");
    printf("BUSQUEDA EN ESE MISMO ARBOL:\n\n");


    printf("\t   n\t        t(n)\t  t(n)/f(n)\t t(n)/g(n)\tt(n)/h(n)\t\n");
    for (i = 0; i < 7; i++) {
        print_result(busqueda[i],n1);
        n1 = n1 * 2;

    }
    return 0;

}


void test(int vec[]){
    arbol a;
    int i;
    a=creararbol();
    visualizar(a);

    printf("Altura del arbol : %d\n", altura(a));
    for(i=0;i<6;i++) {
        printf("inserto un %d\n", vec[i]);
        a= insertar(vec[i], a);

    }
    visualizar(a);

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
    visualizar(a);
    printf("Altura del arbol : %d\n", altura(a));

}





double result_insercion(int n){
    double t1, t2, t;
    arbol a;
    int vector[n],j;
    aleatorio(vector, n);
    a=creararbol();
    t1 = microsegundos();
    for(j=0;j<n;j++){
        a=insertar(vector[j], a);
    }
    t2 = microsegundos();
    eliminararbol(a);
    t = t2 - t1;
        return t;
}


double result_busqueda(int n){
    double t1, t2, t;
    arbol a;
    int vector[n],vector2[n],j;
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
    eliminararbol(a);
    t = t2 - t1;
    return t;
}
void print_time(int n, double insercion[],double busqueda[]){
    for(int i=0;i<7;i++){
        if(insercion[i]>500&&busqueda[i]>500){
        printf("\t%d\t        %.0f \t      %.0f\n",n,insercion[i],busqueda[i]);
    }
        n=n*2;
    }
}
void print_result(double insercion, int n){
    double x,y,z;
    if(insercion>500){
        x = insercion / n;
        y = insercion / pow(n, 1.18);
        z = insercion / pow(n, 1.5);
        printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, insercion, x, y, z);
    }

}
