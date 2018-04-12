#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
    double ** A, * x;
    int n, i, j, k;
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
            if (i<j){
                k = j+1;
            } else {
                k = i+1;
            }
            A[i][j] = 1./k;
        }
        
    }

    /*vector de mida n*/
    x = (double *)malloc(n*sizeof(double));
    
    
    printf("\nMATRIU ENTRADA\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%+.8e  ", A[i][j]);
        }
        printf("\n  ", A[i][j]);     
        /*printf("| x%i  =  %+.2e\n", i, A[i][n]);*/
    }
    
    return 0;
}
