#include<stdio.h>    
#include<stdlib.h> 
#include <math.h>

double e = 2.71828182845904523536028747135266249775724709369995957496697;

double func(double x){
    double fx;
    
    /*
     fx = (sin(x)*sin(x)-cos(x));
     fx = sqrt(2+x);
     fx = pow(e, pow(x, 3) );
     */
    
    fx = pow(e, pow(x, 3) );
    
    return fx;
}
double deriv(double x){
    double dx;
    
    /*
     dx = ((2*sin(x)*cos(x))+sin(x));
     dx = 1/(2*sqrt(2+x));
     dx = 3*x*x * pow(e, pow(x, 3) );
     */
    
    dx = 3*x*x * pow(e, pow(x, 3) );
    
    return dx;
}


double primDeriv_1(double c, double h){
    double primDeriv1;
    
    primDeriv1 = (func(c+h) -func(c)) / h;
    
    /*printf("F1=%.10e \n",primDeriv1);*/
    return primDeriv1;
}


double primDeriv_2(double c, double h){
    double primDeriv;
    
    primDeriv=(func(c+h)-func(c-h)) / (2*h);
    
    return primDeriv;
}

double primDeriv_3(double c, double h){
    double primDeriv;
    
    primDeriv = (func(c-(2*h)) -8*func(c-h) +8*func(c+h) -func(c+(2*h))) / (12*h);
    
    return primDeriv;
}

int main(void){
    int i, n;
    double r,c,hi, F1,F2,F3, derivada, err1,err2,err3;
    
    printf("Introdueix la c ");
    scanf("%lf",&c);
    printf("Introdueix la r ");
    scanf("%lf",&r);
    printf("Introdueix la n ");
    scanf("%d",&n);
    printf("Introdueix h0 ");
    scanf("%lf",&hi);
    
    for(i=1;i<=n;i++){
        printf("\n i=%d,  hi=%.5e \n",i, hi);
        
        F1=primDeriv_1(c,hi);
        F2=primDeriv_2(c,hi);
        F3=primDeriv_3(c,hi);
        
        derivada=deriv(c);
        printf("DERIVADA=%.10e \n",derivada);
        printf("der1= %.10e  der2= %.10e  der3= %.10e\n", F1,F2,F3);
        
        err1=fabs(derivada-F1);
        err2=fabs(derivada-F2);
        err3=fabs(derivada-F3);
        hi=hi/r;
        printf("err1= %.10e  err2= %.10e  err3= %.10e\n",err1,err2,err3);
        
    }
    return 0;
    
}
