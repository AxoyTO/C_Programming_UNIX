#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char str[20];
    struct lnode *prev;
    struct lnode *next;
};

void Print_list(struct lnode *cur);

int insert(struct lnode *cur, char *buf);

int add_end(struct lnode *cur, char *buf);

struct lnode *add_first(struct lnode *cur, char *buf);

void FreeList(struct lnode *cur);

int main() {
    struct lnode *head = NULL;
    char buf[20];
    scanf("%19s", buf);

    head = (struct lnode*)malloc(sizeof(struct lnode));
    if(head==NULL)
        exit(1);

    strcpy(head->str, buf);
    head -> next = NULL;
    head -> prev = NULL;

//    Print_list(head);
    while (scanf("%19s", buf) != EOF) {
        struct lnode *ptr = NULL;
        ptr = add_first(head, buf);
        if (ptr != NULL)
            head = ptr;
        //     if(add_end(head, buf))
        //        return -1;
    }
    if (insert(head, "inserted"))
        return -1;

    Print_list(head);
    FreeList(head);
// 	Print_list(head);
    return 0;
}

void FreeList(struct lnode *cur) {
    while (cur->prev)
        cur = cur->prev;
    while (cur) {
        struct lnode *next = cur->next;
        free(cur);
        cur = next;
    }
    free(cur);
}

struct lnode *delete_element(struct lnode *cur, char *str);

void Print_list(struct lnode *cur) {
    printf("\n");
    while (cur) {
        printf("%s ", cur->str);
        cur = cur->next;
    }
//    printf("\n");
}

int add_end(struct lnode *cur, char *buf) {
    if (!cur)
        return -1;
    struct lnode *new;
    while (cur->next)
        cur = cur->next;
    new = (struct lnode *) malloc(sizeof(struct lnode));
    if (!new) exit(1);
    strcpy(new->str, buf);
    new->prev = cur;
    new->next = NULL;
    cur->next = new;

    return 0;
}

int insert(struct lnode *cur, char *buf)        //insert element
{
    if (cur == NULL)
        return -1;
    if (cur->next == NULL)
        return add_end(cur, buf);
    else {
        struct lnode *new;
        new = (struct lnode *) malloc(sizeof(struct lnode));
        if (!new) return (1);
        strcpy(new->str, buf);
        new->prev = cur;
        new->next = cur->next;
        cur->next->prev = new;
        cur->next = new;
    }
    return 0;
}

struct lnode *add_first(struct lnode *cur, char *buf)    //add first element
{
    struct lnode *new;
    if (cur == NULL) {
        new = (struct lnode *) malloc(sizeof(struct lnode));
        if (!new)
            return NULL;
        strcpy(new->str, buf);
        new->next = NULL;
        new->prev = NULL;
        return new;
    }
    while (cur->prev)
        cur = cur->prev;
    new = (struct lnode *) malloc(sizeof(struct lnode));
    if (!new) return NULL;
    strcpy(new->str, buf);
    new->prev = NULL;
    new->next = cur;
    cur->prev = new;

    return new;
}
