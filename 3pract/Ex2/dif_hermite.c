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
    double * difer;
    double tolerancia = 1.e-14;
    
    x_herm = (double *)malloc(2*n*sizeof(double));
    difHer = (double *)malloc(2*n*sizeof(double));
    
    /*Diferències dividides: Cada cop que es divideixi per 0 sustituim per la derivada.*/
    for (i = 0; i < 2*n; i++) {
        if (i%2 == 0) {
            difHer[i] = x_herm[i];
        } else {
            difHer[i] = (difHer[i] - difHer[i-1]) / (x_herm[i] - x_herm[i-k]);
        }
    }
    
    /*Fem els altres passos: k=2,...,n*/
    for (k = 2; k < n; k++) {
        for (i = n-1; i > k; i--){
            if((x_herm[i] - x_herm[i-k]) < tolerancia){
                return (double *)calloc(n, sizeof(double));
            }
            
            difHer[i] = (difHer[i] - difHer[i-1]) / (x_herm[i] - x_herm[i-k]);
            
        }
    }
    
    
    return difHer;
}
