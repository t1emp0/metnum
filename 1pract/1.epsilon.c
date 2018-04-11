/* 1.epsilon.c */
/* L’èpsilon de la màquina és el menor valor real u > 0 
 * de la forma u = 2^(−i), i > 0, que verifica 1 + u > 1.
 * Feu un programa (epsilon.c) que calculi l’epsilon de la màquina dels tipus float i double.
 * Quina conclusió en traieu? El valor es correspon amb el que havieu pensat?
 */

#include <stdio.h>

int main (void) {
    float f;
    double d;
    
    f = 0.5f;
    d = 0.5;
    
    while (1.f + f > 1.f) {
        f = f/2;
    }
    
    while (1. + d > 1.) {
        d = d/2;
    }
    
    printf("f: %16.8e\n", f*2.f);
    printf("d: %24.16le\n", d*2.);
    
    return 0;
} 

/*
 * Resultats de les operacions:
 * 
 * f:   1.19209290e-07
 * d:   2.2204460492503131e-16
 * 
 */
