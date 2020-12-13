
 #include<stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #define MaxLong 20
 typedef struct Identi{
     char name[MaxLong];
     int Alter;
 }Identi;
 int main(int argc,char *argv[]){
     Identi aparm;
     Identi index[MaxLong];
     int mainLoop=0;
     int MaxId=0;
     //Wird verwendet ,und das Alter zu initalisisren
     for(int n=0;n<MaxLong;n++){
         index[n].Alter=-1;
     }
     while((scanf("%20s%d",aparm.name,&aparm.Alter)!=EOF)&&(mainLoop<20)){
         strcpy(index[mainLoop].name, aparm.name);
         index[mainLoop].Alter=aparm.Alter;
         mainLoop++;
     }
     //printf("\n");
     for(int i=0;i<mainLoop;i++){
         for(int i=0;i<MaxLong;i++){
             if(index[i].Alter>=0&&(i!=MaxId)&&(index[i].Alter>=0)){
                 if(strcmp(index[MaxId].name, index[i].name)>0){
                     MaxId=i;
                 }
                 if(strcmp(index[MaxId].name, index[i].name)==0){
                     if(index[MaxId].Alter>index[i].Alter){
                         MaxId=i;
                     }
                 }
             }
         }
         printf("%s %d\n",index[MaxId].name,index[MaxId].Alter);
         index[MaxId].Alter=-1;
         index[MaxId].name[0]='~';
     }
     return 0;
 }
