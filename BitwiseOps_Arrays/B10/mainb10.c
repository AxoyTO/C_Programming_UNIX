#include <stdio.h>
#define M 10

int main()
{
    int A[M], i, imax=0, max, remax;

    for(i=0;i<M;i++)
        scanf("%d",&A[i]);

    max=A[0];
    remax=A[1];

    for(i=0;i<M;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
            imax=i;
        }
    }
    
    if(max==A[1]){
        remax=A[0];
    }
    
    for(i=0;i<M;i++)
    {
        if(i!=imax && A[i]>remax)
            remax=A[i];
    }

    printf("%d",max+remax);
    return 0;
}
