
/*
TITULO: Algoritmos Práctica 1
AUTOR 1: Eloy Sastre Sobrino LOGIN 1: eloy.sastre
AUTOR 2: Daniel Pérez Mosquera LOGIN 2: daniel.pmosquera
GROUP: 1.1
DATE: 20/10/2022
*/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdlib.h>
#define UMBRAL 1
void inicializar_semilla();
void ord_ins(int v[], int n);
void aleatorio(int v [], int n);
void ascendente(int v [], int n);
void descendente(int v [], int n);
void test ();
void Medianatres (int v[], int i, int j);
void print_result_aleatorio(int n);
void print_result_ascendente(int n);
void print_result_descendente(int n);
void ord_rapida(int v [], int n);
void intercambiar(int vec[], int a, int b);
void rapida_aux(int v[ ], int izq, int der);
void Quicksort ( int v[], int n);



void ord_ins(int v[], int n){
    int i,j,x;
    for (i=1;i<n;i++) {
        x = v[i];
        j = i - 1;
        while (j > -1 && v[j] > x) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = x;
    }
}

int main(){
    int  n1,n2,n3,i;
    inicializar_semilla();
        test();
        n1=500,n2=500,n3=500;

        printf("TABLAS:\n\n");
        printf("ALEATORIA:\n\n");


        printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_aleatorio(n1);
            n1 = n1 * 2;
        }
        printf("\n");
        printf("ASCENDENTE:\n\n");


        printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_ascendente(n2);
            n2 = n2 * 2;
        }
        printf("\n");
        printf("DESCENDENTE:\n\n");


        printf("\t      n\t         t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_descendente(n3);
            n3 = n3 * 2;
        }

    return 0;
}

void Medianatres (int v[], int i, int j){
    int centro = (i+j) /2;
    if( v[i]>v[centro]){
     intercambiar (v, i,centro);
        }
    if (v[i]>v[j]){
        intercambiar(v,i,j);
    }
    if (v[centro]>v[j]) {
        intercambiar(v, centro, j);
    }
    intercambiar(v, centro, i-1);
}

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
    for(i=n; i>0; i--){
        v[j]=i;
        j++;
    }
}
void test () {
    int v1[20], v2[17], i;
    descendente(v1, 20);
        printf("\nORDENACION POR QUICKSORT:\n");

        printf("\nOrdenacion por quicksort con inicializacion descendete:\n");


    for (i = 0; i < 20; i++) {
        printf(" %d ", v1[i]);
    }

    printf("\n");
    printf("Vector ordenado: \n");

        Quicksort(v1, 20);


    for (i = 0; i < 20; i++) {
        printf(" %d ", v1[i]);
    }

    printf("\n\n");
    aleatorio(v2, 17);

      printf("\nOrdenacion rapida con inicializacion aleatoria:\n");


    for (i = 0; i < 17; i++) {
        printf(" %d ", v2[i]);
    }

    printf("\n");

        Quicksort(v2, 17);


    printf("Vector ordenado.\n ");

    for (i = 0; i < 17; i++) {
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
    int vector[n], k=1000, i;
    aleatorio(vector, n);
    t1 = microsegundos();
    ord_ins(vector,n);
    t2 = microsegundos();
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            aleatorio(vector, n);
            ord_ins(vector,n);


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





void print_result_ascendente(int n) {
    double t1, t2,ta, tb, t, x, y, z;
    int vector[n], k=1000, i;
    ascendente(vector, n);
    t1 = microsegundos();
    ord_ins(vector,n);

    t2 = microsegundos();
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            ascendente(vector, n);

            ord_ins(vector,n);

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


void print_result_descendente(int n ){
    double t1, t2,ta, tb, t, x, y, z;
    int vector[n], k=1000, i;
    descendente(vector, n);
    t1 = microsegundos();
    ord_ins(vector,n);

    t2 = microsegundos();
    t = t2 - t1;
    if (t < 500) {
        ta = microsegundos();
        for ( i = 0; i < k; i++) {
            descendente(vector, n);
            ord_ins(vector,n);

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

void rapida_aux(int v[ ], int izq, int der){
    int x,pivote,i,j;

    if ((izq+UMBRAL)<= der ){
        x=rand() % (der-izq+1)+izq;
        pivote=v[x];

        intercambiar(v, izq, x);
        i=izq+1;
        j=der;
        while(i<=j) {
            while (i <= der && v[i] < pivote) {
                i++;
            }
            while (v[j] > pivote) {
                j--;
            }
            if (i <= j) {
                intercambiar(v, i, j);
                i++;
                j--;
            }
        }
        intercambiar(v, izq, j);
        rapida_aux(v, izq, j-1);
        rapida_aux(v, j+1, der);

    }
}

void Qsort ( int v[], int izq, int der ){
    int pivote, i, j ;
        if ( (izq + UMBRAL) <= der ) {
            Medianatres(v, izq, der);
            pivote = v[der-1];
            i=izq;
            j= der-1;
            do {
                do {
                    i ++;
                } while (v[i] >= pivote);

                do {
                    j --;
                } while (v[j] <= pivote);

                intercambiar(v, i , j);
            }
                while ( j <= i);
            intercambiar(v, i , j);
            intercambiar(v, i , der-1);
            Qsort(v, izq, i-1);
            Qsort(v, i+1, der);
        }
}

void intercambiar(int vec[], int a, int b){
    int aux;
    aux=vec[a];
    vec[a]=vec[b];
    vec[b]=aux;

}
void ord_rapida(int v [], int n) {
    rapida_aux(v, 0, n-1);
    if (UMBRAL > 1)
        ord_ins(v, n);
}

void Quicksort ( int v[], int n){
    Qsort(v, 0, n-1);
    if ( UMBRAL>1)
    ord_ins(v, n);
}
