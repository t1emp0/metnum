/* 0.decimals.c */
/* Aquest programa mostra els problemes de l'ordinador al emmagatzemar certs nombres decimals amb precisió. */

#include <stdio.h> 
#include <math.h> 

int main(void)
{
    float y;
    
    y= 1.;
    
    while(y != 0) {
        scanf("%e", &y);
        printf("%.20e", y);
    }
   
    return 0;
}
