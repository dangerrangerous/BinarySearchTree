
#include "stdafx.h"
#include <iostream>
#include "BinaryTree.h"
#include "CustomTypes.h"


using namespace std;

// Default constructor
BinaryTree::BinaryTree(void)
{
	root = NULL;
}

// Default destructor
BinaryTree::BinaryTree(void)
{
	cout << "Destroying binary tree" << endl;
	// Destroy();
}

void BinaryTree::InitializeTree()
{
	// Destroy(root)
}

void BinaryTree::Insert(int keyValue)
{

}

void BinaryTree::BreadthFirstTraversal()
{

}

bool BinaryTree::isEmpty()
{
	return (root == NULL);
}