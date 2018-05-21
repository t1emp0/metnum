#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Funció que, donats els vectors
 * x := {x0 , ..., xn },
 * fx := { f(x0), ..., f(xn)}
 * derfx := { f'(x0 ), ..., f'(xn )}
 * 
 * retorna un vector difHer amb les diferències dividides {f[x0], f[x0, x0], f[x0, x0, x1], ..., f[x0, x0, ..., xn, xn]}
 */
double *dif_hermite (int n, double *x, double *fx, double *derfx){
    
    int k, i;
    double * difHer, * x_herm;
    
    x_herm = (double *)malloc(2*n*sizeof(double));
    difHer = (double *)malloc(2*n*sizeof(double));
    
    
    /*Creem una còpia del vector de les x amb el doble de dades.*/
    /*Diferències dividides: També emplenem el vector amb les imatges de les dades.*/
    for (i = 0; i < n; i++) {
        x_herm[2*i] = x[i];
        x_herm[2*i+1] = x[i];
        
        difHer[2*i] = fx[i];
        difHer[2*i+1] = fx[i];
    }
    
    /*
    printf("\nEtapa: 0\n");
    for (i = 0; i < 2*n; i++){
        printf("x%d = %+.5e\n", i, difHer[i]);
    }*/
        
    
    /*Fem la primera etapa a part*/
    for (i = 2*n-1; i > 0; i--) {
        if (i % 2 == 1) {
            difHer[i] = derfx[i/2];
        } else {
            difHer[i] = (difHer[i] - difHer[i-1]) / (x_herm[i] - x_herm[i-1]);
        }
    }
    
    
    /*Fem els passos d'interpolació: k=1,...,n*/
    for (k = 2; k < 2*n; k++) {/*? k<=n*/
        
        /*
        printf("\nEtapa: %d\n", k-1);
        for (i = 0; i < 2*n; i++){
            printf("x%d = %+.5e\n", i, difHer[i]);
        } */
        
        for (i = (2*n)-1; i >= k; i--){
                difHer[i] = (difHer[i] - difHer[i-1]) / (x_herm[i] - x_herm[i-k]);
        }
    }
    
    
    return difHer;
}
