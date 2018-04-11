/* 4.aprox.c */
/*
 * a) Escriviu la sèrie de Taylor de la funció log(1 + y) per y = x i y = −x (|y| < 1) (la denotarem (L1)).
 * 
 * b) Determineu un valor aproximat de log(0.7), a partir del polinomi de Taylor de grau n de (L1 ) per n = 7, 9, 11. Quin és l’error en S11 ? Quants termes de la sèrie són necessaris per tenir un error menor que 10−15, per tot 0 < x < 10−3 ?
 * 
 * c) De l’expressió (L1 ) i la identitat log(a/b) = log a − log b, deduı̈u-ne una expressió per 1+ x (L2 )  log .1 − x
 * 
 * Quin valor ha de tenir x en (L2) per a aproximar log(0.7)? Useu aquest x per calcular un valor aproximat de log(0.7), a partir del polinomi de Taylor de grau n de (L2 ) per n = 7, 9, 11. Quin és l’error en S11? Quants termes de (L1 ) són necessaris per a assegurar aquesta mateixa exactitud?
 */


#include <stdio.h>
#include <math.h>


double S(int n, double x) {
    int i;
    double res;
    
    if (fabs(x) > 1) {return 1;}
    res = 0;
    for (i = 1; i < n; i++){
        res += pow(-1, i-1) * pow(x, i) / i;
    }
    
    return res;
}


int main (void) {
    int n;
    double x, L, aprox, up, down, x1, x2, L1, L2, resta, y;
    
    x = -0.3;
    L = log(1+x);
    printf("%+26.16le\n", L);
    
    for (n = 7; n < 12; n = n+2) {    
        aprox = S(n,x);
        printf("%2.d %+23.16le %+23.16le %+23.16le\n", n, aprox, fabs(aprox-L), fabs(aprox-L)/L);
    }
    
    n = 1;
    x1 = 0.001;
    x2 = 1.e-15;
    
    L1 = log(1+x1);
    L2 = log(1+x2);
    
    while (up > 1.e-15 || down > 1.e-15) {
        up = fabs( S(n,x1) - L1);
        down = fabs( S(n,x2) - L2);
        n++;
    }
    printf("Els termes de la sèrie que són necessaris per l'error son %d\n", n);
    
    x = -0.3;
    L = log(1+x); 
    y = -3./17.;
    for (n = 7; n < 12; n+=2){
        
        resta = S(n,y) - S(n,-y) ;
        printf("%2.d %+23.16le %+23.16le\n",n, resta, L-resta);
    }
    
    
    
    
    return 0;
}
