#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
/*
	Removes all the nodes with a given value
	@param node belonging to tree
	@param value to search for
	@return root node
*/
using namespace std;
class Node {
public:
	Node* left;
	Node* right;
	Node* parent;

	Node();
	static  Node* removeNodes(Node* node, int value);
	void addValue(int value);
	const int getValue();
	static Node* findValue(Node* node, int value);
	void displayBFS();
	
public:
	int value;
	char color;
	static Node* findPlace(Node* node, int value);
	static void fixTree(Node*& root, Node* node);
	static void rotateRight(Node*& root, Node*& node);
	static void rotateLeft(Node*& root, Node*& node);
};

void inorderHelper(Node* root)
{
	if (root == NULL)
		return;

	inorderHelper(root->left);
	cout << root->value << "  ";
	inorderHelper(root->right);
}

int main() {

	Node* r = new Node;

	r->addValue(13);
	r->addValue(17);
	r->addValue(8);
	r->addValue(1);
	r->addValue(11);
	r->addValue(15);
	r->addValue(25);
	r->addValue(6);
	r->addValue(22);
	r->addValue(27);
	//Node* aux = r->findValue(r, 3);

	r->displayBFS();
	cout << "\n";
	//inorderHelper(r);
	return 0;
}




Node::Node()
{
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
}

void Node::addValue(int value)
{
	auto& root = this->right;
	
	if (root == NULL) 
	{
		Node* aux = new Node;
		aux->value = value;
		aux->color = 'B';
		root = aux;
	}
	else {
		Node* goodParent = findPlace(root, value);
		Node* aux = new Node;
		aux->value = value;
		aux->color = 'R';
		aux->parent = goodParent;
		if (value < goodParent->value) {
			goodParent->left = aux;
		}
		else {
			goodParent->right = aux;
		}

		if (aux->parent->color == 'R')
		{
			fixTree(root, aux);
			//cout << "I need fixing!";
		}
	}
}

const int Node::getValue()
{
	try {
		if (this == NULL) throw 1;
		return this->value;
	}
	catch (int e) {
		cout << "This node dose not exist";
	}
}

Node* Node::findPlace(Node* node, int value)
{
	Node* aux = node;
	while (1) {
		if (value < aux->value) {
			if (aux->left == NULL)
				return aux;
			aux = aux->left;
		}
		else {
			if (aux->right == NULL)
				return aux;
			aux = aux->right;
		}
	}
}

void Node::fixTree(Node*& root, Node* aux)
{
	//3 parent is red
	while (aux != root && aux->color != 'B' && aux->parent->color == 'R')
	{
		auto parent = aux->parent;
		auto grandParent = aux->parent->parent;

		//Case 1 uncle is right
		if (parent == grandParent->left)
		{
			auto uncle = grandParent->right;
			// if uncle is red ->only recoloring
			if (uncle != NULL && uncle->color == 'R')
			{
				uncle->color = 'B';
				parent->color = 'B';
				grandParent->color = 'R';
				aux = grandParent;
			}
			// uncle black -> need rotations
			else
			{
				if (aux == parent->right)
				{
					rotateLeft(root, parent);
					aux = parent;
					parent = aux->parent;
				}

				rotateRight(root, grandParent);
				swap(parent->color, grandParent->color);
				aux = parent;
			}
		}
		//Case 2 uncle is left
		else
		{
			auto uncle = grandParent->left;
			// if uncle red -> only recoloring

			if (uncle != NULL && uncle->color == 'R')
			{
				parent->color = 'B';
				grandParent->color = 'R';
				uncle->color = 'B';
				aux = grandParent;
			}
			// uncle black -> need rotation
			else
			{
				if (aux == parent->left)
				{
					rotateRight(root, parent);
					aux = parent;
					parent = aux->parent;
				}

				rotateLeft(root, grandParent);
				swap(parent->color, grandParent->color);
				aux = parent;
			}
		}
	}
	root->color = 'B';
}

void Node::rotateRight(Node*& root, Node*& node)
{
	Node* childLeft = node->left;

	node->left = childLeft->right;

	if (node->left != NULL)
		node->left->parent = node;

	childLeft->parent = node->parent;

	if (node->parent == NULL)
		root = childLeft;

	else if (node == node->parent->left)
		node->parent->left = childLeft;

	else
		node->parent->right = childLeft;

	childLeft->right = node;
	node->parent = childLeft;
}

void Node::rotateLeft(Node*& root, Node*& node)
{
	Node* childRight = node->right;

	node->right = childRight->left;

	if (node->right != NULL)
		node->right->parent = node;

	childRight->parent = node->parent;

	if (node->parent == NULL)
		root = childRight;

	else if (node == node->parent->left)
		node->parent->left = childRight;

	else
		node->parent->right = childRight;

	childRight->left = node;
	node->parent = childRight;
}


Node* Node::findValue(Node* node, int value)
{
	Node* aux = node;
	while (1) {
		if (value == aux->value)
			return aux;
		if (aux->left == NULL && aux->right == NULL)
			return NULL;
		if (value < aux->value) {
			aux = aux->left;
		}
		else {
			aux = aux->right;
		}
	}
}

void Node::displayBFS()
{
	Node* aux = this;
	map<Node*, int> vis;
	queue<Node*> q;
	q.push(this);

	while (!q.empty())
	{
		auto thisNode = q.front();
		q.pop();
		if (vis.find(thisNode) != vis.end())
			continue;

		vis[thisNode] = 1;
		cout << "(" << thisNode->value << "," << thisNode->color << ") ";

		if (thisNode->left != NULL)
			q.push(thisNode->left);
		if (thisNode->right != NULL)
			q.push(thisNode->right);

	}

}
