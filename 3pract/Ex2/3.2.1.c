#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Funció que, donats els vectors
 * x := {x0 , ..., xn },
 * fx := { f(x0), ..., f(xn)}
 * derfx := { f'(x0 ), ..., f'(xn )}
 * 
 * retorna un vector difHer amb les diferències dividides {f[x0], f[x0, x0], f[x0, x0, x1], ..., f[x0, x0, ..., xn, xn]}
 */
double *dif_hermite (int n, double *x, double *fx, double *derfx);

/*Aquesta funció en realitat és Horner amb el nom canviat. De 3pract/Ex1 */
/*
 * Aquesta funció evalua el polinomi *difHer (de grau n) en el punt z i en retorna la solució.
 * També pot returnar el valor de la seva derivada.
 */
double aval_hermite (int n, double *x, double *difHer, double z);


int main(void) {
    
    double *x, * fx, * derfx, *pol, sol, z;
    int i, n;
    
    /* double tolerancia = 1.e-14; */
    
    scanf("%d", &i);
    n = i;
    
    /*Declarem els tres vectors: x, f(x) i f'(x) */
    x = (double *)malloc(n*sizeof(double));
    fx = (double *)malloc(n*sizeof(double));
    derfx = (double *)malloc(n*sizeof(double));
    
    
    /*Aquí emplenem els tres vectors amb les dades que ens passen per teclat.*/
    for (i = 0; i < n; i++) {
        scanf("%le", &z);
        x[i] = z;
        
        scanf("%le", &z);
        fx[i] = z;
        
        scanf("%le", &z);
        derfx[i] = z;
    }

    /*Mostrem els tres vectors que s'han entrat.*/
    printf("\nVECTORS ENTRADA\n");
    for (i = 0; i < n; i++){
        printf("%+.5e  ", x[i]);
        printf("|  %+.5e", fx[i]);
        printf("|  %+.5e\n", derfx[i]);
    }
    
    pol = dif_hermite(n,x,fx,derfx);
    printf("\nINTERPOLACIÓ HERMITE FETA.\n");
    
    /*Mostrem el polinomi de grau 2n que resulta d'interpolar les dades*/
    printf("El resultat és: \n");
    for (i = 0; i < 2*n; i++){
        printf("x%d = %+.5e\n", i, pol[i]);
    }
    
    /*Avaluem el polinomi trobat en un cert punt*/
    scanf("%le", &z);
    x[i] = z;
    printf("\nEvaluació en p= %+.2e: \n", z);
    sol = aval_hermite(n,x,pol,z);
    printf("%+.4e\n", sol);
       
    
    
    return 0;
}