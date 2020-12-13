#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLong 20
typedef struct node{
    char Inhalt[MaxLong];
    struct node* bisherige;
    struct node* letzter;
}node;
node *nue(node *index,char aparm[MaxLong]);//ok
node *af(node *index,char aparm[MaxLong]);//ok
node *ae(node *index,char aparm[MaxLong]);//ok
node *i(node *index,char aparm[MaxLong],int lp);//ok
node *los(node *index,char aparm[MaxLong]);//ok
node *zerst(node *index);//ok
int main(int argc,char *argv[]){
    char aparm[MaxLong];
    node *index=NULL;
    //put addnation here
    while (scanf("%20s",aparm)!=EOF) {
        index=nue(index,aparm);
    }
    //zur
    if(index!=NULL){
        while (index->bisherige!=NULL) {
            index=index->bisherige;
        }
    }
    //addnation
    if(argc==3){
        if(strcmp(argv[1],"-ae")==0){
            index=ae(index, argv[2]);
        }
        if(strcmp(argv[1],"-af")==0){
            index=af(index, argv[2]);
        }
        if(strcmp(argv[1],"-d")==0){
            index=los(index, argv[2]);
        }
    }
    if(argc==4){
        if(strcmp(argv[1],"-i")==0){
            if(atoi(argv[3])!=0){
            index=i(index, argv[2], atoi(argv[3]));
            }
        }
    }
    //end
    while (index!=NULL) {
        printf("%s ",index->Inhalt);
        index=index->letzter;
    }
    //zur
    if(index!=NULL){
        while (index->bisherige!=NULL) {
            index=index->bisherige;
        }
    }
    //delete all.
    if(index!=NULL){
        zerst(index);
    }
    return 0;
}
node *nue(node *index,char aparm[MaxLong]){
    node *Node=NULL;
    Node=malloc(sizeof(node));
    if(Node==NULL){
        exit(-1);
    }
    if(index!=NULL){
        index->letzter=Node;
    }
    Node->bisherige=index;
    Node->letzter=NULL;
    strcpy(Node->Inhalt, aparm);
    index=Node;
    return index;
}
node *zerst(node *index){
    node *aparm=NULL;
    while (index->letzter!=NULL) {
        aparm=index;
        index=index->letzter;
        free(aparm);
    }
    free(index);
    index=NULL;
    return index;
}
node *ae(node *index,char aparm[MaxLong]){
    node *Node=NULL;
    Node=malloc(sizeof(node));
    if(Node==NULL){
        exit(-1);
    }
    strcpy(Node->Inhalt, aparm);
    if(index==NULL){
        index=Node;
        index->bisherige=NULL;
        index->letzter=NULL;
        return index;
    }
    node *rindex=index;
    while (rindex->letzter!=NULL) {
        rindex=rindex->letzter;
    }
    rindex->letzter=Node;
    Node->bisherige=rindex;
    Node->letzter=NULL;
    return index;
}
node *af(node *index,char aparm[MaxLong]){
    node *Node=NULL;
    Node=malloc(sizeof(node));
    if(Node==NULL){
        exit(-1);
    }
    strcpy(Node->Inhalt, aparm);
    if(index==NULL){
        index=Node;
        index->bisherige=NULL;
        index->letzter=NULL;
        return index;
    }
    Node->letzter=index;
    Node->bisherige=NULL;
    index->bisherige=Node;
    index=Node;
    return index;
}
node *i(node *index,char aparm[MaxLong],int lp){
    int lps=1;
    node *Node=NULL;
    Node=malloc(sizeof(node));
    strcpy(Node->Inhalt, aparm);
    if(index==NULL){
        free(Node);
        return index;
    }
    node *rindex=index;
    for(lps=1;lps<lp;lps++){
        if(rindex->letzter!=NULL){
            rindex=rindex->letzter;
        }else{
            return index;
        }
        
    }
    if(rindex->letzter!=NULL){
        rindex->letzter->bisherige=Node;
        Node->letzter=rindex->letzter;
        Node->bisherige=rindex;
        rindex->letzter=Node;
    }else if(rindex->letzter==NULL){
        index=ae(index, aparm);
    }
    return index;
}
node *los(node *index,char aparm[MaxLong]){
    if(index==NULL){
        return index;
    }
    node *rindex=index,*losch=NULL;
    while (rindex!=NULL) {
        if(strcmp(rindex->Inhalt, aparm)==0){
            losch=rindex;
            if(rindex->bisherige!=NULL){
                rindex=rindex->bisherige;
                if(losch->letzter!=NULL){
                    rindex->letzter=losch->letzter;
                    losch->letzter->bisherige=rindex;
                    free(losch);
                    return index;
                }else{
                    rindex->letzter=NULL;
                    free(losch);
                    return index;
                }
            }else if(rindex->bisherige==NULL&&rindex->letzter!=NULL){
                losch=rindex;
                index=losch->letzter;
                index->bisherige=NULL;
                free(losch);
                return index;
            }else if(rindex->bisherige==NULL&&rindex->letzter==NULL){
                free(index);
                index=NULL;
                return index;
            }
        }
        rindex=rindex->letzter;
    }
    return index;
}
