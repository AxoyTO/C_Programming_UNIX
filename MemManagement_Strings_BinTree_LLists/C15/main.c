#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int key;
    struct tnode *left;
    struct tnode *right;
};

int searchTree(struct tnode *p, int num);

struct tnode *addNode(struct tnode *p, int key);

void freeTree(struct tnode *p);

int main(int argc, char **argv) {
    struct tnode *root = NULL;
    int tkey, num;
	
    if(argc < 2)
    {
	printf("NO\n");
    	return 2;
    }

    num = atoi(argv[1]);
    if(!num)
        return -1;

    while (scanf("%d", &tkey) != EOF)
        root = addNode(root, tkey);

    if (searchTree(root, num))
        printf("YES");
    else
        printf("NO");
    if (root != NULL)
        freeTree(root);
    return 0;
}

struct tnode *addNode(struct tnode *p, int key) {
    if (p == NULL) {
        p = (struct tnode *) malloc(
                sizeof(struct tnode));        //Valgrind сильно ругает когда 1*sizeof, ошибка "invalid write of size 8", я думал, что из-за того, что мы сразу не выделяем память и для соседних узлей.
        p->key = key;                                                    //Когда 3*sizeof, не ругает, если неправильно, исправлю
        p->right = NULL;
        p->left = NULL;
    } else if (key < p->key)
        p->left = addNode(p->left, key);
    else if (key > p->key)
        p->right = addNode(p->right, key);

    return p;
}

int searchTree(struct tnode *p, int num) {
    if (p == NULL)
        return 0;
    else if (p->key == num)
        return 1;
    else if (num > p->key)
        return searchTree(p->right, num);
    else if (num < p->key)
        return searchTree(p->left, num);

    return 0;
}

void freeTree(struct tnode *p) {
    {
        if (p->right)
            freeTree(p->right);
        if (p->left)
            freeTree(p->left);
        free(p);
    }
}
