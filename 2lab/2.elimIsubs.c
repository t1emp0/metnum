/* 2.elimIsubs.c 
Resolució d'un sistema lineal Ax=b de dim n mitjançant eliminación guassiana am pivotatge parcial.
Seguit de la resolució del sistema triangular per substituació endarrera.
*/

/* Resum programa:
 * Llegir n
 * Guardar memòria per a A,b i AA, bb que seran les copies
 * Copiar A a AA i b a bb.
 * Cridar funció que face elim gauss am piv parcial (A|b) ~ (U|c) <-> index = elimgaus(n,A,b,TOL)
 * Cridar funció que resolgui Ux = c -> x
 * Escriure resultats x
 * Calcular b-Ax i ||b-Ax||2 i escriure-ho
 * (L'últim pas està fet per comprovar que el programa funciona bé.)
 */
#include<stdio.h>    
#include<stdlib.h>
#include<math.h>
#define TOL 1.e-14

/*Etapa*/

int elimgaus(int n, double ** A, double * B) {
    double m;
    int i, j, k;
    
    for (k=1; k<(n-1); k++) {
        /*Fila*/
        for (i=k+1; i<n; i++) {
            if (fabs(A[k][k]) < TOL) return 1;
            m = (double)A[i][k] / A[k][k];
            A[i][k] = m;
            /*Columna*/
            for (j=k; j<n; j++) {
                A[i][j] -= m*A[k][j];
            }
            B[i] -= m*B[k];
        }
    }
    
    
    /* Imprimim la matriu per comprovar com ha anat. */
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++){
            printf("%+.2f ", A[i][j]);
        }
        printf("%+.2f", B[i]);
        printf("\n");
    }
    return 0;
}

int main(void)
{
    double **A, *B;
    int n, i, j, index;

    printf("\nIntrodueix la mida de la matriu:\n");
    scanf("%d", &n);


    A = (double **)malloc( n*sizeof(double *) );
    if ( A==NULL ) return 2;
    for (i=0; i<n; i++) {
        A[i] = (double *)malloc( n*sizeof(double) );
        if ( A[i]==NULL ) return 3; 
    }
    B = (double *)malloc( n*sizeof(double) );
    if ( B==NULL ) return 4;


    for (i=0; i<n; i++) {
        for (j=0; j<n; j++){
            scanf("%lf", &A[i][j]);
        }
    }
    for (i=0; i<n; i++) {
        scanf("%lf", &B[i]);
    }

    
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++){
            printf("%+.2f ", A[i][j]);
        }
        printf("%+.2f", B[i]);
        printf("\n");
    }
    
    
    index = elimgaus(n, A, B);
    if (index != 0) return 1;
    

    for (i=0; i<n; i++) free(A[i]);
    free(A);
    free(B);


    return 0;
}
