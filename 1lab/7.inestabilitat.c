/* 
*/

#include <stdio.h> 
#include <math.h> 
#include <limits.h>

int main(void)
{
    int i;
    float y, min, max;
    
    y = log(6./5);
    printf("y0 = %+.10e \n", y);
    for(i=1; i<=25; i++){
        y = 1./i - 5*y;
        max = 1./(5*(i+1));
        min = 1./(6*(i+1));
        printf("y%2d = %+.10e; min=%+.6e; max=%+.6e\n", i, y, min, max);
        
    }
    
    y= 0;
    printf("\n\ny50 = %f \n", y);
    for(i=49; i>=25; i--){
        y = 1./5 * (1./(i+1) - y);
        max = 1./(5*(i+1));
        min = 1./(6*(i+1));
        printf("y%2d = %+.10e; min=%+.6e; max=%+.6e\n", i, y, min, max);
    }
  
   return 0;
}
