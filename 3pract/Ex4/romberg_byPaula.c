#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trapezis(double, double, int);
int romberg(double a, double b, int n, double *sol, double tol, int iter){

	int i, j, k;
	double aux, producte;
	double *t;
	
	t=(double*)malloc(iter*sizeof(double));
	if(t==NULL){
		printf("No hi ha memoria per al vector\n");
		exit(1);
	}
	
	for(i=iter-1; i>=0; i--){
		t[i]=trapezis(a, b, n);
		n*=2;
	}
	for(j=0; j<iter; j++){
		for(i=0; i<iter-j; i++){
			for(k=0, producte=1.; k<2*j; k++) producte*=2.;
			aux=(producte*t[i]-t[i-1])/(producte-1);
			t[i]=aux;
		}
		if(fabs(aux-t[0])<tol){
			*sol=t[0];
			return 1;
		}
		
	}
	free(t);
	
	return 0;
}
