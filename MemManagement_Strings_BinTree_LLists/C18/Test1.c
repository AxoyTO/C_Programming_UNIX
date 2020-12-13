#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode{
    char str[20];
    struct lnode *prev;
    struct lnode *next;
};
void Print_list(struct lnode *cur);
struct lnode* add_end(struct lnode *cur, char *buf);
void FreeList(struct lnode *cur);
struct lnode *add_first(struct lnode *cur, char *buf);
struct lnode* delete_world(struct lnode*cur, char *cmp);
struct lnode* insert(struct lnode *cur, char *buf, int n);

int main(int argc, char**argv)
{   int i=0,n;
    struct lnode *head=NULL;
    struct lnode *ptr = NULL;
    char buf [20], cmp[20];
   
    while (scanf("%19s", buf)!=EOF){
        head=add_end(head, buf);
        i++;
    }
    if(head!=NULL){
    while (head->prev!=NULL) {
        head=head->prev; }}

if (argc==4){
    if(strcmp(argv[1], "-i")==0){
        n=atoi(argv[3]);
        if(n>0&&n<=i){
            head=insert(head, argv[2],n);
            
        }
    }
}
if(argc==3){
    if(strcmp(argv[1], "-af")==0){
        ptr = add_first(head, argv[2]);
        if (ptr!=NULL)
        head = ptr;}
    if (strcmp(argv[1], "-ae")==0){
       head=add_end(head, argv[2]);}
    if (strcmp(argv[1],"-d")==0){
        head=delete_world(head,argv[2]);}
        while (head->prev!=NULL) {
            head=head->prev;} }
    
    Print_list(head);
    FreeList(head);
    return 0;
}
void Print_list(struct lnode *cur)
{
    if(cur==NULL){
        exit(0);}
    while(cur){
        printf ("%s ", cur->str);
        cur = cur->next; }
}


struct lnode* add_end(struct lnode *cur, char *buf)
{
    struct lnode *new;
    struct lnode *new1=cur;
    new = (struct lnode*)malloc(sizeof(struct lnode));
    if (new==NULL) exit(1);
    strcpy (new->str, buf);
    if (cur==NULL){
        cur=new;
        cur->prev=NULL;
        cur->next=NULL;
        return cur; }
    while (new1->next!=NULL){
          new1=new1->next; }
    new1->next=new;
    new->prev=new1;
    new->next=NULL;
    return cur;
}

struct lnode *add_first(struct lnode *cur, char *buf)
{
    struct lnode *new;
    if(cur!=NULL){
    while(cur->prev)
        cur = cur->prev;
    }
    new = (struct lnode*)malloc(sizeof(struct lnode));
    if(!new) return NULL;
    strcpy(new->str, buf);
    if(cur!=NULL){
    new->prev = NULL;
    new->next = cur;
    cur->prev = new;
    return new;
    }else{
        new->prev=NULL;
        new->next=NULL;
        return new;
    }
}

struct lnode* delete_world(struct lnode*cur, char *cmp){
    struct lnode *q1, *q2, *q3;
    
    if (cur==NULL) {
        exit(0);}
    q3=cur;
    q1=cur->prev;
    q2=cur->next;
while (1) {
    if(strcmp(q3->str, cmp)==0){
        if(q1==NULL&&q2!=NULL){ //1
            q2->prev=NULL;
            free(q3);
            return q2;}
        if(q1==NULL&&q2==NULL){
            free(q3);
            exit(0);}
        if(q1!=NULL&&q2==NULL){
            q1->next=NULL;
            free(q3);
            return cur;}
        if(q1!=NULL&&q2!=NULL){
            q1->next=q2;
            q2->prev=q1;
            free(q3);
            break;
        }
        }
    q3=q3->next;
    if(q3==NULL){break;}
    q1=q3->prev;
    q2=q3->next;}
        return cur;
        
}
struct lnode* insert(struct lnode *cur, char *buf, int n)
{struct lnode *new;
 struct lnode *new1=cur;
 int i=1;
    new = (struct lnode*)malloc(sizeof(struct lnode));
    if (new==NULL) exit(1);
    strcpy (new->str, buf);
    if (cur==NULL)
        exit (0);
    for (i=0; i<n-1;i++){
       if (new1->next)
       new1=new1->next;}
    if (new1->next!=NULL){
        new1->next->prev=new;
        new->next=new1->next;
        new->prev=new1;
        new1->next=new;}
    else if (new1->next==NULL)
    cur=add_end(cur,buf);
    return cur;
        
}

void FreeList(struct lnode *cur)
{
    struct lnode *next=NULL;
    if (cur!=NULL){
    while(cur->prev)
        cur=cur->prev;// переходим на первый элемент
    while (cur)
    {
        next=cur->next;
        if(cur!=NULL){
            free (cur);
        }
        cur=next;
    }
}}
