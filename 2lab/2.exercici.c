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
double tolerancia;

/**
 * Donada una matriu, aquest metode la triangula
 * 
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
    double ** A, * b, k;
    int i, j;
    double t1, t2;
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
    
    /*Fem Pivotatge*/
    init = clock();
    gauss_pivotatge(A,b);
    fint = clock();
    t1 = (double)(fint-init)/CLOCKS_PER_SEC;
    
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
    init = clock();
    if (subs_endarrere(A, b) != 0)
        return 1;
    fint = clock();
    t2= (double)(fint-init)/CLOCKS_PER_SEC;
    
    
    /*Mostrem solucio*/
    printf("\nLa solucio es: \n");
    for (i = 0; i < n; i++){
        printf("x%d = %e\n", i, b[i]);
    }
    
    /* Mostrem Factoritzacio*/
    printf("\nFACTORITZACIO LU\n");
    
    printf("\nImprimim la matriu L  \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i > j) printf("%+.1e  ", A[i][j]);
            if (i == j) printf("+1.0e+00  ");
            if (i < j) printf("+0.00000  ");
        }
        printf("\n");
    }
    
    printf("\nImprimim la matriu U \n");
    for(i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i <= j) printf("%+.1e  ", A[i][j]); /*i fila, j columna*/
            if (i > j) printf("+0.00000  ");
        }
        printf("\n");
    }
    
    
    printf("\nFACTORITZACIO LDLt\n");
    
    printf("\nImprimim la matriu D  \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i > j) printf("+0.00000  ");
            if (i == j) printf("%+.1e  ", A[i][j]);
            if (i < j) printf("+0.00000  ");
        }
        printf("\n");
    }
    
    printf("\nImprimim la matriu Lt  \n");
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            if (i > j) printf("%+.1e  ", A[i][j]);
            if (i == j) printf("+1.0e+00  ");
            if (i < j) printf("+0.00000  ");
        }
        printf("\n");
    }
    /*
     * 
     * Falta multiplicar L per la arrel quadrada de D per tal d'obtenir R.
     * 
    printf("\nFACTORITZACIO RRt\n");
    
    printf("\nImprimim la matriu R = L*D^(1/2)  \n");
    for (i = 0; i < n; i++) {
        m = pow(A[i][i], 0.5)
        for (j = 0; j < n; j++) { 
            if (i > j) printf("%+.1e  ", A[i][j]);
            if (i == j) printf("%+.1e  ", m);
            if (i < j) printf("+0.00000  ");
        }
        printf("\n");
    }
    
    printf("\nImprimim la matriu Rt = D^(1/2)*Lt  \n");
    for (j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            if (i > j) printf("%+.1e  ", A[i][j]);
            if (i == j) printf("%+.1e  ", pow(A[i][j], 0.5));
            if (i < j) printf("+0.00000  ");
        }
        printf("\n");
    }
    
    */
    
    printf("\n");
    printf("Eliminacio Gaussiana amb Pivotatge: %.2es\n", t1);
    printf("substitucio endarrera: %.2es\n", t2);
    
    return 0;
}
