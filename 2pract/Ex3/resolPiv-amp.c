#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


/*Eliminació Gaussiana amb pivotatge parcial*/
int gaussPivot(double**A, int n, double tol){
    double max, *vauxiliar, m;
    int k,v,i,j;
    /*Vector auxiliar per a l'intercanvi de files: Serà de mida n+1 per guardar també bk.*/
    vauxiliar = (double *)malloc((n+1)*sizeof(double));
    /*Cal fer n-1 etapes: */
    for(k=0;k<n-1;k++){
        /*Busquem v pertanyent a {k+1,....,n} tq avk(n) sigui el màxim: */
        max = A[k][k];
        v = k;
        for(i=k+1;i<n;i++){
            if(fabs(A[i][k]) > fabs(max)){
                max = A[i][k];
                v = i; 
            }
        }
        /*Si el màxim es menor a la tolerància, ja hem acabat:*/
        if(fabs(max) < tol) return 0;
        /*Si v!=k Intercanviem les files k i v (a partir de la columna k, ja que les altres seran 0. */
        if(k!=v){
            /*Guardem fila k a vauxiliar: */
            for(i=k;i<n+1;i++){
                vauxiliar[i] = A[k][i];
            }
            
            /*Passem la fila v a k:*/
            for(i=k; i < n+1; i++){
                A[k][i] = A[v][i];
            }

            /*Passem el vector auxiliar, on guardem la fila k, a v:*/
            for(i=k; i < n+1; i++){
                A[v][i] = vauxiliar[i];
            }    
        }
        
        /* Ara fem els passos que correspondrien a l'Eliminació Gaussiana*/
        for (i = k+1; i < n; i++){
            
            m = A[i][k]/A[k][k];
            A[i][k] = m; /*Guardem el multiplicador per a futurs usos, com fact LU*/
            
            for (j = k+1; j < n+1; j++){
                A[i][j] = A[i][j] - m*A[k][j];
            }
        }
    }
    return 1;
}


/*
 * Resol un sistema d equacions triangular per substitucio endarrera
 */
int substitucio(int n, double **matU, double *x){
    int i, j;
    double sumatori, sum = 1;
    double tolerancia = 1.e-14;
    
    for (i=0; i < n; i++){
        sum *= matU[i][i];
    }
    if (fabs(sum) < tolerancia){
        return 0;
    }
    
    x[n-1] = matU[n-1][n]/matU[n-1][n-1];
    
    for (i = n-2; i >= 0; i--){
        sumatori = 0.;
        for (j = i+1; j < n; j++){
            sumatori += matU[i][j]*x[j];
        }
        x[i] = (matU[i][n] - sumatori) / matU[i][i];
    }
    return 1;
}


int main(void){
    double ** A, * x;
    int n, i, j, k;
    double tolerancia;
    FILE *dades,*sol;
    char fname[128], fname2[128];
    
    tolerancia = 1.e-14;
    
    srand( time(NULL) );/*perque el primer sigui random de veritat*/
    printf("Introdueix el nom de l'arxiu a llegir ");
    k = scanf("%s",fname);
    
    dades = fopen( fname, "r");
    
    k = fscanf(dades, "%d", &n);
    /* Dimensio de la matriu = n */
    
    /*Reservem memòria per la matriu A*/
    /*Dim de la matriu A: n files i n+1 cols*/
    A  = (double **)malloc( n*sizeof(double *) );
    for (i=0; i<n; i++) {
        A[i] = (double *)malloc( (n+1)*sizeof(double) );
    }

    /*vector de mida n*/
    x = (double *)malloc(n*sizeof(double));
    
    
   /*Llegim la matriu*/
    for( i = 0; i < n; i++ ){
        for( j = 0; j < n+1; j++ ){
            k = fscanf(dades, "%lf", &A[i][j]);
        }
    }
    fclose(dades);
    
    
    printf("\nMATRIU ENTRADA\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%+.2e  ", A[i][j]);
        }
        printf("| x%i  =  %+.2e\n", i, A[i][n]);
    }
    
    /*Fem Gauss*/
    if (gaussPivot(A,n,tolerancia) == 0) {
        printf("No s'ha pogut triangular la matriu!\n");
        return 1;
    }
    
    /*Mostrem la matriu amb Gauss fet*/
    printf("\nGAUSS FET\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i <= j) printf("%+.2e  ", A[i][j]);
            else printf("+0.00+e00  ");
        }
        printf("| x%i  =  %+.1e\n", i, A[i][n]);
    }
    
    /*Fem Subst endarrera*/
    if (substitucio(n,A,x) == 0) {
        printf("No s'ha pogut realitzar substitució endarrera!\n");
        return 1;
    }

    /*Mostrem solucio*/
    printf("\nLa solucio es: \n");
    for (i = 0; i < n; i++){
        printf("x%d = %e\n", i, x[i]);
    }
    
    /* Gaurdem en l'arxiu */
    printf("Introdueix el nom de l'arxiu on guardar la solució: ");
    k = scanf("%s",fname2);
    sol = fopen( fname2, "w");
    
    
    /* Guardem també la dimensió, la matriu i la seva solució: */ 
    fprintf(sol,"Dimensió i matriu ampliada:\n");
    fprintf(sol,"%d\n",n);
    for( i = 0; i < n; i++ ){
        for (j = 0; j <= n; j++){
            if (i <= j) fprintf(sol, "%+.2e  ", A[i][j]);
            else fprintf(sol, "+0.00e+00  ");
        }
        fprintf(sol,"\n"); 
    }
    
    fprintf(sol,"\nSolució al sistema:\n");
    for( i = 0; i < n; i++ ){
        fprintf(sol, "%+e\n", x[i]);
    }
    
    fprintf(sol,"\n"); 
    fclose(sol);
    
    return 0;
}
