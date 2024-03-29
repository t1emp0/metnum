#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * Aquesta funció evalua el polinomi *difer (de grau n) en el punt z i en retorna la solució.
 * També pot returnar el valor de la seva derivada.
 */
double aval (int n, double *x, double *difer, double z) {
    
    int i;
    double sol, der;
    
    sol = difer[n];
    der = 0;
    
    
    for (i = (n-1); i > 0; i--) {
        der = der * z + sol;
        sol = sol * (z - x[i]) + difer[i];
    }
    
    return sol;
}
