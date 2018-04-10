/* 1.limits-int.c */
/* Aquest programa cerca el rang dels valor que pot prendre la variable int */

#include <stdio.h>

int main (void) {
    
    int i, n, num, result, limit;
    n = 10;
    for (i = 0; i < n; i++) {
        limit = 2 * n;
        result = 1;
        num = 1;
        while (num < limit) {
            num ++;
            result *= num;
        }
        
        printf("%d,%d\n", limit, result);
    }
    
    return 0;
}