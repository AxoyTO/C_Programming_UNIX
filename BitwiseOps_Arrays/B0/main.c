#include <stdio.h>
#include <stdlib.h>

int main (){
    int **a;
    int **b;
    int **c;
    int i, j, n, m, h, l, k;
    
    scanf ("%d%d", &n,&m);
    
    a= (int**)malloc(n*sizeof (int*)); // строки
        if (a==NULL)
        {			
			printf("-1");
        exit (0);}
        
    for (i=0; i<n; i++){
		a[i]=NULL;
        a[i]=(int*)malloc(m*sizeof(int)); // столбцы
        if (a[i]==NULL)
        {
						printf("-1");
            exit (0);}
		}
    for (i=0; i<n;i++)
        for (j=0; j<m; j++)
            scanf ("%d", &a[i][j]);
    
    scanf ("%d%d", &h,&l);
    
    b= (int**)malloc(h*sizeof (int*)); // строки
        if (b==NULL)
        {
						printf("-1");
        exit (0);
	}
    for (i=0; i<h; i++){
		b[i]=NULL;
        b[i]=(int*)malloc(l*sizeof(int)); // столбцы
        if (b[i]==NULL)
        {
			printf("-1");
            exit (0);}
    }
    for (i=0; i<h;i++)
        for (j=0; j<l; j++)
            scanf ("%d", &b[i][j]);
    
    
if (m!=h){
    printf ("-1");
     for (i=0; i<h; i++)
 free (b[i]);
 free (b);
 b=NULL;
 for (i=0; i<n; i++)
 free (a[i]);
 free (a);
 a=NULL;
    exit(0);}
if (m==h){
    c=(int**)malloc(n*sizeof (int*));
          if (c==NULL)
          {			
			  printf("-1");
            exit (0);}
        
    for (i=0; i<n; i++){
		c[i]=NULL;
		c[i]=(int*)malloc(l*sizeof(int)); // столбцы
        
        if (c[i]==NULL)
        {			printf("-1");
            exit (0);}}
            
    for (i=0; i<n; i++)
    for (j=0; j<l;j++){
          c[i][j]=0;
    for (k=0; k<m; k++)
          c[i][j]+=a[i][k]*b[k][j];
        }
        
    }
        
for (i=0; i<n; i++){
    for (j=0; j<l; j++)
    printf ("%d ", c[i][j]);
    printf ("\n");
}
 for (i=0; i<n; i++)
 free (c[i]);
 free (c);
 c=NULL;
 for (i=0; i<h; i++)
 free (b[i]);
 free (b);
 b=NULL;
 for (i=0; i<n; i++)
 free (a[i]);
 free (a);
 a=NULL;
 
 return 0;
    
}
