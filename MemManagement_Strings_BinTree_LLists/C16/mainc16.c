#include <stdio.h>
#include <stdlib.h>

struct tnode{
	int key;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *add_tnode(struct tnode *p, int key)
{
	if(p == NULL)
	{
		p = (struct tnode*) malloc(sizeof(struct tnode));
		p->key = key;
		p->left = NULL;
		p->right = NULL;
	}
	else if(key < p->key)
		p->left = add_tnode(p->left, key);
	else if(key > p->key)
		p->right = add_tnode(p->right, key);
		
	return p;
}

void PrintTree(struct tnode *p, int level)
{
	int i;
	if(p!=NULL)
	{
		PrintTree(p->right, level+1);
		for(i=0; i<level; i++)
			printf("   ");
		printf("%4d\n", p->key);
		PrintTree(p->left, level+1);
	}
}

/*void PrintMin(struct tnode *p)
{
	struct tnode *min = p;
	
	while(p->left->left)
		min = p->left;
	if(min->left->right!=NULL)
		printf("%d %d", min->left->key, min->left->right->key);
	else
		printf("%d %d", min->left->key, min->key);
}
*/
void FreeTree(struct tnode *p)
{
	if(p->left)
		FreeTree(p->left);
	if(p->right)
		FreeTree(p->right);
	free(p);
}

int main()
{
	struct tnode *root = NULL;
	int tkey;
	
	while(scanf("%d", &tkey) != EOF)
		root = add_tnode(root, tkey);
	PrintTree(root, 0);
//	PrintMin(root);
	FreeTree(root);
	return 0;
}
