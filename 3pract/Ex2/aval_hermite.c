#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Aquesta funció en realitat és Horner amb el nom canviat. De 3pract/Ex1 */
/*
 * Aquesta funció evalua el polinomi *difHer (de grau 2*n) en el punt z i en retorna la solució.
 * També pot returnar el valor de la seva derivada.
 */
double aval_hermite (int n, double *x, double *difHer, double z) {
    
    int i;
    double sol, der, *x_herm;
    
    sol = difHer[2*n-1];
    der = 0;
    
    
    /*Creem una còpia del vector de les x amb el doble de dades.*/
    x_herm = (double *)malloc(2*n*sizeof(double));
    
    for (i = 0; i < n; i++) {
        x_herm[2*i] = x[i];
        x_herm[2*i+1] = x[i];
    }
    
    
    for (i = (2*n-1)-1; i >= 0; i--) {
        der = der * z + sol;
        sol = sol * (z - x_herm[i]) + difHer[i];
    }
    
    return sol;
}
