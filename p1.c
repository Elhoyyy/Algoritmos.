/*
TITULO: Algoritmos Práctica 1
AUTOR 1: Eloy Sastre Sobrino LOGIN 1: eloy.sastre
AUTOR 2: Daniel Pérez Mosquera LOGIN 2: daniel.pmosquera
GROUP: 1.1
DATE: 22/09/2022
*/

#include <stdio.h>
#include <math.h>
#include <sys/time.h>
double microsegundos();
void test();
int fib1(int n);
int fib2(int n);
int fib3(int n);
void print_resultf1(int n);
void print_resultf2(int n);
void print_resultf3(int n);
int main (){
    test();


    printf("\n\n");
    int n1=2;
    printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
    for(int i=0;i<5;i++){
        print_resultf1(n1);
        n1=n1*2;
    }
    printf("\n");
    int n2=1000;
    printf("\t      n\t        t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
    for(int i=0;i<5;i++){
        print_resultf2(n2);
        n2=n2*10;
    }
    printf("\n");
    int n3=1000;

    printf("\t      n\t         t(n)\t    t(n)/f(n)\t   t(n)/g(n)\t  t(n)/h(n)\t\n");
    for(int i=0;i<5;i++){
        print_resultf3(n3);
        n3=n3*10;
    }
    return 0;
}

int fib1(int n) {
    if (n < 2) {
        return n;
    } else {
        return (fib1(n - 1) + fib1(n - 2));
    }
}

int fib2(int n){
    int i=1, j=0;
    for(int k=1; k<=n; k++){
        j=i+j;
        i=j-i;
    }
    return j;
}

int fib3(int n) {
    int i = 1, j = 0, k = 0, h = 1, t;
    while (n > 0) {
        if (n % 2 == 1) {
            t = j * h;
            j=i*h+j*k+t;
            i=i*k+t;
        }
        t=h*h;
        h = 2 * k * h + t;
        k = k*k + t;
        n = n / 2;

    }
    return j;
}
void test(){
    int n=10;
    printf("\n");
    for(int i =0;i<n;i++){
        if(i==0){
            printf("\t|N|\t\t|FIB1|\t\t|FIB2|\t\t|FIB3|\n");
        }

        printf("\t %d \t",i+1);
        printf("\t %d \t",fib1(i+1));
        printf("\t %d \t",fib2(i+1));
        printf("\t %d \n",fib3(i+1));

    }
}
void print_resultf3(int n){
    double t1, t2, t, x, y, z;
    int k=1000;
    t1=microsegundos();
    fib3(n);
    t2=microsegundos();
    t=t2-t1;
    if (t < 500){
        t1=microsegundos();
        for(int i=0;i<k;i++){
            fib3(n);
        }
        t2=microsegundos();
        t=(t2-t1)/k;
        printf("(*)");

    }else{
        printf("   ");
    }
    x = t / sqrt(log(n));
    y = t / log(n);
    z = t / pow(n, 0.5);
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);
}

void print_resultf2(int n){
    double t1, t2, t, x, y, z;
    int k=1000;
    t1 = microsegundos();
    fib2(n);
    t2 = microsegundos();
    t = t2-t1;
    if (t < 500){
        t1=microsegundos();
        for(int i=0;i<k;i++){
            fib2(n);
        }
        t2=microsegundos();
        t=(t2-t1)/k;
        printf("(*)");
    } else{
printf("   ");
}
    x = t / pow(n,0.8);
    y = t / n;
    z = t / (n*log(n));
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);
}

void print_resultf1(int n){
    double t1, t2, t, x, y, z,o;
    int k=1000;
    o=(1+sqrt(5))/2;
    t1 = microsegundos();
    fib1(n);
    t2 = microsegundos();
    t = t2-t1;
    if (t < 500){
        t1=microsegundos();
        for(int i=0;i<k;i++){
            fib1(n);
        }
        t2=microsegundos();
        t=(t2-t1)/k;
        printf("(*)");

    }else{
        printf("   ");
    }
    x = t / pow(1.1,n);
    y = t / pow(o,n);
    z = t / pow(2,n);
    printf("%12d%15.3f%15.6f%15.6f%15.6f\n", n, t, x, y, z);
}

double microsegundos() {
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}
