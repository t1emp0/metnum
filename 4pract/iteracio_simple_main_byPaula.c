#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);
int iteracioSimple(double, double *, double, int *, int);

int main(void){
	
	int it_max, ret, iter;
	double x0, tol, sol;
	FILE *pin;
	char fin[80];
	
	printf("Digues el nom del fitxer d'entrada:\n");
	scanf("%s", fin);
	pin=fopen(fin,"r");
	if(pin==NULL){
		printf("No es pot obrir el fitxer d'entrada\n");
		exit(1);
	}
	
	fscanf(pin,"%le %le %d", &x0, &tol, &it_max);
	
	ret=iteracioSimple(x0, &sol, tol, &iter, it_max);
	if(ret==1){
		printf("S'ha arribat al nombre maxim d'iteracions sense convergencia\n");
		return 0;
	}
	printf("S'ha trobat un zero en x=%20.12le a la iteracio %d\n", sol, iter);
	
	fclose(pin);
	
	return 0;
	
}

