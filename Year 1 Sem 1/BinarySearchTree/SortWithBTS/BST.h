#pragma once
struct B_search_treenode
{
	int key;
	B_search_treenode *right;
	B_search_treenode *left;
};
void BStree_initialize(B_search_treenode *&tree);
void BStree_insert(B_search_treenode *&tree, int x);
int BStree_search(B_search_treenode *temp, int x);
int BStree_find_max(B_search_treenode *temp);
int BStree_find_min(B_search_treenode *temp);
void BStree_delete(B_search_treenode *temp, int x);
void BStree_delete(B_search_treenode *prev, B_search_treenode *temp);
bool BStree_exist(B_search_treenode *temp);
void inorder(B_search_treenode *temp);
void preorder(B_search_treenode *temp);
void postorder(B_search_treenode *temp);
void DFS(B_search_treenode *temp);