#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;

/*
 * Donada una matriu, aquest metode la triangula
 */
int gauss(double **A, double *b, double tolerancia){
    int i, j, k;
    double m;
    
    for (k = 0; k < n; k++){
        for (i = k+1; i < n; i++){
            
            m = A[i][k]/A[k][k];
            for (j = k+1; j < n; j++){
                A[i][j] = A[i][j] - m*A[k][j];
            }
            A[i][k] = m; /*Guardem el multiplicador per a futurs usos, com fact LU*/
            b[i] = b[i] - m*b[k];
        }
    }
    
    return 0;
}


/*
 * Resol un sistema d equacions triangular per substitucio endarrera
 */
int subs_endarrere(double **A, double *b){
    int i, j, sumatori;
    
    for (i = n-1; i >= 0; i--){
        sumatori = 0;
        for (j = i+1; j < n; j++){
            sumatori += A[i][j]*b[j];
        }
        b[i] = (b[i] - sumatori) / A[i][i];
    }
    
    return 0;
}

int main(void){
    double ** A, * b, k;
    int i, j;
    double tolerancia;
    
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
    
    /*Fem Gauss*/
    gauss(A,b,tolerancia);
    
    /*Mostrem la matriu amb pivotatge*/
    printf("\nGAUSS FET\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i <= j) printf("%+.1e  ", A[i][j]);
            else printf("+0.00000  ");
        }
        printf("| x%i  =  %+.1e\n", i, b[i]);
    }
    
    /*Fem Subst endarrera*/
    if (subs_endarrere(A, b) == 0) {
        return 1;
    } else {
        /*Mostrem solucio*/
        printf("\nLa solucio es: \n");
        for (i = 0; i < n; i++){
            printf("x%d = %e\n", i, b[i]);
        }
    }
    
    return 0;
}
