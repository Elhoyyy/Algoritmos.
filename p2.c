#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
void inicializar_semilla();
void ord_ins(int v[], int n);
void aleatorio(int v [], int n);
void ascendente(int v [], int n);
void descendente(int v [], int n);
void test ();
void print_result_aleatorio(int n);
void print_result_ascendente(int n);
void print_result_descendente(int n);



void ord_ins(int v[], int n){
    int i,j,x;
    for (i=1;i<n;i++) {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = x;
    }
}

int main(){
    int n1=500,n2=500,n3=500,i;
    inicializar_semilla();
    test();
    printf("\n\n");
    printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
    for( i=0;i<10;i++){
        print_result_aleatorio(n1);
        n1=n1*2;
    }
    printf("\n");
    printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
    for( i=0;i<10;i++){
        print_result_ascendente(n2);
        n2=n2*2;
    }
    printf("\n");

    printf("\t      n\t         t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
    for( i=0;i<10;i++){
        print_result_descendente(n3);
        n3=n3*2;
    }
    return 0;
};

void inicializar_semilla() {
    srand(time(NULL));
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
    for(i=10; i>0; i--){
        v[j]=i;
        j++;
    }
}
void test (){
    int v1[10],v2[17],i;
    descendente(v1, 10); //Inicializo el vector con elementos desecendentes.
    printf("\nOrdenacion por insercion con inicializacion descendente: \n");
    for(i=0;i<10; i++){
        printf(" %d ", v1[i]);
    }
    printf("\n");
    printf("Vector ordenado: \n");
    ord_ins(v1, 10);
    for(i=0;i<10; i++){
        printf(" %d ", v1[i]);
    }
    printf("\n\n");
    aleatorio(v2, 17);
    printf("Ordenacion por insercion con inicializacion aleatoria:\n");
    for(i=0; i<17; i++){
        printf(" %d ", v2[i]);
    }
    printf("\n");
    ord_ins(v2, 17);
    printf("Vector ordenado.\n ");
    for(i=0; i<17; i++){
        printf(" %d ", v2[i]);
    }
    printf("\n\n");

}


double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void print_result_aleatorio(int n){
    double t1, t2,ta, tb, t, x, y, z;
    int vector[n];
    int k=1000;
    t1=microsegundos();
    t2=microsegundos();
    t=t2-t1;
    if (t < 500){
        ta=microsegundos();
        for(int i=0;i<k;i++){
            aleatorio(vector, n);
            ord_ins(vector,n);
        }
        tb=microsegundos();
        t1=(tb-ta);
        ta=microsegundos();
        for(int i=0;i<k;i++){
            aleatorio(vector, n);
        }
        tb=microsegundos();
        t2=tb-ta;
        t=(t1-t2)/k;
        printf("(*)");

    }else{
        printf("   ");
    }
    x = t / pow (n, 1.8);
    y = t/ pow(n,2);
    z = t / pow ( n, 2.2);
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);
}


void print_result_ascendente(int n){
    double t1, t2, t, x, y, z;
    int k=1000;
    t1=microsegundos();
    t2=microsegundos();
    t=t2-t1;
    if (t < 500){
        t1=microsegundos();
        for(int i=0;i<k;i++){

        }
        t2=microsegundos();
        t=(t2-t1)/k;
        printf("(*)");

    }else{
        printf("   ");
    }
    //x =;
    y = t/ pow(n,2);
    //z =;
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);
}

void print_result_descendente(int n){
    double t1, t2, t, x, y, z;
    int k=1000;
    t1=microsegundos();
    t2=microsegundos();
    t=t2-t1;
    if (t < 500){
        t1=microsegundos();
        for(int i=0;i<k;i++){

        }
        t2=microsegundos();
        t=(t2-t1)/k;
        printf("(*)");

    }else{
        printf("   ");
    }
    //x = t/n ;
    y =t/ pow(n,2);
    //z =t / pow (n,2);
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);

}
