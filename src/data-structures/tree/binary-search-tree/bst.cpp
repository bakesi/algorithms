#include <cstdio>

#define ERR_NOT_FOUND -1

using namespace std;

struct Node
{
	Node() { printf("node contructor\n"); }
	Node(const int k):key(k) { printf("node contructor: %d\n", k); }
	~Node() { printf("node destructor: %d\n", key); }
	Node *parent = nullptr;
	Node *left = nullptr;
	Node *right = nullptr;
	int key = 0;
	int height = -1;
};

class BSTree
{
	void virtual printNode(const Node *current) const;
	void transplant(Node *toDelete, Node *toInsert);
	Node * searchNode(const int key) const;
  public:
	Node *_root;
	BSTree() : _root(nullptr) {};
	void print() const;
	Node * insert(const int key);
	Node * erase(const int key);
	int search(const int key) const;
	int getMin(Node * node) const;
	int getMax(Node * node) const;
	int getSuccessor(const int key) const;
	int getPredecessor(const int key) const;
};

void BSTree::printNode(const Node *current) const
{
	if (current)
	{
		printNode(current->left);
		printf("%d ", current->key);
		printNode(current->right);
	}
}

void BSTree::transplant(Node *toDelete, Node *toInsert)
{
	if (!toDelete->parent)
	{
		_root = toInsert;
	} else if(toDelete == toDelete->parent->left)
	{
		toDelete->parent->left = toInsert;
	} else {
		toDelete->parent->right = toInsert;
	}

	if (toInsert) {
		toInsert->parent = toDelete->parent;
	}
}

Node * BSTree::searchNode(const int key) const
{
	Node *node = _root;
	while (node && key != node->key)
	{
		if (key < node->key)
		{
			node = node->left;
		}
		else
		{
			node = node->right;
		}
	}

	return node;
}

void BSTree::print() const
{
	printNode(_root);
	printf("\n");
}

Node * BSTree::insert(const int key)
{
	Node *node = new Node(key);
	if (_root == nullptr)
	{
		_root = node; // Tree is empty
		return node;
	}

	Node *parent = nullptr;
	Node *current = _root;
	while (current)
	{
		parent = current;
		if (node->key < current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	node->parent = parent;
	if (node->key < parent->key)
	{
		parent->left = node;
	}
	else
	{
		parent->right = node;
	}

	return node;
}

Node * BSTree::erase(const int key)
{
	Node *node = searchNode(key);
	if (!node) return node;

	Node *parent = node->parent;

	if (!node->left) {
		transplant(node, node->right);
	} else if (!node->right) {
		transplant(node, node->left);
	} else {
		Node *successor = searchNode(getMin(node->right));
		if (successor) {
			if (successor->parent != node) {
				transplant(successor, successor->right);
				successor->right = node->right;
				successor->right->parent = successor;
			}

			transplant(node, successor);
			successor->left = node->left;
			successor->left->parent = successor;
		}
	}

	delete node;
	return parent;
}

int BSTree::search(const int key) const
{
	Node *node = searchNode(key);
	if (node)
	{
		return node->key;
	}
	return ERR_NOT_FOUND;
}

int BSTree::getMin(Node * node = nullptr) const
{
	Node * current = node ? node : _root;
	while (current && current->left) {
		current = current->left;
	}

	if (current) {
		return current->key;
	}
	return ERR_NOT_FOUND;
}

int BSTree::getMax(Node * node = nullptr) const
{
	Node * current = node ? node : _root;
	while (current && current->right) {
		current = current->right;
	}

	if (current) {
		return current->key;
	}
	return ERR_NOT_FOUND;
}

int BSTree::getSuccessor(const int key) const
{
	Node *current = searchNode(key);
	if (!current)
	{
		return ERR_NOT_FOUND;
	}

	if (current->right)
	{
		return getMin(current->right);
	}

	Node *parent = current->parent;
	while(parent && current == parent->right) {
		current = parent;
		parent = parent->parent;
	}
	
	if (parent) {
		return parent->key;
	}

	return ERR_NOT_FOUND;
}

int BSTree::getPredecessor(const int key) const
{
	Node *current = searchNode(key);
	if (!current)
	{
		return ERR_NOT_FOUND;
	}

	if (current->left)
	{
		return getMax(current->left);
	}

	Node *parent = current->parent;
	while(parent && current == parent->left) {
		current = parent;
		parent = parent->parent;
	}
	
	if (parent) {
		return parent->key;
	}

	return ERR_NOT_FOUND;
}
