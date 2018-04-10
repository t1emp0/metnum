#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double tolerancia = 1.e-14;

int main (void) {
	double *a, *b, *c, *d, elem;
	int i, n;
	
    /*printf("Introdueix la dimensió de la matriu:");*/
    scanf("%d", &n);
    
	a = (double *)malloc((n)*sizeof(double));
	b = (double *)malloc((n-1)*sizeof(double));
	c = (double *)malloc((n-1)*sizeof(double));
	d = (double *)malloc((n)*sizeof(double));
	
    /*printf("Introdueix els elements de a:");*/
	for (i = 0; i < n; i++) {
		scanf("%le", &elem);
		a[i] = elem;
	}
	
    /*printf("Introdueix els elements de b:");*/
	for (i = 0; i < (n-1); i++) {
		scanf("%le", &elem);
		b[i] = elem;
	}
	
    /*printf("Introdueix els elements de c:");*/
	for (i = 0; i < (n-1); i++) {
		scanf("%le", &elem);
		c[i] = elem;
	}
	
    /*printf("Introdueix els elements de d:");*/
	for (i = 0; i < n; i++) {
		scanf("%le", &elem);
		d[i] = elem;
	}
	
	b[1] = b[1]/a[1];
	for (i = 1; i < n; i++) {
		if (fabs(a[i-1]) < tolerancia) return 1;
		b[i] = a[i] - (c[i] * b[i-1]);
	}
	
    d[1] = d[1]/a[1];
	for (i = 2; i < n; i++) {
		d[i] = (d[i] - b[i] * d[i-1]) / (a[i] - (b[i] * b[i-1]));
	}
	
	if (fabs(a[n-1]) < tolerancia) return 2;
	
	for (i = 0; i < n; i++) {
		printf("x[%d] = %e\n", i+1, d[i]);
	}
	
	return 0;
}
