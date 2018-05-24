#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double pi = 3.1415926535897932384626433832795028841971693993751058209749445923078;

/*
 *Aquesta funció evalua el polinomi *difer (de grau n) en el punt z i en retorna la solució.
 * També pot returnar el valor de la seva derivada.
 */
double aval (int n, double *x, double *difer, double z);

/*
 * Donat dos vectors x i y, aquesta funció retorna difer amb es diferencies dividides.
 */
double *dif_dividides(int n, double *x, double *y) ;

double funq(double x) {
    double y;
    y = 1./(1 + 12*x*x);
    return y;
}



int abcs_Txevitxev(double *a, int l, int u, int n){
    /*Donats un vector de mida n, aquest métode l'emplena amb les abcisses de Txebishev a l'interval [l,u].*/
    int i;
    
    for (i = 0; i < n; i++){
        a[n-i-1] = 0.5*(l+u) + 0.5*(u-l)* cos(((2*i+1)*pi)/((2*n)+2));
    }
    return 0;
}

/*
double trapezis (double a, double b, double *p, int n) {
    int i;
    double h, x, sol;
    
    sol = 0.;
    x = a;
    
    h = (b-a)/n;
    */
    /* Fem els casos extrems a part, i la resta a del sumatori a dins del bucle.*/
    /*sol += (aval(n,a,p,x) /2);
    for (i=1;i<n;i++){
        x += h;
        sol += aval(n,a,p,x);
    }
    sol += (aval(n,a,p,b))/2;
    
    sol *= h;
    
    return sol;
}*/


int main(void) {
    
    double * a, *q, * b, * fq,  *pol, *polq,  l, u, k, x, m;
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
    
    n = 12;
    l = -2.;
    u = 2.;
    
    a = (double *)malloc(n*sizeof(double));
    q = (double *)malloc(n*sizeof(double));
    
    /*Aquí emplenem el vector *a amb les abscisses equidistant.*/
    u = (u-l) / (n-1.);
    for (i = 0; i < n; i++){
        a[i] = l + u*i;
    }
    
    /*Emplenem el vector q amb abcisses de abcs_Txevitxev*/
    
    n = 12;
    l = -2.;
    u = 2.;
    i = abcs_Txevitxev(q, l, u, 12);
    
    /*Assignem al vector *b les imatges de les abcisses.*/
    b = (double *)malloc(n*sizeof(double));
    fq = (double *)malloc(n*sizeof(double));
    for (i = 0; i < n; i++){
        b[i] = funq(a[i]);
        fq[i] = funq(q[i]);
    }
    
    /*
    printf("\nVECTOR EQUIDISTANT\n");
    for (i = 0; i < n; i++){
        printf("%+.5e  ", a[i]);
        printf("|  %+.5e\n", b[i]);
    }
    
    printf("\nVECTOR Txebishev\n");
    for (i = 0; i < n; i++){
        printf("%+.5e  ", q[i]);
        printf("|  %+.5e\n", fq[i]);
    }
    */
    
    pol = dif_dividides(n,a,b);
    polq = dif_dividides(n,q,fq);
    
    /*
    printf("\nDIFERÈNCIES DIVIDIDES FETES\n");
    
    printf("\nResultat:\n");
    for (i = 0; i < n; i++){
        printf("%+.5e  ", pol[i]);
        printf("|  %+.5e\n", polq[i]);
    }
    
    */
    
    
    /* Avaluació final: x, f(x), p(x) (amb Horner), p(x)-f(x) */
    /*
    printf("\nEvaluació extra: \n");
    x = l-0.5;
    for (i = 0; i < 50; i++){
        k = aval(n,a,pol,x);
        m = funq(x);
        printf("%+.2e %+.4e %+.4e %+.4e\n", x, m, k, k-m);
        x += 0.2;
    }
    */
    /*
    x = -2;
    for (i = 0; i < 501; i++){
        k = aval(n,a,polq,x);
        m = funq(x);
        printf("%+.4e %+.4e\n", x, k-m);
        x += 4./501.;
    }*/
    
    /*trapezis();*/
    
    
    return 0;
}
