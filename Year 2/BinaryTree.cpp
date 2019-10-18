#include <iostream>
using namespace std;

class Node
{
public:
	Node* left;
	Node* right;
	Node* parent;
	
	Node();
	~Node();
	static Node* removeNodes(Node* node, int value);
	static void addValue(Node* root,  int value);
	const static void inorder(const Node* node);
private:
	static Node* minValueNode(Node* node);
	static void removeValue(Node* node, int value);
	static void removeNode(Node* node);
	static Node* findValue(Node* node, int value);
	int value;
};



Node::Node()
{
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

Node::~Node()
{
	if(this->right != NULL)
		delete(this->right);
	if (this->left != NULL)
		delete(this->left);
}

Node* Node::removeNodes(Node* node, int value)
{
	auto delNode = findValue(node, value);
	while(delNode != NULL)
	{
		node->removeNode(delNode);
		delNode = findValue(node, value);
	}
	return node;
}

void Node::addValue(Node* root, int value)
{
	Node* aux = new Node;
	aux->value = value;
	
	if (root->right == NULL)
	{
		root->right = aux;
		aux->parent = root;	
	}
	else
	{
		auto currentNode = root->right;
		while(1)
		{
			if(value > currentNode->value)
			{
				if (currentNode->right != NULL)
				{
					currentNode = currentNode->right;
					continue;
				}
				else
				{
					currentNode->right = aux;
					aux->parent = currentNode;
					return;
				}
			}
			else
			{
				if (currentNode->left != NULL)
				{
					currentNode = currentNode->left;
					continue;
				}
				else
				{
					currentNode->left = aux;
					aux->parent = currentNode;
					return;
				}
			}
		}
	}
}

Node* Node::findValue(Node* node, int value)
{
	auto currentNode = node;

	if (currentNode->parent == NULL)
		currentNode = currentNode->right;
	while(1)
	{
		if (currentNode == NULL)
			return NULL;
		if(value == currentNode->value)
		{
			return currentNode;
		}
		else
		{
			if (currentNode->right == NULL && currentNode->left == NULL)
				return NULL;
			if (value > currentNode->value)
			{
				currentNode = currentNode->right;
			}
			else
			{
				currentNode = currentNode->left;
			}
		}
		
		
	}
}

void Node::removeNode(Node* node)
{
	//auto delNode = findValue(node, value);
	auto delNode = node;
	auto delParent = delNode->parent;

	
	
	if(delParent->left == delNode)
	{
		// case is leaf
		if(delNode->left == NULL && delNode->right == NULL)
		{
			delParent->left = NULL;

		}
		else // not leaf
		{
			// case has only one child

			if(delNode->right == NULL && delNode->left != NULL)
			{
				delParent->left = delNode->left;
				delNode->left->parent = delParent;

				delNode->parent = NULL;
				delNode->left = NULL;
				delNode->right = NULL;
				delete(delNode);
			}
			else
			if(delNode->right != NULL && delNode->left == NULL)
			{
				delParent->left = delNode->right;
				delNode->right->parent = delParent;
				
				delNode->parent = NULL;
				delNode->left = NULL;
				delNode->right = NULL;
				delete(delNode);
			}
			else // case has two children
			{
				auto succesor = minValueNode(delNode->right);
				delNode->value = succesor->value;
				removeNode(succesor);
				
				
			}
			
		}
	}
	else
	{
		// case is leaf
		if (delNode->left == NULL && delNode->right == NULL)
		{
			delParent->right = NULL;

		}
		else // not leaf
		{
			// case has only one child

			if (delNode->right == NULL && delNode->left != NULL)
			{
				delParent->right = delNode->left;
				delNode->left->parent = delParent;
				
				delNode->parent = NULL;
				delNode->left = NULL;
				delNode->right = NULL;
			}
			else
				if (delNode->right != NULL && delNode->left == NULL)
				{
					delParent->right = delNode->right;
					delNode->right->parent = delParent;
					
					delNode->parent = NULL;
					delNode->left = NULL;
					delNode->right = NULL;
				}
				else // case has two children
				{
					auto succesor = minValueNode(delNode->right);
					delNode->value = succesor->value;
					removeNode(succesor);


				}

		}
	}
	
}

void Node::removeValue(Node* node, int value)
{
	auto delNode = findValue(node, value);
	removeNode(delNode);
}

Node* Node::minValueNode(Node* node)
{
	 Node* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}


const void Node::inorder(const Node* node)
{
	if (node != NULL)
	{
		inorder(node->left);
		cout << node->value<<" ";
		inorder(node->right);
	}
}

int main()
{

	Node* root = new Node;
	root->addValue(root,50);
	root->addValue(root, 80);
	root->addValue(root, 30);
	root->addValue(root, 30);
	root->addValue(root, 30);
	root->addValue(root, 80);
	root->addValue(root, 20);
	root->addValue(root, 40);
	root->addValue(root, 70);
	root->addValue(root, 70);
	root->addValue(root, 70);
	root->addValue(root, 60);
	root->addValue(root, 80);
	root->addValue(root, 80);

	root->inorder(root->right);
	cout << "\n";
	root->removeNodes(root, 30);
	root->removeNodes(root, 80);
	root->removeNodes(root, 70);
	root->inorder(root->right);
	cout << "\n";


	delete (root);
	return 0;
}
