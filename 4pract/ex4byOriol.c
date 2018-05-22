#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double *pol;
int n;

double evaluar(double x,  double *polinomi, int m){
    double res = 0;
    int i;
    /*x: Array m: grau del polinomi*/
    for(i=0;i<=m;i++){
        res += polinomi[i]*pow(x,i);
    }
    return res;
}

double derievaluar(double x, double *polinomi, int m){
    double *polinomiderivat;
    int i;
    /*x: Array n: grau del polinomi*/
    
    /*Fem la derivada del polinomi:*/
    polinomiderivat = (double*)malloc(m*sizeof(double));
    for(i = 0;i<=m-1;i++){
        polinomiderivat[i] = polinomi[i+1]*(i+1);
    }
    /*Evaluem la derivada*/
    return evaluar(x, polinomiderivat, m-1);
    free(polinomiderivat);
}

int newton (double x0, double *sol, double eps, int it_max){
    double xant;
    int i;
    *sol=x0;
    for(i=0;i<it_max;i++){
        xant = *sol;
        *sol -= (evaluar(*sol,pol,n) / derievaluar(*sol,pol,n) );
        if( fabs(evaluar(*sol,pol,n)) < eps || fabs(*sol-xant)<eps){
            return 0;
        }
    }
    /*Si hem arribat aquí, vol dir que hem fet it_max passos sense trobar convergència.*/
    return 1;
}


int main (void){
    int i,k, it_max, solnewton, solsecant;
    double x, xant, polx, polxant, eps, h, C, *a, *b, *c;
    
    /*Dades arbitràries:*/
    eps = 1.e-10; /*epsisio desitjada*/
    it_max = 15;
    k = 37; /*Nombre d'intents per fer l'interval [-C,C] més petit.*/
    
    /*Demanem grau i coeficients polinomi:*/
    printf("Digues el grau: ");
    scanf("%d",&n);
    printf("Escriu els coeficients del polinomi (de grau menor a major): ");
    /*Reservem la memòri pel polinomi*/
    pol = (double*)malloc((n+1)*sizeof(double));
    C =0;/*Anem calculant C a mesura que ens donen els graus*/
    for(i=0;i<=n;i++){
        scanf("%le",&pol[i]);
        C += fabs(pol[i]);
    }
    
    /*Tenim interval [-C,C]. Volem trobar un interval més petit*/
    polxant = evaluar(-C,pol,n);
    xant = -C;
    /*Reservem memòria per les variables auxiliars a,b,c: */
    a = (double*)malloc(sizeof(double));
    b = (double*)malloc(sizeof(double));
    c = (double*)malloc(sizeof(double));
    printf("C PEQUE: %.26le\n",*c);
    printf("C: %.26le\n",C);
    for(i=1;i<k;i++){
            solnewton = newton(xant,c,eps,it_max);
            if(solnewton==0){
                printf("Newton: %.26le\n",*c);
            }else{
                printf("No convergencia amb Newton.\n");
            }
        }
    
    return 0;
}
 
