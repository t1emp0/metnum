/*
Exercici 2 [Interpolació de Lagrange d’una funció per diferències dividides]
Feu una funció que resolgui el problema (1)-(3) mitjançant el mètode de les diferències dividides de Newton.
També cal fer una funció on s’avaluï la f(x) que es vol interpolar. Useu qualsevol funció senzilla, per exemple, sin(x), exp(x), |x|, etc.
En el programa principal, es llegirà n i els extrems de l’interval [a, b] on es vol fer la interpolació. Aquesta es farà de dues maneres, en abscisses equidistant i en abscisses de Txebishev.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
double tolerancia;



int abcs_Txevitxev(double *a, int l, int u int n){
    /*Donats un vector de mida n, aquest métode l'emplena amb les abcisses de Txebishev a l'interval [l,u].*/
    for (i = 0; i < n; i++){
        a[i] = 0.5*(l+u) + 0.5*(u-l)* cos(((2*i+1)*pi)/(2*n));
    }
    return 0;
}

int dif_dividides(double *a, double *b, int n){
    /*Donats dos vectors, aquest métode retorna les diferencies dividides al 2n. */
    int i, j;

    for (i =0; i < n; i++) {
        for (j = n; j > i; j--){
            if ((a[j]-a[j-i])) < tolerancia){
                return 1;
            }
            b[j] = (b[i]-b[j-1]). / (a[j]-a[j-i])
        }
    }
    return 0;
}

double horner(double *a, double x, int n){
    /* Aquesta funció evalua el polinomi *a en el punt x (de grau n)*/
    /* També pot returnar el valor de la seva derivada.*/
    double p, q;
    p = a[n];
    q = 0;
    
    for(i = (n-1); i < 0; i--) {
        q = q*x + p;
        p = p*x + a[i];
    }
    
    return p;
}

double funq(double x){
    double y;
    y = sin(x);
    return y;
    
}

double funp(double *b, double x){
    double y;
    for (i =0; i < n; i++) {
        y += b[i] * pow(x,i);
    }
    return 0;
}

int main(void){
    double * a, * b, l, u, k, x;
    int i, j;
    
    tolerancia = 1.e-14;
    
    printf("Introdueix la dimensio: \n");
    scanf("%d", &n);
    
    n++;
    
    printf("Introdueix l'extrem inferior de l'interval: \n");
    scanf("%d", &l);
    printf("Introdueix l'extrem superior de l'interval: \n");
    scanf("%d", &u);
    
    a = (double **)malloc(n*sizeof(double *));
    
    /*Aquí emplenem el vector *a amb les abscisses equidistant.*/
    /*
    u = (u-l) /n.;
    for (i = 0; i < n; i++){
        a[i] = l + u*i;
    }
    */
    
    /*Aquí emplenem el vector *a amb les abcisses de Txebishev*/
    abcs_Txevitxev(*a, l, u, n);
    
    /*Assignem al vector *b les imatges de les abcisses.*/
    b = (double *)malloc(n*sizeof(double));
    for (i = 0; i < n; i++){
        b[i] = funq(a[i]);
    }
    
    /* Mostrem la matriu entrada*/
    printf("\nVECTORS ENTRADA\n");
    for (i = 0; i < n; i++){
        printf("%+.1e  ", a[i]);
        printf("| x%i  =  %+.3e\n", i, b[i]);
    }
    
    /*Fem Pivotatge*/
    dif_dividides(a,b,n);
    
    /*Mostrem la matriu amb pivotatge*/
    printf("\nDIFERÈNCIES DIVIDIDES FETES\n");
    for (i = 0; i < n; i++){
        printf("%+.1e  ", a[i]);
        printf("| x%i  =  %+.3e\n", i, b[i]);
    }
    
    
    /*Mostrem solucio*/
    printf("\nLa solucio es: \n");
    for (i = 0; i < n; i++){
        printf("x%d = %+e\n", i, b[i]);
    }
    
    /* Avaluació final: x, f(x), p(x) (amb Horner), p(x)-f(x) */
    printf("\nEvaluació extra: \n");
    x = -1;
    for (i = 0; i < 20; i++){
        x += 0.1;
        k = horner(b,x,n);
        q = funq(x);
        printf("%+.2e %+.4e %+.4e %+.4e", x, q, k, k-q);
    }
    
    return 0;
}
