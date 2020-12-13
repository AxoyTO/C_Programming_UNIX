#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lnode{
    char str[20];
    struct lnode *prev;
    struct lnode *next;
};

struct lnode *add_first(struct lnode *cur, char *str)
{
    struct lnode *new;
    while(cur->prev)
        cur = cur->prev;
    new = (struct lnode*)malloc(sizeof(struct lnode));
    if(!new)
        return NULL;
    strcpy(new->str, str);
    new->prev = NULL;
    new->next = cur;
    cur->prev = new;

    return new;
}

void printList(struct lnode *cur){
    while(cur)
    {
        printf("%s", cur->str);
        if(cur->next!=NULL)
            printf("\n");
        cur = cur->next;
    }
}

void deleteList(struct lnode **head)
{
    struct lnode *list = *head;
    while(*head)
    {
        *head = (*head)->next;
        free(list);
        list=*head;
    }
}

int main() {
    struct lnode *head = NULL;
    char buf[20];
    char tmp;
    int len;

    head = (struct lnode*)malloc(sizeof(struct lnode));
    if(head==NULL)
        exit(1);

    while(scanf("%19s", buf) != EOF)
    {
        len = strlen(buf);
        if(buf[len-1]=='.')
            buf[len-1]='\0';
        struct lnode *ptr = NULL;
        ptr = add_first(head, buf);
        if(ptr!=NULL)
            head = ptr;
    }

    printList(head);
    deleteList(&head);

    return 0;
}
