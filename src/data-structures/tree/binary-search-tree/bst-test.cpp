#include <cstdio>
#include <vector>
#include "bst.cpp"

using namespace std;

int main()
{
	BSTree tree;
	tree.insert(2);
	tree.insert(5);
	tree.insert(4);
	tree.insert(1);
	tree.insert(3);
	tree.insert(6);
	int n = 5;

	tree.print();
	printf("found: %d\n", tree.search(n));
	printf("min: %d\n", tree.getMin());
	printf("max: %d\n", tree.getMax());

	printf("\n");

	printf("successor of %d: %d\n", n, tree.getSuccessor(n));
	printf("predecessor of %d: %d\n", n, tree.getPredecessor(n));
	printf("erase %d\n", n);
	tree.erase(n);
	tree.print();

	printf("\n");

	printf("insert %d\n", n);
	tree.insert(n);
	tree.print();
	printf("successor of %d: %d\n", n, tree.getSuccessor(n));
	printf("predecessor of %d: %d\n", n, tree.getPredecessor(n));
	return 0;
}

