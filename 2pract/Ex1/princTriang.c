#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double tolerancia;

/*
 * Resol un sistema d equacions triangular per substitucio endarrera
 */
int substitucio(int n, double **matU, double *x){
    int i, j;
    double sumatori, sum = 1;
    tolerancia = 1.e-14;
    
    for (i=0; i < n; i++){
        sum *= matU[i][i];
    }
    if (fabs(sum) < tolerancia){
        return 0;
    }
    
    x[n-1] = matU[n-1][n]/matU[n-1][n-1];
    
    for (i = n-2; i >= 0; i--){
        sumatori = 0.;
        for (j = i+1; j < n; j++){
            sumatori += matU[i][j]*x[j];
        }
        x[i] = (matU[i][n] - sumatori) / matU[i][i];
    }
    return 1;
}


int main(void){
    double ** A, * x, k;
    int i, j, n;
    double  t2;
    clock_t init, fint;
    
    tolerancia = 1.e-14;
    
    /*printf("Introdueix la dimensio: \n");*/
    scanf("%d", &n);
    
    A = (double **)malloc( n*sizeof(double *) );
    for (i = 0; i < n; i++){
        A[i] = (double *)malloc((n+1)*sizeof(double));
        for (j = 0; j < n+1; j++){
            /*printf("Introdueix A[%d][%d]: ", i+1, j+1);*/
            scanf("%le", &k);
            A[i][j] = k;
        }
    }
    
    x = (double *)malloc(n*sizeof(double));
    
    /* Mostrem la matriu entrada*/
    printf("\nMATRIU ENTRADA\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%+.1e  ", A[i][j]);
        }
        printf("| x%i  =  %+.1e\n", i, A[i][n]);
    }
    
    
    /*Fem Subst endarrera*/
    init = clock();
    if (substitucio(n, A, x) == 0) {
        printf("La matriu es singular\n");
    } else {
        fint = clock();
            
        /*Mostrem solucio*/
        printf("\nLa solucio es: \n");
        for (i = 0; i < n; i++){
            printf("x%d = %+.1e\n", i, x[i]);
        }
        
        t2= (double)(fint-init)/CLOCKS_PER_SEC;
        printf("substitucio endarrera: %.2es\n", t2);
    }
    
    return 0;
    
}
