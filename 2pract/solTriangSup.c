/*
 * Resol un sistema d equacions triangular per substitucio endarrera
 */
int substitucio(int n, double **matU, double *x){
    int i, j, sumatori, sum=1;
    tolerancia = 1.e-14;
    
    for (i=0; i < n; i++){
        sum *= matU[i][i];
    }
    if (fabs(sum) < tolerancia){
        return 0;
    }
    
    for (i = n-1; i >= 0; i--){
        sumatori = 0;
        for (j = i+1; j < n; j++){
            sumatori += matU[i][j]*x[j];
        }
        x[i] = (x[i] - sumatori) / matU[i][i];
    }
    return 1;
}
