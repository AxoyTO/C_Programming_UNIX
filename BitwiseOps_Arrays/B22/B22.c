

#include <stdio.h>
#include <stdlib.h>
int** inMart(int y,int x,int flag);
int **release(int **mart,int y);
int outMart(int **Mart,int y,int x);
int main(int argc,char*argv[]){
    int **mart1=NULL;
    int **mart2=NULL;
    int y1,x1;
    int y2,x2;
    int aparm=0;
    scanf("%d%d",&y1,&x1);
    mart1=inMart(y1,x1,0);
    scanf("%d%d",&y2,&x2);
    mart2=(inMart(y2, x2,0));
    if(x1!=y2){
        printf("-1");
    }else{
        int **mart3=NULL;
        mart3=inMart(y1, x2, 1);
        for(int y=0;y<y1;y++){
            for(int x=0;x<x2;x++){
                aparm=0;
                for(int index=0;index<x1;index++){
                    aparm=mart1[y][index]*mart2[index][x]+aparm;
                }
                mart3[y][x]=aparm;
            }
        }
        outMart(mart3, y1, x2);
        mart3=release(mart3,y1);
    }
    mart1=release(mart1,y1);
    mart2=release(mart2,y2);
    return 0;
}
int** inMart(int y,int x,int flag){
    int **Mart=NULL;
    Mart=(int**)malloc(sizeof(int*)*y);
    if(Mart==NULL){
        printf("-1");
        exit(0);
    }
    for(int n=0;n<y;n++){
        Mart[n]=NULL;
        Mart[n]=(int*)malloc(sizeof(int)*x);
        if(Mart[n]==NULL){
            printf("-1");
            exit(0);
        }
    }
    if(flag==1){
        return Mart;
    }
    for(int y_l=0;y_l<y;y_l++){
        for (int x_l=0; x_l<x; x_l++) {
            scanf("%d",&Mart[y_l][x_l]);
        }
    }
    return Mart;
}
int outMart(int **Mart,int y,int x){
    for(int y_l=0;y_l<y;y_l++){
        for (int x_l=0; x_l<x; x_l++) {
            printf("%d ",Mart[y_l][x_l]);
        }
        printf("\n");
    }
    return 0;
}
int **release(int **mart,int y){
    for (int i=0; i<y; i++){
        free (mart[i]);
    }
    free(mart);
    mart=NULL;
    return mart;
}

