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
void test (int j);
void print_result_aleatorio(int n, int j);
void print_result_ascendente(int n, int j);
void print_result_descendente(int n, int j);
void ord_rapida(int v [], int n);
void intercambiar(int vec[], int a, int b);
void rapida_aux(int v[ ], int izq, int der);



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
    int j;
    for(j =0; j<2; j++) {
        test(j);
        int n1=500,n2=500,n3=500,i;
        inicializar_semilla();

        printf("TABLAS:\n\n");
        printf("ALEATORIA:\n\n");


        printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_aleatorio(n1, j);
            n1 = n1 * 2;
        }
        printf("\n");
        printf("ASCENDENTE:\n\n");


        printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_ascendente(n2, j);
            n2 = n2 * 2;
        }
        printf("\n");
        printf("DESCENDENTE:\n\n");


        printf("\t      n\t         t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
        for (i = 0; i < 7; i++) {
            print_result_descendente(n3, j);
            n3 = n3 * 2;
        }
    }
    return 0;
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
void test (int j) {
    int v1[20], v2[17], i;
    descendente(v1, 20);
    if (j == 0) {
        printf("\nORDENACION POR INSERCION:\n");

        printf("\nOrdenacion por insercion con inicializacion descendete:\n");
    } else {
        printf("\nORDENACION RAPIDA:\n");

        printf("\nOrdenacion rapida con inicializacion descendente:\n");
    }
    for (i = 0; i < 20; i++) {
        printf(" %d ", v1[i]);
    }
    printf("\n");
    printf("Vector ordenado: \n");
    if (j == 0) { ord_ins(v1, 20); }
    else {
        ord_rapida(v1, 20);
    }
    for (i = 0; i < 20; i++) {
        printf(" %d ", v1[i]);
    }
    printf("\n\n");
    aleatorio(v2, 17);
    if (j == 0) {
        printf("\nOrdenacion por insercion con inicializacion aleatoria:\n");
    } else {
        printf("\nOrdenacion rapida con inicializacion aleatoria:\n");
    }
    for (i = 0; i < 17; i++) {
        printf(" %d ", v2[i]);
    }
    printf("\n");
    if (j == 0) { ord_ins(v2, 17); }
    else {
        ord_rapida(v2, 17);
    }
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

void print_result_aleatorio(int n,  int j){
    double t1, t2,ta, tb, t, x, y, z;
    int vector[n];
    int k=1000;
    if(j==0){
        aleatorio(vector, n);
        t1 = microsegundos();
        ord_ins(vector, n);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            ta = microsegundos();
            for (int i = 0; i < k; i++) {
                aleatorio(vector, n);
                ord_ins(vector, n);
            }
            tb = microsegundos();
            t1 = (tb - ta);
            ta = microsegundos();
            for (int i = 0; i < k; i++) {
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



    }else {
        aleatorio(vector, n);
        t1 = microsegundos();
        ord_rapida(vector, n);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            ta = microsegundos();
            for (int i = 0; i < k; i++) {
                aleatorio(vector, n);
                ord_rapida(vector, n);
            }
            tb = microsegundos();
            t1 = (tb - ta);
            ta = microsegundos();
            for (int i = 0; i < k; i++) {
                aleatorio(vector, n);
            }
            tb = microsegundos();
            t2 = tb - ta;
            t = (t1 - t2) / k;
            printf("(*)");

        } else {
            printf("   ");
        }
        x = t / n;
        y = t / pow(n, 1.1);
        z = t / pow(n, 1.2);
        printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);
    }

}

void print_result_ascendente(int n, int j) {
    double t1, t2, ta, tb, t, x, y, z;
    int vector[n];
    int k = 1000;
    if (j == 0) {
        ascendente(vector, n);
        t1 = microsegundos();
        ord_ins(vector, n);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            ta = microsegundos();
            for (int i = 0; i < k; i++) {
                ascendente(vector, n);
                ord_ins(vector, n);
            }
            tb = microsegundos();
            t1 = (tb - ta);
            ta = microsegundos();
            for (int i = 0; i < k; i++) {
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
        y = t / n;
        z = t / pow(n, 1.2);
    } else {
        ascendente(vector, n);
        t1 = microsegundos();
        ord_rapida(vector, n);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            ta = microsegundos();
            for (int i = 0; i < k; i++) {
                ascendente(vector, n);
                ord_rapida(vector, n);
            }
            tb = microsegundos();
            t1 = (tb - ta);
            ta = microsegundos();
            for (int i = 0; i < k; i++) {
                ascendente(vector, n);
            }
            tb = microsegundos();
            t2 = tb - ta;
            t = (t1 - t2) / k;
            printf("(*)");

        } else {
            printf("   ");
        }
        x = t / pow(n, 0.9);
        y = t / pow(n, 1.05);
        z = t / pow(n, 1.2);
    }
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);
}


void print_result_descendente(int n , int j){
    double t1, t2,ta, tb, t, x, y, z;
    int vector[n];
    int k=1000;
    int i;
    if(j==0) {
        descendente(vector, n);
        t1 = microsegundos();
        ord_ins(vector, n);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            ta = microsegundos();
            for (i = 0; i < k; i++) {
                descendente(vector, n);
                ord_ins(vector, n);
            }
            tb = microsegundos();
            t1 = (tb - ta);
            ta = microsegundos();
            for (i = 0; i < k; i++) {
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


    }else {
        descendente(vector, n);
        t1 = microsegundos();
        ord_rapida(vector, n);
        t2 = microsegundos();
        t = t2 - t1;
        if (t < 500) {
            ta = microsegundos();
            for (i = 0; i < k; i++) {
                descendente(vector, n);
                ord_rapida(vector, n);
            }
            tb = microsegundos();
            t1 = (tb - ta);
            ta = microsegundos();
            for (i = 0; i < k; i++) {
                descendente(vector, n);
            }
            tb = microsegundos();
            t2 = tb - ta;
            t = (t1 - t2) / k;
            printf("(*)");

        } else {
            printf("   ");
        }
        x = t / pow(n, 0.9);
        y = t / pow(n, 1.04);
        z = t / pow(n, 1.2);
    }
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);

}

void rapida_aux(int v[ ], int izq, int der){
    int x;
    int pivote;
    int i,j;
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
