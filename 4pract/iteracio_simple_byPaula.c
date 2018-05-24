#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);
double g(double);

int iteracioSimple(double x0, double *sol, double tol, int *iter, int it_max){
		
	int i, x1;

	if(fabs(f(x0))<tol){
		*sol=x0;
		*iter=0;
		
		return 0;
	}
	
	for(i=1; i<=it_max; i++){
		x1=g(x0);
		if(fabs(f(x1))<tol || fabs(x1-x0)<tol){
			*sol=x1;
			*iter=i;
			
			return 0;
		}
		x0=x1;
	}
	
	return 1;

}

double g(double x){
	
	return f(x)+x;
	
}
