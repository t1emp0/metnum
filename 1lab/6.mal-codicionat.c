/*Un problema és mal condicionat si en canviar poc les dades, canvia molt el resultat.*/

#include <stdio.h>  /* serveix per scanf i printf */
#include <math.h>  /* serveix per incloure el valor absolut */

int m; /* variable global */

/* Això és una funció auxiliar per calcular la f(x) en el mètode de Newton */
double f(double x, double c) {
    int k;
    double y = 1.;
    for(k=1; k<=m; k++) y=y*(x-k);
    y=y+c*pow(x,m);
    return y;
}


/* Això és una funció auxiliar per calcular la f'(x) en el mètode de Newton */
double d(double x, double c) {
    int k, j;
    double y, p;
    
    y=0.;
    for(k=1; k<=m; k++) {
        p=1.;
        for(j=1; j<=m; j++) {
            if(j!=k) p=p*(x-j);
        } 
        y = y+p;
    }
    y = y+m*c*pow(x,m-1);
    return y;
}

int main(void){
    
    int k, i, iter;
    double c, x, xi, fi, eps;
    /* xi ve de x increment
     * eps es epsilon per parar de iterar quan l'error sigui prou petit.
     * iter és el màxim d'iteracions que permetem: el mètode de Newton quan convergeix ho fa bastant ràpid.
     */
    
    iter=10;
    eps = 1.e-10;
    
    printf("m=?\n");
    scanf("%d", &m);
    printf("c=?\n");
    scanf("%le", &c);
    
    /*No busco una arrel pel métode de Newton, si no que en busco k.*/
    for(k=1;k<=m;k++) {
        /*Poso k a x perque busco una arrel propera al nombre.*/    
        x=k;
        xi=1.;
        i=0;
        while(i<iter && fabs(xi)>eps) {
            i = i+1;
            fi = f(x,c);
            xi= fi/d(x,c);
            x = x-xi;
            printf("i=%2d x=%+.16e fi=%+.4e xi=%+.4e\n", i, x, fi, xi);
        }
        if(fabs(xi)>eps) {
            printf("\n k=%2d, no convergencia \n\n", k);
        } else {
            printf("\n k=%2d, x_k=%.16e  ", k, x);
            printf("   dx_k=%+.4e, dx_k/c= %+.e\n\n",x-k, (x-k)/c);
        }
    }
    return 0;
}
