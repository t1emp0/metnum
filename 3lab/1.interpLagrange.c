/*
[Interpolació de Lagrange d’una taula resolent un sistema lineal “ple”]
Es busquen els coeficients del polinomi del problema (1) en la base natural:
p(x) = a0 + a1 x + a2 x^2 + . . . + an x^n
Feu una funció on es resolgui un sistema lineal quadrat regular, per eliminació gaussiana
i substitució endarrera.
Feu una funció main on es llegeixin les dades n, xi’s, fi’s, s’omplin adequadament A i f del sistema lineal (n + 1) × (n + 1) que cal resoldre: Aa = f, es cridi la funci´o anterior per a resoldre’l i escrigui les ai’s
El programa ha de llegir n, A i b i escriura els resultats.
Calcular el vector residu b - Ax
Calcular temps d'execucio per a n grans i generar aleatoriament les dades
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
double tolerancia;

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
    int i, j;
    double sumatori;
    
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
    
    tolerancia = 1.e-14;
    
    printf("Introdueix la dimensio: \n");
    scanf("%d", &n);
    
    n++;
    
    A = (double **)malloc(n*sizeof(double *));
    for (i = 0; i < n; i++){
        A[i] = (double *)malloc(n*sizeof(double));
        printf("Introdueix x[%d]: ", i);
        scanf("%le", &k);
        for (j = 0; j < n; j++){
            A[i][j] = pow(k,j);
        }
    }
    
    b = (double *)malloc(n*sizeof(double));
    for (i = 0; i < n; i++){
        printf("Introdueix f[%d]: ", i);
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
        printf("x%d = %+e\n", i, b[i]);
    }
    
    return 0;
}
