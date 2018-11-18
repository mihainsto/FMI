#include <iostream>
#include <queue>

struct B_search_treenode
{
	int key;
	B_search_treenode *right;
	B_search_treenode *left;
};
void BStree_insert(B_search_treenode *&tree, int x)
{
	B_search_treenode *aux = new B_search_treenode;
	aux->key = x;
	aux->right = NULL;
	aux->left = NULL;
	if(tree == NULL)
	{
		tree = aux;
	}
	else
	{
		B_search_treenode *temp = tree;
		while (1)
		{
			

			if (temp->key > aux->key && temp->left == NULL)
			{
				temp->left = aux; break;
			}
			else
				if (temp->key < aux->key && temp->right == NULL) 
				{
					temp->right = aux; break;
				}

				else
					if (temp->key > aux->key) temp = temp->left;
					else
						temp = temp->right;
						
		}
	}
}
int BStree_search(B_search_treenode *temp, int x)
{
	while(temp != NULL)
	{
		if (temp->key == x) return 1;
		if (temp->key > x) temp = temp->left;
		else
			temp = temp->right;
	}
	return 0;
}
int BStree_find_max(B_search_treenode *temp)
{
	int x;
	while(temp!=NULL)
	{
		x = temp->key;
		temp = temp->right;
	}

	return x;
}
void BStree_delete(B_search_treenode *temp, int x);
void BStree_delete(B_search_treenode *prev, B_search_treenode *temp)
{
	int question;
	if (temp->left == NULL && temp->right == NULL) question = 1;
	else
		if (temp->left == NULL || temp->right == NULL ) question = 2;
			else question = 3;

	switch (question)
	{
	case 1:
		if (prev->right == temp) prev->right = NULL;
		else
			prev->left = NULL;
		free(temp);
		break;
	case 2:
		if (prev->right == temp)
		{
			if (temp->right != NULL) prev->right = temp->right;
			else prev->right = temp->left;

		}
		else
		{
			if (temp->right != NULL) prev->left = temp->right;
			else prev->left = temp->left;

		}
		break;
	case 3:
		//minimum right subtree
		B_search_treenode *aux;
		aux = temp;
		int x;
		aux = aux->right;
		while(aux != NULL)
		{
			x = aux->key;
			if (aux->left != NULL) aux = aux->left;
			else
				aux = aux->right;
		}
		BStree_delete(temp, x); 
		temp->key = x; 
		break;
	}
}
void BStree_delete(B_search_treenode *temp, int x)
{
	B_search_treenode *prev;
	prev = temp;
	if (temp->key == x) BStree_delete(temp, temp);
	if (temp->key > x) temp = temp->left;
	else
		temp = temp->right;
	
	while (temp != NULL)
	{
		if (temp->key == x) 
		{
			BStree_delete(prev, temp);
			return;
		}

		prev = temp;
		if (temp->key > x) temp = temp->left;
		else
			temp = temp->right;
	}
	
}
void inorder(B_search_treenode *temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	std::cout << temp->key << " ";
	inorder(temp->right);
}
void preorder(B_search_treenode *temp)
{
	if (!temp)
		return;
	std::cout << temp->key<< " ";
	preorder(temp->left);
	preorder(temp->right);
	
	
}
void postorder(B_search_treenode *temp)
{
	if (!temp)
		return;
	postorder(temp->left);
	postorder(temp->right);
	std::cout << temp->key << " ";
}
void DFS(B_search_treenode *temp)
{
	std::queue<B_search_treenode*> q;
	q.push(temp);
	while(!q.empty())
	{
		temp = q.front();
		std::cout << temp->key << " ";
		q.pop();
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
	
}
int main()
{
	B_search_treenode *tree;
	tree = NULL;

	BStree_insert(tree, 20);
	BStree_insert(tree, 5);
	BStree_insert(tree, 7);
	BStree_insert(tree, 25);
	BStree_insert(tree, 24);
	BStree_insert(tree, 30);
	BStree_insert(tree, 29);
	//inorder(tree);
	//std::cout << "\n";
	//preorder(tree);
	//std::cout<<find_max(tree);
	BStree_delete(tree,20);
	DFS(tree);
	system("pause");
	return 0;
}