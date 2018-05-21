#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Funció d'exemple: 1/(1+x) */
double fun(double x){
    double y;
    y = 3*x*x;
    return y;
}

/*
 * Donat un interval [a, b]
 * Un enter n és el nombre de subintervals en què dividim l’interval [a, b]
 * 
 * Retorna una aproximació de la integral de f(x) a l’interval [a, b] usant la fórmula dels trapezis.
 */

double trapezis (double a, double b, int n) {
    int i;
    double h, x, sol;
    
    sol = 0.;
    x = a;
    
    h = (b-a)/n;
    
    /* Fem els casos extrems a part, i la resta a del sumatori a dins del bucle.*/
    sol += (fun(a) /2);
    for (i=1;i<n;i++){
        x += h;
        sol += fun(x);
    }
    sol += (fun(b))/2;
    
    sol *= h;
    
    return sol;
}

int main (void){
    double sol;
    
    sol = trapezis(0.0,2.0,10);
    
    printf("%.10e\n", sol);
    
    /* double fita = ((b-a)/12)*h*h; */
    
    return 0;
}
