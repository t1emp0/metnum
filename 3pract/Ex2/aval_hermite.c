/*
 *Aquesta funció evalua el polinomi *difer (de grau n) en el punt z i en retorna la solució.
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

    
    /*Diferències dividides: Cada cop que es divideixi per 0 sustituim per la derivada.*/
    r = (double*)malloc(((2*m)+1)*sizeof(double)); 
    /*Fem el pas k=1*/
    for(i=0;i<(2*m)+1;i++){
        if(i%2==0){
            r[i] = M[i/2][2];
        }else{
            r[i] = (M[i/2 + 1][1] - M[i/2][1]) / (M[i/2+1][0] - M[i/2][0]);
        }
    }
    /*Fem els altres passos: k=2,...,n*/
    for(i=1; i<=2*m; i++){
        /*printf("\n");*/
        for(j=2*m;j>=i;j--){
            /*printf("%f-%f/%f-%f ,", r[j],r[j-1], M[j/2+j%2][0],M[(j-i)/2][0]);*/
            r[j] = (r[j]-r[j-1]) / (M[j/2+j%2][0]-M[(j-i)/2][0]);
        }
    }
    pri
