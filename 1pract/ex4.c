/* ex4.c
exercici 4
*/

#include <stdio.h>
#include <math.h>

double S(int n, double x){
    int i;
    double res;
    
    if (fabs(x) > 1) {return 1;}
    
    res = 0;
    
    for(i = 1; i < n; i++){
        res += pow(-1, i-1) * pow(x, i) / i;
                
    }
    
    return res;
}

int main(void){
    int n;
    double x, L, aprox, resta, y;
    
    x = -0.3;
    L = log(1+x);
    printf("%+26.16le \n",L);
    
    for (n = 7; n < 12; n+=2){
        
        aprox = S(n,x);
        printf("%2.d %+23.16le %+23.16le\n",n, aprox, L-aprox);
    }
    
    y = -3./17.;
    for (n = 7; n < 12; n+=2){
        
        resta = S(n,y) - S(n,-y) ;
        printf("%2.d %+23.16le %+23.16le\n",n, resta, L-resta);
    }
    
    x = -0.999;
    L = log(1+x);
    for (n = 5; n < 300; n+=2){
        
        aprox = S(n,x);
        printf("%2.d %+23.16le %+23.16le\n",n, aprox, L-aprox);
    }
    
    
    
    return 0;

}
