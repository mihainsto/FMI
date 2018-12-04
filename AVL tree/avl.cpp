#include <iostream>
#include <queue>

struct AVL_treenode
{
	int key;
	int BalanceFactor;
	AVL_treenode *right;
	AVL_treenode *left;
};
AVL_treenode *tree;

int AVL_subtree_height(AVL_treenode *temp, char question);
void AVL_BalanceFactor_update(AVL_treenode *temp, int x);
void AVL_rotate_left(AVL_treenode *prev, AVL_treenode *temp)
{
	int ok = 0;
	AVL_treenode *son = temp->right;
	if (prev != temp && prev->right == temp) prev->right = son;
	if (prev != temp && prev->left == temp) prev->left = son;
	if (prev == temp)ok = 1;
	AVL_treenode *aux = son->left;
	son->left = temp;
	temp->right = aux;
	if (ok == 1)
	{
		tree = son;
	}


}
void AVL_rotate_left(AVL_treenode *temp, int x)
{
	AVL_treenode *prev;
	prev = temp;
	if (temp->key == x)
	{
		AVL_rotate_left(temp, temp);
		AVL_BalanceFactor_update(tree, x);
		return;
	}
	if (temp->key > x) temp = temp->left;
	else
		temp = temp->right;

	while (temp != NULL)
	{
		if (temp->key == x)
		{
			AVL_rotate_left(prev, temp);
			AVL_BalanceFactor_update(tree, x);
			return;
		}

		prev = temp;
		if (temp->key > x) temp = temp->left;
		else
			temp = temp->right;
	}

}
void AVL_rotate_right(AVL_treenode *prev, AVL_treenode *temp)
{
	int ok = 0;
	AVL_treenode *son = temp->left;
	if (prev != temp && prev->right == temp)prev->right = son;
	if (prev != temp && prev->left == temp)prev->left = son;
	if (prev == temp)ok = 1;
	AVL_treenode *aux = son->right;
	son->right = temp;
	temp->left = aux;
	if (ok == 1)
	{
		tree = son;
	}


}
void AVL_rotate_right(AVL_treenode *temp, int x)
{
	AVL_treenode *prev;
	prev = temp;
	if (temp->key == x)
	{
		AVL_rotate_right(temp, temp);
		AVL_BalanceFactor_update(tree, x);
		return;
	}
	if (temp->key > x) temp = temp->left;
	else
		temp = temp->right;

	while (temp != NULL)
	{
		if (temp->key == x)
		{
			AVL_rotate_right(prev, temp);
			AVL_BalanceFactor_update(tree, x);
			return;
		}

		prev = temp;
		if (temp->key > x) temp = temp->left;
		else
			temp = temp->right;
	}

}
int AVL_subtree_height(AVL_treenode *temp, char question)
{
	std::queue<AVL_treenode*> q;

	if (question == 'L') 
	{
		if (temp->left == NULL) return 0;
		q.push(temp->left);
	}
	else 
	{
		if (temp->right == NULL) return 0;
		q.push(temp->right);
	}
	AVL_treenode *aux = NULL;
	while (!q.empty())
	{
		aux = q.front();
		//std::cout << aux->key << " ";
		q.pop();
		if (aux->left != NULL) q.push(aux->left);
		if (aux->right != NULL) q.push(aux->right);
	}
	int x = aux->key, height = 0;

	while (temp != NULL)
	{

		if (temp->key == x) return height;
		if (temp->key > x) temp = temp->left;
		else
			temp = temp->right;
		height++;
	}




}
void AVL_BalanceFactor_update(AVL_treenode *temp, int x)
{
	AVL_treenode *aux = NULL;
	while (temp != NULL)
	{
		
		temp->BalanceFactor = AVL_subtree_height(temp, 'R') - AVL_subtree_height(temp, 'L');
		if (temp->BalanceFactor >= 2 || temp->BalanceFactor <= -2) aux = temp;
		if (temp->key == x)	break;
		if (temp->key > x) temp = temp->left;
		else
			temp = temp->right;
	}
	if (aux == NULL) return;
	if (aux->BalanceFactor <= -2 && aux->left->BalanceFactor > 0) AVL_rotate_left(tree, aux->left->key);
	else
	if (aux->BalanceFactor >= 2 && aux->right->BalanceFactor < 0) AVL_rotate_right(tree, aux->right->key);
	else
	if (aux->BalanceFactor >= 2) AVL_rotate_left(tree, aux->key);
	else
	if (aux->BalanceFactor <= -2) AVL_rotate_right(tree, aux->key);
	return;
}
void AVL_insert(AVL_treenode *&tree, int x)
{
	AVL_treenode *aux = new AVL_treenode;
	aux->key = x;
	aux->right = NULL;
	aux->left = NULL;
	if (tree == NULL)
	{
		tree = aux;
	}
	else
	{
		AVL_treenode *temp = tree;
		while (1)
		{


			if (temp->key > aux->key && temp->left == NULL)
			{
				temp->left = aux;
				AVL_BalanceFactor_update(tree, aux->key);
				break;
			}
			else
				if (temp->key < aux->key && temp->right == NULL)
				{
					temp->right = aux;
					AVL_BalanceFactor_update(tree, aux->key);
					break;
				}
				else
					if (temp->key > aux->key) temp = temp->left;
					else
						temp = temp->right;

		}
	}
}
int AVL_search(AVL_treenode *temp, int x)
{
	while (temp != NULL)
	{
		if (temp->key == x) return 1;
		if (temp->key > x) temp = temp->left;
		else
			temp = temp->right;
	}
	return 0;
}
int AVL_find_max(AVL_treenode *temp)
{
	int x;
	while (temp != NULL)
	{
		x = temp->key;
		temp = temp->right;
	}

	return x;
}
void AVL_delete(AVL_treenode *temp, int x);
void AVL_delete(AVL_treenode *prev, AVL_treenode *temp)
{
	int question;
	if (temp->left != NULL && temp->right != NULL) question = 3; // has 2 children
	else
		if (temp->left == NULL && temp->right == NULL) question = 1; // is leaf 
		else
			if (temp == prev) question = 4; // is first node and has only a child
			else
				if (temp->left == NULL || temp->right == NULL) question = 2; // has only a child

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
		AVL_BalanceFactor_update(tree, prev->key);
		break;
	case 3:
		//minimum right subtree
		AVL_treenode *aux;
		aux = temp;
		int x;
		aux = aux->right;
		while (aux != NULL)
		{
			x = aux->key;
			if (aux->left != NULL) aux = aux->left;
			else
				aux = aux->right;
		}
		AVL_delete(temp, x);
		temp->key = x;
		AVL_BalanceFactor_update(tree, prev->key);
		break;
	case 4:
		if (temp->right != NULL) temp = temp->right;
		else
		{
			temp->key = temp->left->key;
			temp->right = temp->left->right;
			temp->left = temp->left->left;

		}
		break;
	}
}
void AVL_delete(AVL_treenode *temp, int x)
{
	AVL_treenode *prev;
	prev = temp;
	if (temp->key == x)
	{
		AVL_delete(temp, temp);
		return;
	}
	if (temp->key > x) temp = temp->left;
	else
		temp = temp->right;

	while (temp != NULL)
	{
		if (temp->key == x)
		{
			AVL_delete(prev, temp);
			return;
		}

		prev = temp;
		if (temp->key > x) temp = temp->left;
		else
			temp = temp->right;
	}

}//search a value and then calls the deletion function for that pointer
bool AVL_exist(AVL_treenode *temp, int x)
{
	if (temp->right != NULL || temp->left != NULL) return 1;
	return 0;
}//0 - if we have only one node in the tree 
void inorder(AVL_treenode *temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	std::cout << temp->key << " ";
	inorder(temp->right);
}
void preorder(AVL_treenode *temp)
{
	if (!temp)
		return;
	std::cout << temp->key << " ";
	preorder(temp->left);
	preorder(temp->right);


}
void postorder(AVL_treenode *temp)
{
	if (!temp)
		return;
	postorder(temp->left);
	postorder(temp->right);
	std::cout << temp->key << " ";
}
void DFS(AVL_treenode *temp)
{
	std::queue<AVL_treenode*> q;
	q.push(temp);
	while (!q.empty())
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
	
	tree = NULL;

	AVL_insert(tree, 20);
	AVL_insert(tree, 10);
	AVL_insert(tree, 30);
	AVL_insert(tree, 40);
	AVL_insert(tree, 50);
	//inorder(tree);
	//std::cout << "\n";
	//preorder(tree);
	

	//AVL_delete(tree,20);

	//AVL_rotate_left(tree, 30);
	AVL_insert(tree, 45);
	//AVL_rotate_left(tree, 20);
	AVL_insert(tree, 44);
	//AVL_rotate_right(tree, 50);	
	AVL_insert(tree, 55);
	AVL_insert(tree, 54);
	//std::cout << tree->BalanceFactor;
	//DFS(tree);
	inorder(tree);
	system("pause");
	return 0;
}