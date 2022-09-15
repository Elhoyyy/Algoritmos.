#include <stdio.h>
#include <math.h>
void test();
int main (){
    test();
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
    for(int k=1; k<n; k++){
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
        t=pow(h,2);
        h = 2 * k * h + t;
        k = pow(k, 2) + t;
        n = n / 2;

    }
    return j;
}
void test(){
    int n=10;
    printf("\n");
    for(int i =0;i<n;i++){
        if(i==0){
            printf("|N|\t|FIB1|\t|FIB2|\t|FIB3|\n");
        }

        printf("|%d|\t",i+1);
        printf("|%d|\t",fib1(i+1));
        printf("|%d|\t",fib2(i+2));
        printf("|%d|\n",fib3(i+1));

    }
}
