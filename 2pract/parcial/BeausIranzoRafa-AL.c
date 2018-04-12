#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



int sumes, divisions, productes;


/*
 * Donada una matriu, aquest metode la triangula
 */
int gauss(double **A, int n, double tol){
    int i, j, k;
    double m;
    
    for (k = 0; k < n; k++){
        if (k < n-3) {
            for (i = k+1; i < k+3; i++){
                if (fabs(A[k][k]) < tol) {
                    return 0;
                }
                
                m = A[i][k]/A[k][k];
                divisions++;
                
                A[i][k] = m; /*Guardem el multiplicador per a futurs usos, com fact LU*/
                
                for (j = k+1; j < n+1; j++){
                    A[i][j] = A[i][j] - m*A[k][j];
                    productes++;
                    sumes++;
                }
            }
        } else {
            for (i = k+1; i < k+3; i++){
                if (fabs(A[k][k]) < tol) {
                    return 0;
                }
                
                m = A[i][k]/A[k][k];
                divisions++;
                
                A[i][k] = m; /*Guardem el multiplicador per a futurs usos, com fact LU*/
                
                for (j = k+1; j < n+1; j++){
                    A[i][j] = A[i][j] - m*A[k][j];
                    productes++;
                    sumes++;
                }
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
        productes++;
    }
    if (fabs(sum) < tolerancia){
        return 0;
    }
    
    x[n-1] = matU[n-1][n]/matU[n-1][n-1];
    divisions++;
    
    for (i = n-2; i >= 0; i--){
        sumatori = 0.;
        for (j = i+1; j < n; j++){
            sumatori += matU[i][j]*x[j];
            productes++;
            sumes++;
        }
        x[i] = (matU[i][n] - sumatori) / matU[i][i];
        divisions++;
        sumes++;
    }
    return 1;
}


int main(void){
    double ** A, * x, k;
    int n, i, j;
    double tolerancia;
    FILE *dades,*sol;
    char fname[128], fname2[128];
    
    tolerancia = 1.e-14;
    
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

    /*vector de mida n*/
    x = (double *)malloc(n*sizeof(double));
    
    
    printf("\nMATRIU ENTRADA\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%+.2e  ", A[i][j]);
        }
        printf("| x%i  =  %+.2e\n", i, A[i][n]);
    }
    
    /*Fem Gauss*/
    if (gauss(A,n,tolerancia) == 0) {
        printf("No s'ha pogut triangular la matriu!\n");
        return 1;
    }
    
    /*Mostrem la matriu amb Gauss fet*/
    printf("\nGAUSS FET\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i <= j) printf("%+.5e  ", A[i][j]);
            else printf("+0.00000000  ");
        }
        printf("| x%i  =  %+.1e\n", i, A[i][n]);
    }
    
    
    /* Mostrem Factoritzacio*/
    printf("\nFACTORITZACIO LU\n");
    
    printf("\nImprimim la matriu L  \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i > j) printf("%+.1e  ", A[i][j]);
            if (i == j) printf("+.5e  ");
            if (i < j) printf("+0.00000000  ");
        }
        printf("\n");
    }
    
    printf("\nImprimim la matriu U \n");
    for(i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i <= j) printf("%+.5e  ", A[i][j]); /*i fila, j columna*/
            if (i > j) printf("+0.00000  ");
        }
        printf("\n");
    }
    
    
    
    /*Fem Subst endarrera*/
    if (substitucio(n,A,x) == 0) {
        printf("No s'ha pogut realitzar substitució endarrera!\n");
        return 1;
    }

    /*Mostrem solucio*/
    printf("\nLa solucio es: \n");
    for (i = 0; i < n; i++){
        printf("x%d = %e\n", i, x[i]);
    }
    
    
    
    printf("\nNúmero d'operacions:\n");
    printf("Sumes / restes: %d\n", sumes);
    printf("Productes: %d\n", productes);
    printf("Divisions: %d\n", divisions);
    
    return 0;
}
