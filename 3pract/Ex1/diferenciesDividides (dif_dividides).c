#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Donat dos vectors x i y, aquesta funció retorna difer amb es diferencies dividides.
 */
double *dif_dividides(int n, double *x, double *y){
    
    int k, i;
    double * difer;
    double tolerancia = 1.e-14;
    
    difer = (double *)malloc(n*sizeof(double));
        
    for (i = 0; i < n; i++) {
        difer[i] = y[i];
    }
    
    for (k = 1; k < n; k++) {
        for (i = n-1; i > k; i--){
            if ((x[i] - x[i-k]) < tolerancia){
                return (double *)calloc(n, sizeof(double));
            }
            difer[i] = (difer[i] - difer[i-1]) / (x[i] - x[i-k]);
            
        }
    }
    return difer;
}
