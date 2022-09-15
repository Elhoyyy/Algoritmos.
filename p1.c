#include <stdio.h>
#include <math.h>

int fib1(int n) {
    if (n > 2) {
        return n;
    } else {
        return fib1(n - 1) + fib1(n - 2);
    }
}

int fib2(int n){
    int i=1, j=2;
    for(int k=1; k<n; k++){
        j=i+j;
        i=j-i;
    }
    return j;
}

int fib3(int n) {
    int i = 1, j = 0, k = 0, h = 1, t = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            t = j * h;
            h = 2 * k * h + t;
            k = pow(k, 2) + t;
            n = n / 2;
        }
    }
    return j;
}
