#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 *Aquesta funció evalua el polinomi *difer (de grau n) en el punt z i en retorna la solució.
 * També pot returnar el valor de la seva derivada.
 */
double aval (int n, double *x, double *difer, double z);

/*
 * Donat dos vectors x i y, aquesta funció retorna difer amb es diferencies dividides.
 */
double *dif_dividides(int n, double *x, double *y);

int main(void) {
    
    double * p, * t, *pol, sol, z;
    int i, n;
    
    /* double tolerancia = 1.e-14; */
    
    n = 4;
    
    p = (double *)malloc(n*sizeof(double));
    t = (double *)malloc(n*sizeof(double));
    
    p[0] = 750;
    t[0] = 99.630;
    p[1] = 755;
    t[1] = 99.815;
    p[2] = 760;
    t[2] = 100.00;
    p[3] = 765;
    t[3] = 100.184;
    
    printf("\nVECTORS ENTRADA\n");
    for (i = 0; i < n; i++){
        printf("%+.3e  ", p[i]);
        printf("|  %+.5e\n", t[i]);
    }
    
    pol = dif_dividides(n,p,t);
    printf("\nDIFERÈNCIES DIVIDIDES FETES\n");
    
    printf("\nEl resultat és: \n");
    for (i = 0; i < n; i++){
        printf("x%d = %+.5e\n", i, pol[i]);
    }
    
    z = 753;
    printf("\nEvaluació en p= 753: \n");
    sol = aval(n,p,pol,z);
    printf("%+.4e\n", sol);
    
    
    return 0;
}