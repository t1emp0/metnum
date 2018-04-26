/*
 * Aquesta funció evalua el polinomi *difHer (de grau n) en el punt z i en retorna la solució.
 * També pot returnar el valor de la seva derivada.
 */
double aval_hermite (int n, double *x, double *difHer, double z) {
    
    int i;
    double sol, der;
    
    sol = difHer[n];
    der = 0;
    
    
    for (i = (n-1); i > 0; i--) {
        der = der * z + sol;
        sol = sol * (z - x[i]) + difHer[i];
    }
    
    return sol;
}
