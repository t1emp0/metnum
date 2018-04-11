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
    }
    return 1;
} 
