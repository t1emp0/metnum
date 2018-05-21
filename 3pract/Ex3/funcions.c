/*
 * Aproximació de derivades per diferents funcions.
 */

double funq(double x) {
    double y;
    y = 2.*x;
    return y;
}


double primDeriv_1 (double c, double h) {
    double sol;
    sol = (funq(c+h) -funq(c)) / h;    
    return sol;
}

double primDeriv_2 (double c, double h) {
    double sol;
    sol = (funq(c+h) -funq(c-h)) / 2.*h;    
    return sol;
}


double primDeriv_3 (double c, double h) {
    double sol;
    sol = (funq(c-2*h) -8*funq(c-h) +8*funq(c+h) -funq(c+2*h)) / 12.*h;    
    return sol;
}