#include <iostream>
#include <queue>

struct Btreenode
{
	int key;
	Btreenode *right;
	Btreenode *left;
};
void Btree_insert(Btreenode *&tree, int x)
{
	Btreenode *aux = new Btreenode;
	aux->key = x;
	aux->left = NULL;
	aux->right = NULL;
	if(tree == NULL)
	{
		tree = aux;
	}else
	{
		std::queue<Btreenode*> q;
		q.push(tree);
		while(!q.empty())
		{
			Btreenode *temp = q.front();
			q.pop();
			if (temp->left == NULL) 
			{
				temp->left = aux; return;
			}
			else
			if (temp->right == NULL)
			{
				temp->right = aux; return;
			}
			else
			{
				q.push(temp->left);
				q.push(temp->right);
			}
		}
	}
}
void inorder(Btreenode *temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	std::cout << temp->key << " ";
	inorder(temp->right);
}
void preorder(Btreenode *temp)
{
	if (!temp)
		return;
	std::cout << temp->key<< " ";
	preorder(temp->left);
	preorder(temp->right);
	
	
}
void postorder(Btreenode *temp)
{
	if (!temp)
		return;
	postorder(temp->left);
	postorder(temp->right);
	std::cout << temp->key << " ";
}
int main()
{
	Btreenode *tree;
	tree = NULL;
	Btree_insert(tree, 1);
	Btree_insert(tree, 2);
	Btree_insert(tree, 3);
	Btree_insert(tree, 4);
	Btree_insert(tree, 5);
	Btree_insert(tree, 6);

	postorder(tree);
	system("pause");
	return 0;
}