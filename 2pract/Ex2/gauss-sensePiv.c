/*
 * Donada una matriu, aquest metode la triangula
 */
int gauss(double **A, int n, double tol){
    int i, j, k;
    double m;
    
    for (k = 0; k < n-1; k++){
        for (i = k+1; i < n; i++){
            if (fabs(A[k][k]) < tol) {
                return 0;
            }
            
            m = A[i][k]/A[k][k];
            A[i][k] = m; /*Guardem el multiplicador per a futurs usos, com fact LU*/
            
            for (j = k+1; j < n+1; j++){
                A[i][j] = A[i][j] - m*A[k][j];
            }
        }
    }
    return 1;
} 
