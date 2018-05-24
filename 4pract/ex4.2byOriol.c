#include <stdio.h>
#include <math.h>

double f(double x)
{
return x*pow(e,-x)-0.06064;  //aplicació 1.4
}

double g(double x)
{
return 0.06064*pow(e,x); // aïllo la x
}
int iteracioSimple(double x0, double *sol, double tol, int *iter, int it_max){
    int i=0;
    while (i<=it_max){
        p = g(x0);

        if((fabs(p-x0))<Tol){
            sol=p;
            iter=i;
            //printf("%lf", &p);
            return 0;
        }
        printf("Iteration %d: Current value = %lf\n", i, p);

        i++;  //i=i+1
        x0=p;

        if (i>it_max)
        {
        return 1;
        }

    }

}

int main()
{
    double p, x0, tol,*solucio;
    int i=1;
    int it_max,sol,*iter;

    printf("Enter x0 inicial : "); //
    scanf ("%lf", &x0);

    printf("Desired Tolerance: ");
    scanf ("%lf", &tol);

    printf("Maximum Iterations: ");
    scanf ("%d", &it_max);
    sol=iteracioSimple(x0,*solucio,tol,iter,it_max);
    if(sol==1){
        printf("Method Failed");
    }
    if(sol==0){
        printf("Iteration %d: Punt fix = %lf\n", iter, solucio);
    }

    
}