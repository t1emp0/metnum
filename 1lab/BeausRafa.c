/* BeausRafa.c
Observació de la cancel·lació que hi ha en el càlcul de
(1/sqrt(x)) ( (1-x)/(1+x) - 1/(1+cx) )
quan x ~ 0
Una expressió equivalent és  (sqrt(x)) ( (c-2-c*x) / (1 + x*(1+c+c*x)));
*/

#include <stdio.h> 
#include <math.h> 

int main(void)
{
   int i, n = 12;
   double c, x, y, r;
   
   c= 2. + 18071996./1e+7;
   
   printf("    x        y amb cancel·lacio      y sense cancel·lacio      ea            er\n");
   for (i=1; i<=n; i++) {
      x = pow(10.,-i);
      y = (pow(x,(-0.5))) * (((1-x)/(1+x)) - 1/(1+c*x));
      r = (pow(x,(+0.5))) * ((c-2-c*x) / (1+x*(1+c+c*x)));
      printf(" %+.2e %+.16e %+.16e %+.6e %+.6e\n", x, y, r, fabs(r-y), fabs(r-y)/r);
   }

   return 0;
}
