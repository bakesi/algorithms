#include <cstdio>
#include "../binary-search-tree/bst.cpp"

#define max(a, b) (a > b ? a : b)

using namespace std;

class AVL : public BSTree
{
	int height(const Node *) const;
	void updateHeight(Node *);
	void leftRotate(Node *);
	void rightRotate(Node *);
	void rebalance(Node *);
	void printNode(const Node *) const;
  public:
	void insert(const int key);
	void erase(const int key);
};

int AVL::height(const Node *node) const
{
	if (node)
	{
		return node->height;
	}

	return -1;
}

void AVL::updateHeight(Node *node)
{
	node->height = max(height(node->left), height(node->right)) + 1;
}

void AVL::leftRotate(Node *x)
{
	Node *y = x->right;
	x->right = y->left;
	if (y->left)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (!x->parent)
	{
		_root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}

	y->left = x;
	x->parent = y;
	updateHeight(x);
	updateHeight(y);
}

void AVL::rightRotate(Node *x)
{
	Node *y = x->left;
	x->left = y->right;
	if (y->right)
	{
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (!x->parent)
	{
		_root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}

	y->right = x;
	x->parent = y;
	updateHeight(x);
	updateHeight(y);
}

void AVL::rebalance(Node *node)
{
	while (node)
	{
		updateHeight(node);
		if (height(node->left) >= 2 + height(node->right))
		{
			if (height(node->left->left) >= height(node->left->right))
			{
				rightRotate(node);
			}
			else
			{
				leftRotate(node->left);
				rightRotate(node);
			}
		}
		else if (height(node->right) >= 2 + height(node->left))
		{
			if (height(node->right->right) >= height(node->right->left))
			{
				leftRotate(node);
			}
			else
			{
				rightRotate(node->right);
				leftRotate(node);
			}
		}
		node = node->parent;
	}
}

void AVL::insert(const int key)
{
	Node *node = BSTree::insert(key);
	rebalance(node);
}

void AVL::erase(const int key)
{
	Node *node = BSTree::erase(key);
	rebalance(node);
}

void AVL::printNode(const Node *current) const
{
	if (current)
	{
		if (!current->parent) {
			printf("%d(%d)\n", current->key, current->height);
		} else if (current == current->parent->left) {
			printf("%d(%d).left->%d(%d)\n", current->parent->key, current->parent->height, current->key, current->height);
		} else {
			printf("%d(%d).right->%d(%d)\n", current->parent->key, current->parent->height, current->key, current->height);
		}
		printNode(current->left);
		printNode(current->right);
	}
}
