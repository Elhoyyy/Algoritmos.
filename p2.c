#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
void inicializar_semilla();
void ord_ins(int v[], int n);
void aleatorio(int v [], int n);
void ascendente(int v [], int n);
void descendente(int v [], int n);
bool test (int v[], int n);



void ord_ins(int v[], int n){
    int i,j,x;
    for (i=1;i<=n;i++) {
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
    int i;
    inicializar_semilla();
    //int size=sizeof vector/sizeof vector[5];
    int val[10];
    aleatorio(val, 10);
    for(i=0;i<10; i++){
        printf(" %d ", val[i]);
    }
    printf("\n\n");
    ord_ins(val, 10);
    for(i=0;i<10; i++){
        printf(" %d ", val[i]);
    }
    printf("\n\n");

    test(val, 10);
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
    int i;
    for(i=n; i>0; i--){
        v[i]=i;
    }
}
bool test (int v[], int n){
    int i=0, j=1;
    bool check=true;
    while(j<=n){
        if(v[i]>v[j]){
            check =false;
            printf("FALSEO JHEEEEJE");
            return check;
        }
        i++,j++;

    }
    printf("CORRECTOR JAJEHEJEAEH");
    return check;

}
