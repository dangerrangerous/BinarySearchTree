// BinaryTree class implementation
// Brian Keppinger

#include "stdafx.h"
#include <iostream>
#include "CustomTypes.h"
#include "BinaryTree.h"


using namespace std;


// Default constructor
BinaryTree::BinaryTree(void)
{
	root = NULL;
}

// Default destructor
BinaryTree::~BinaryTree(void)
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
	TreeNode* newNode;
	TreeNode* current;
	TreeNode* previous;

	newNode = new TreeNode;
	newNode->nodeData = keyValue;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;

	bool iterate = true;

	if (IsEmpty())
		root = newNode;
	else
	{
		current = root;

		while (root != NULL && iterate)
		{
			previous = current;

			if (newNode->nodeData == root->nodeData)
			{
				cout << "newNodes keyValue is the same as root" << endl;
				cout << "duplicates are not allowed." << endl;
				iterate = false;
			}
			// go left?
			if (newNode->nodeData < previous->nodeData)
			{
				current = current->leftChild;
				// using nullptr instead of NULL, as NULL is essentially 0 and
				// can cause problems when working with ints and functions.
				// nullptr is a type.	
				// If end of the line.
				if (current == nullptr)
				{
					previous->leftChild = newNode;
					iterate = false;
				}
			}
			// Go right.
			else
			{
				current = current->rightChild;
				if (current == nullptr)
				{
					previous->rightChild = newNode;
					iterate = false;
				}
			}
		} // end while
	} // end else
} // end Insert()

void BinaryTree::BreadthFirstTraversal()
{
	BreadthFirst(root);
}

void BinaryTree::BreadthFirst(TreeNode* nodePointer)
{
	// do the things

}

bool BinaryTree::IsEmpty()
{
	return (root == NULL);
}

