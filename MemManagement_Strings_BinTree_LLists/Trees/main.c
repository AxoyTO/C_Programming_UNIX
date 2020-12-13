#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int key;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *add_tnode(struct tnode *p, int key);
void PrintTree(struct tnode *, int);
void FreeTree(struct tnode *p);
void Print2Min(struct tnode *p, int *flag);

int main() {
    struct tnode *root = NULL;
    int tkey;
    int flag = 2;

    while (scanf("%d", &tkey) != EOF)
        root = add_tnode(root, tkey);
    //PrintTree(root, 0);
    //printf("\n");
    Print2Min(root, &flag);
    FreeTree(root);
    return 0;
}

void Print2Min(struct tnode *p, int *flag) {
    // printf("FLAG OUTSIDE = %d\n", *flag);
    if (*flag > 0) {
        if (p->left != NULL) {
            Print2Min(p->left, flag);
            if (*flag == 0) {
                // printf("FLAG INSIDE = %d\n", *flag);
                return;
            }
            printf("%d", p->key);
            (*flag)--;
            //  printf("THAT FLAG = %d\n", *flag);
        } else {
            if (*flag == 2)
                printf("%d ", p->key);
            else if (*flag == 1)
                printf("%d", p->key);
            (*flag)--;
            //  printf("THIS FLAG = %d\n", *flag);
            if (p->right != NULL)
                return Print2Min(p->right, flag);
        }
    }
}

void PrintTree(struct tnode *p, int level) {
    int i;
    if (p != NULL) {
        PrintTree(p->right, level + 1);
        for (i = 0; i < level; i++)
            printf("   ");
        printf("%4d\n", p->key);
        PrintTree(p->left, level + 1);
    }
}

struct tnode *add_tnode(struct tnode *p, int key) {
    if (p == NULL) {
        p = (struct tnode *) malloc(sizeof(struct tnode));
        p->key = key;
        p->left = NULL;
        p->right = NULL;
    } else if (key < p->key) // создаем левую ветку
        p->left = add_tnode(p->left, key);
    else if (key > p->key)
        p->right = add_tnode(p->right, key);
    else; // игнорируем если одинаковые элементы
    return p;
}

void FreeTree(struct tnode *p) {
    if (p->left) FreeTree(p->left);
    if (p->right) FreeTree(p->right);
    free(p);
}