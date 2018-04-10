/*
 * Donada una matriu, aquest metode la triangula
 */
int gauss(double **A, double *b, double tolerancia){
    int i, j, k;
    double m;
    
    for (k = 0; k < n; k++){
        for (i = k+1; i < n; i++){
            
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
