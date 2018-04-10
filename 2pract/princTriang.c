#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double tolerancia;

/*
 * Resol un sistema d equacions triangular per substitucio endarrera
 */
int substitucio(int n, double **matU, double *x){
    int i, j, sumatori, sum=1;
    tolerancia = 1.e-14;
    
    for (i=0; i < n; i++){
        sum *= matU[i][i];
    }
    if (fabs(sum) < tolerancia){
        return 0;
    }
    
    for (i = n-1; i >= 0; i--){
        sumatori = 0;
        for (j = i+1; j < n; j++){
            sumatori += matU[i][j]*x[j];
        }
        x[i] = (x[i] - sumatori) / matU[i][i];
    }
    return 1;
}


int main(void){
    double ** A, * b, k;
    int i, j, n;
    double  t2;
    clock_t init, fint;
    
    tolerancia = 1.e-14;
    
    /*printf("Introdueix la dimensio: \n");*/
    scanf("%d", &n);
    
    A = (double **)malloc( n*sizeof(double *) );
    for (i = 0; i < n; i++){
        A[i] = (double *)malloc(n*sizeof(double));
        for (j = 0; j < n; j++){
            /*printf("Introdueix A[%d][%d]: ", i+1, j+1);*/
            scanf("%le", &k);
            A[i][j] = k;
        }
    }
    
    b = (double *)malloc(n*sizeof(double));
    for (i = 0; i < n; i++){
        /*printf("Introdueix b[%d]: ", i+1);*/
        scanf("%le", &k);
        b[i] = k;
    }
    
    /* Mostrem la matriu entrada*/
    printf("\nMATRIU ENTRADA\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%+.1e  ", A[i][j]);
        }
        printf("| x%i  =  %+.1e\n", i, b[i]);
    }
    
    
    /*Fem Subst endarrera*/
    init = clock();
    if (substitucio(n, A, b) == 0) {
        printf("La matriu es singular\n");
    } else {
        fint = clock();
            
        /*Mostrem solucio*/
        printf("\nLa solucio es: \n");
        for (i = 0; i < n; i++){
            printf("x%d = %+.1e\n", i, b[i]);
        }
        
        t2= (double)(fint-init)/CLOCKS_PER_SEC;
        printf("substitucio endarrera: %.2es\n", t2);
    }
    
    return 0;
    
}
