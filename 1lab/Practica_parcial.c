/* 
*/

#include <stdio.h> 
#include <math.h> 
#include <limits.h>

int main(void)
{
    int i;
    double c, y, min, max;
    
    c= 18071996./1e+7;
    y = 1/c*log((c+7.)/7.);
    printf("y0 = %+.10e \n", y);
    for(i=1; i<=40; i++){
        y = 1./c * (1./i - (7*y));
        min = 1./((7+c)*(i+1));
        max = 1./(7*(i+1));
        printf("y%2d = %+.10e; min=%+.6e; max=%+.6e\n", i, y, min, max);
        
    }
    
    y= ((1./((7+c)*(i+1)))+(1./(7*(i+1))))/2;
    /* y = 0; */
    printf("\n\ny80 = %f \n", y);
    for(i=79; i>=40; i--){
        y = (1./7) * ((1./(i)) - c * y);
        /* y = (1./7) * ((1./(i+1)) - c * y); */
        min = 1./((7+c)*(i+1));
        max = 1./(7*(i+1));
        printf("y%2d = %+.10e; min=%+.6e; max=%+.6e\n", i, y, min, max);
    }
  
   return 0;
}
