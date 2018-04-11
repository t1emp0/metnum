/* 3.itera.c */
/* Demostreu, per inducció a partir de t0 = 1, que es verifica tn = 1, per tot n.
 * a) Feu un programa que calculi, en precisió simple, els 30 primers termes de la successió {tn }n≥0 , a partir d’un valor de x0 que s’ha de llegir.
 * Executeu-lo per a diferents valors de x0 . Per als valors x0 = 0.3 i x0 = 0.8, escriviu la sortida en els fitxers f03.res i f08.res, respectivament. Feu la gràfica d’aquests dos casos, mitjançant el programa gnuplot. Dibuixeu les gràfiques per als rangs de t següents: [0.5, 2.5] i [0.99, 1.01].
 * 
 * b) Modifiqueu el programa anterior per treballar en precisió doble i calculant 60 termes de la successió.
 * Executeu-lo per a diferents valors de x0; en particular, podeu agafar els valors x0 = 0.35, 0.55, 0.75, 0.85. Feu-ne la gràfica mitjançant el programa gnuplot.
 * 
 * Comenteu els resultats.
 */


#include <stdio.h>
#include <math.h>

int main (void) {
    int i;
    float x0f, y0f, t0f, x1f;
    double x0d, y0d, t0d, x1d;

        
    /*
    printf("Introdueix x0, float: ");
    scanf("%f", &x0f);
    
    y0f = sqrt(1 - x0f*x0f);
    t0f = x0f * x0f + y0f * y0f;

    for (i=0; i < 30; i++) {

        printf("x%d: %+.6e\n", i, x0f);
        printf("y%d: %+.6e\n", i, y0f);
        printf("t%d: %+.6e\n", i, t0f);
        
        printf("t%d: %16.8e\n", i, t0f);
        
        x1f = 2.f * x0f * y0f;
        y0f = x0f * x0f - y0f *y0f;
        t0f = x1f * x1f + y0f * y0f;
        x0f = x1f;
    }
    
  
    
    printf("Introdueix x0, double: ");
    */
    
    scanf("%le", &x0d);
    
    y0d = sqrt(1 - x0d*x0d);
    t0d = x0d * x0d + y0d * y0d;
    
    for (i=0; i < 60; i++) {
        /*
        printf("x%d: %+.6e\n", i, x0d);
        printf("y%d: %+.6e\n", i, y0d);
        printf("t%d: %+.6e\n", i, t0d);
        */
        
        printf("%+24.16le\n", t0d);
        
        x1d = 2. * x0d * y0d;
        y0d = x0d * x0d - y0d *y0d;
        t0d = x1d * x1d + y0d * y0d;
        x0d = x1d;
    }
    
    
    return 0;
} 
