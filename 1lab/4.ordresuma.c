/* ordresuma.c
* 1 - Aquest programa ens permet veure que la serie sum(1/k) amb k=1,..., inf és divergent però numéricament convergent: el resultat s'estabilitza.
* 2 - Si sumem els mateixos termes en ordre invers, veiem que dóna diferent.
* 3 - Finalment, calculem la suma de la serie sum(1/k^2) amb k=1,..., inf.
*/

#include <stdio.h> 
#include <math.h> 
#include <limits.h>

int main(void)
{
    int i, k;
    float s, dif;
    double resultat, eps;
    resultat = 0.;
    s = 0.;
    eps = 1.e-6;
    dif =100;

    k = 1;
    while(dif > eps) {
        s+=1./k;
        dif = fabs(s-(s-1./k));
        k++;
    } 
    for(i = k; i < k+10; i++){
        s += 1./i;
        printf("%7d. Successió = %+.8e \n", i, s);
    }


    printf("---------- \n");
    
    s=0.;
    for(i = k; i >10; i--){
        s+=1./i;
    }
    for(i=10; i >=1; i--){
        s+=1./i;
        printf("%2d. Successió inversa= %+8e \n", i, s);
    }

    printf("---------- \n");
    
    for(k=1; k <INT_MAX; k++){
        resultat+=1./pow(k,2);
    }
    printf("Segona successió = %f \n", resultat);
   return 0;
}
