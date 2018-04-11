/* 2.sumes.c */
/* Volem calcular S(N) = sum(de j=1 a N) (1/j^2) per als valors N = 10^3, 10^4, 10^5 i 10^6.
 * Feu un programa que calculi S(N), sumant els termes començant per j = 1 fins a j = N i a l’inrevés.
 * Compareu els resultats obtinguts, Scalc(N).
 * Feu primer tots els càlculs en precisió simple. Després, en precisió doble. (sumes.c)
 * 
 * Quines conclusions en traieu?
 */

#include <stdio.h>

int main (void) {
    int i, k;
    float n, resultF;
    double d, resultD;
    
    n = 1.e3;
    d = 1.e3;
    for (i = 0; i < 4; i++){
        printf("\n");
        printf("n: %.1e, d: %.1le\n", n, d);
        
        /* Cap endavant */
        resultF = 0;
        for (k = 1; k < n; k++){
            resultF += (1.f/k)/k;
        }
        printf("Endavant float: %16.8e\n", resultF);
        
        /* Cap endavant double */
        resultD = 0;
        for (k = 1; k < n; k++){
            resultD += (1.f/k)/k;
        }
        printf("Endavant double: %23.16le\n", resultD);
        
        /* Cap endarrere float */
        resultF = 0;
        for (k = n; k > 0; k--){
            resultF += (1.f/k)/k;
        }
        printf("Endarrere float: %16.8e\n", resultF);
        
        /* Cap endarrere double */
        resultD = 0;
        for (k = n; k > 0; k--){
            resultD += (1.f/k)/k;
        }
        printf("Endarrere double: %23.16le\n", resultD);
        
        n *= 10;
        d *= 10;
    }
    
    return 0;
} 
