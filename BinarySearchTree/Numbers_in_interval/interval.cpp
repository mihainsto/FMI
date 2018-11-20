#include <iostream>
#include "BST.h"
int main()
{
	B_search_treenode *tree;
	BStree_initialize(tree);

	int n,x;
	std::cin >> n;
	for(int i=1;i<=n;i++)
	{
		std::cin >> x;
		BStree_insert(tree,x);
	}
	int a, b;
	std::cin >> a;
	std::cin >> b;
	for(int i=a;i<=b;i++)
	{
		if (BStree_search(tree, i)) std::cout << i << " ";
	}

	system("pause");
	return 0;
}