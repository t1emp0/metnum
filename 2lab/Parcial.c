/*
Resoldre Ax = b
dimensio n
eliminacio gaussiana + pivotatge parcial (transformar Ax = b en Ux = c amb U triangular superior resoldre el sistema triangular substituint endarrera
2 funcions:
    Cada funcio retornara 0 si s'ha completat correctament el proces o un enter no nul si en algun cas es divideix per un nombre més petit que 1.e-14
El programa ha de llegir n, A i b i escriura els resultats
Calcular el vector residu b - Ax
Calcular temps d'execucio per a n grans i generar aleatoriament les dades
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int n;
double tolerancia, c;


/**
 * Donada una matriu, aquest metode la triangula
 */

int gauss_pivotatge(double **A, double *b){
    int i, j, k, tmp;
    double maxim, *aux, m;
    
    aux = (double *)malloc((n)*sizeof(double));
    for (k = 0; k < n; k++){
        for (i = k+1; i < n; i++){
            if (fabs(A[k][k]) < tolerancia){
                /*Si es masa petit fem pivotatge*/
                maxim = A[k][k];
                tmp = k;
                /* Busquem el maxim de la columna*/
                for (j = k+1; j < n; j++){
                    if (fabs(A[j][k]) > fabs(maxim)){
                        maxim = A[j][k];
                        tmp = j;
                    }
                }
                /*Si no hi ha cap mes petit retorna 1*/
                if (fabs(maxim) < tolerancia) return 1;
                aux[n] = b[i];
                b[i] = b[tmp];
                b[tmp] = aux[n];
                for (j = k; j < n; j++){
                    aux[j] = A[tmp][j];
                    A[tmp][j] = A[k][j];
                    A[k][j] = aux[j];
                }
            }
            
            
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
    
    for (i = n-1; i > -1; i--){
        sumatori = 0;
        for (j = i+1; j < n; j++){
            sumatori += A[i][j]*b[j];
        }
        b[i] = (b[i] - sumatori) / A[i][i];
    }
    return 0;
}




int main(void){
    double ** A, * b;
    int i, j;
    double num;
    /*clock_t init, fint;*/
    
    tolerancia = 1.e-14;
    c = 1.8017952;
       
    
    /*printf("Introdueix la dimensio: \n");*/
    n = 5;
    
    A = (double **)malloc( n*sizeof(double *) );
    for (i = 0; i < n; i++){
        A[i] = (double *)malloc(n*sizeof(double));
        for (j = 0; j < n; j++){
            /*printf("Introdueix A[%d][%d]: ", i+1, j+1);*/
            if (i > j) A[i][j] = 1. / (i+1);
            if (i == j) A[i][j] = 3*i + 4 + c;
            if (i < j) A[i][j] = 1. / (j+1);
        }
    }

    
    /* Mostrem la matriu entrada*/
    printf("\nMATRIU ENTRADA\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%+.3e  ", A[i][j]);
        }
        printf("\n");
    }
    
    /*SUMA*/
    num = 0;
    for (i = 0; i < 5; i++) {
        num += A[0][i];
    }
    printf("%+.9e  ", num);
    num = 0;
    for (i = 1; i < 4; i++){
        num += A[0][i];
    }
    printf("%+.9e  \n", A[0][0]-num);
    
    
    
    b = (double *)malloc(n*sizeof(double));
    b[0] = 1;
    for (i = 1; i < n; i++){
        b[i] = 0;
    }
    
    printf("\nMATRIU ENTRADA\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%+.3e  ", A[i][j]);
        }
        printf("| x%i  =  %+.3e\n", i, b[i]);
    }
        /*Fem Pivotatge*/
    gauss_pivotatge(A,b);
    
    /*Mostrem la matriu amb pivotatge*/
    printf("\nGAUSS PIVOTATGE FET\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i <= j) printf("%+.1e  ", A[i][j]);
            else printf("+0.00000  ");
        }
        printf("| x%i  =  %+.1e\n", i, b[i]);
    }
    
    
        /*Fem Subst endarrera*/
    if (subs_endarrere(A, b) != 0)
        return 1;
    
    /*Mostrem solucio*/
    printf("\nLa solucio es: \n");
    for (i = 0; i < n; i++){
        printf("x%d = %e\n", i, b[i]);
    }
    
    printf("%+.5e\n", 1./b[0]);
    
    /*Norma*/
    num = 0;
    for (i = 0; i < n; i++) {
        num += pow(b[i],2);
    }
    num = pow(num, 0.5);
    
    for (i = 0; i < n; i++) {
        b[i] = b[i] / num;
    }
    
    printf("\nLa solucio es: \n");
    for (i = 0; i < n; i++){
        printf("x%d = %e\n", i, b[i]);
    }
    
    
    return 0;
}
