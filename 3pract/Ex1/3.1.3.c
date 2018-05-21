#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 *Aquesta funció evalua el polinomi *difer (de grau n) en el punt z i en retorna la solució.
 * També pot returnar el valor de la seva derivada.
 */
double aval (int n, double *x, double *difer, double z);

/*
 * Donat dos vectors x i y, aquesta funció retorna difer amb es diferencies dividides.
 */
double *dif_dividides(int n, double *x, double *y);


double funq(double x) {
    double y;
    y = 1. / (1 + (25*x) *x);
    return y;
}

int main(void) {
    
    double * a, * b, *pol, l, u, k, x, q;
    int n, i;
    
    /* double tolerancia = 1.e-14; */
    
    
    /*
    printf("Introdueix la dimensio: \n");
    scanf("%d", &n);
    
    n++;
    
    printf("Introdueix l'extrem inferior de l'interval: \n");
    scanf("%d", &l);
    printf("Introdueix l'extrem superior de l'interval: \n");
    scanf("%d", &u);
    */
    
    
    for (n= 5; n <= 25; n += 5) {
        n++;
        
        l = -1;
        u = 1;
        
        a = (double *)malloc(n*sizeof(double));
        
        /*Aquí emplenem el vector *a amb les abscisses equidistant.*/
        u = (u-l) / (n-1.);
        for (i = 0; i < n; i++){
            a[i] = l + u*i;
        }
        
        /*Assignem al vector *b les imatges de les abcisses.*/
        b = (double *)malloc(n*sizeof(double));
        for (i = 0; i < n; i++){
            b[i] = funq(a[i]);
        }
        
        
        printf("\nVECTORS ENTRADA\n");
        for (i = 0; i < n; i++){
            printf("%+.3e  ", a[i]);
            printf("|  %+.5e\n", b[i]);
        }
        
        
        pol = dif_dividides(n,a,b);
        printf("\nDIFERÈNCIES DIVIDIDES FETES\n");
        
        printf("\nVECTORS ENTRADA\n");
        for (i = 0; i < n; i++){
            printf("%+.3e  ", a[i]);
            printf("|  %+.5e\n", pol[i]);
        }
        
        
        /* Avaluació final: x, f(x), p(x) (amb Horner), p(x)-f(x) */
        printf("\nEvaluació extra: \n");
        x = l-0.5;
        for (i = 0; i < 60; i++){
            k = aval(n,a,pol,x);
            q = funq(x);
            printf("%+.2e %+.4e %+.4e %+.4e\n", x, q, k, k-q);
            x += 0.05;
        }
    }
    
    return 0;
}
