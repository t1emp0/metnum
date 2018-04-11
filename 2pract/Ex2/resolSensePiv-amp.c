#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * En teoria aquest main fa: 
 * 
 * llegeix d'un fitxer el sistema lineal
 * fa elim Gauss
 * resol el sistema triangular superior
 * Escriu el resultat en un altre fitxer
 */

/*
 * Donada una matriu, aquest metode la triangula
 */
int gauss(double **A, int n, double tol){
    int i, j, k;
    double m;
    
    for (k = 0; k < n; k++){
        for (i = k+1; i < n; i++){
            if (A[k][k] < tol) {
                return 0;
            }
            
            m = A[i][k]/A[k][k];
            A[i][k] = m; /*Guardem el multiplicador per a futurs usos, com fact LU*/
            
            for (j = k+1; j < n+1; j++){
                A[i][j] = A[i][j] - m*A[k][j];
            }
        }
    }
    return 1;
} 


/*
 * Resol un sistema d equacions triangular per substitucio endarrera
 */
int substitucio(int n, double **matU, double *x){
    int i, j;
    double sumatori, sum = 1;
    double tolerancia = 1.e-14;
    
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
    int n, i, j;
    double tolerancia;
    
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
    
    /*Fem Gauss*/
    if (gauss(A,n,tolerancia) == 0) {
        printf("No s'ha pogut triangular la matriu!\n");
        return 1;
    }
    
    /*Mostrem la matriu amb pivotatge*/
    printf("\nGAUSS FET\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i <= j) printf("%+.1e  ", A[i][j]);
            else printf("+0.00000  ");
        }
        printf("| x%i  =  %+.1e\n", i, A[i][n]);
    }
    
    /*Fem Subst endarrera*/
    if (substitucio(n,A,x) == 0) {
        printf("No s'ha pogut realitzar substitució endarrera!\n");
        return 1;
    }

    /*Mostrem solucio*/
    printf("\nLa solucio es: \n");
    for (i = 0; i < n; i++){
        printf("x%d = %e\n", i, A[i]);
    }
    
    return 0;
}
