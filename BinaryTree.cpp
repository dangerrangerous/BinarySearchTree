// BinaryTree class implementation
// Brian Keppinger

#include "stdafx.h"
#include <iostream>
#include "CustomTypes.h"
#include "BinaryTree.h"
#include "Queue.h"
#include "LinkedListStack.h"

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

void BinaryTree::BreadthFirst(TreeNode* rootPointer)
{
	if (IsEmpty())
		return;
		
	Queue q;
	TreeNode* treeNodePointer = nullptr;

	if (rootPointer != NULL)
	{
		q.AddToQueue(rootPointer);

		while (!q.IsEmpty())
		{
			q.RemoveFront(treeNodePointer);
			// could do something like treeNodePointer = q.Front().
			cout << treeNodePointer->nodeData << " ";
			
			if (treeNodePointer->leftChild != NULL)
			{
				q.AddToQueue(treeNodePointer->leftChild);
			}
			if (treeNodePointer->rightChild != NULL)
			{
				q.AddToQueue(treeNodePointer->rightChild);
			}
		} // end while
	} // end if

} // end BreadthFirst()

bool BinaryTree::IsEmpty()
{
	return (root == NULL);
}

void BinaryTree::IterativeInOrderTraversal()
{
	IterativeInOrder(root);
}

void BinaryTree::IterativeInOrder(TreeNode* rootPointer)
{
	TreeNode* current = rootPointer;
	LinkedListStack shtack;

	bool iterate = true;
	
	shtack.Push(current);
	
	cout << "Iterative In Order Traversal with Stack." << endl;
	while (iterate)
	{
		while (current != nullptr)
		{
			current = current->leftChild;
			if (current != nullptr)
			{
				shtack.Push(current);
			}
		} // end while

		if (current == nullptr)
		{
			// fix Pop()
			current = shtack.Top()->sTreeNodePointer;
			shtack.Pop();

			cout << current->nodeData << " ";
			current = current->rightChild;
			
			if (current != nullptr)
			{
				shtack.Push(current);
			}
		} // end if

		if (shtack.IsEmpty())
		{
			iterate = false;
		}
	} // end while iterate
} // end Iterative In Order Traversal

void BinaryTree::IterativePreOrderTraversal()
{
	IterativePreOrder(root);
}

void BinaryTree::IterativePreOrder(TreeNode* rootPointer)
{
	TreeNode* current = rootPointer;
	LinkedListStack shtack;

	shtack.Push(current);

	while (!shtack.IsEmpty())
	{
		current = shtack.Top()->sTreeNodePointer;
		cout << current->nodeData << " ";

		if (current->rightChild != nullptr)
		{
			shtack.Push(current->rightChild);
		}
		
		if (current->leftChild != nullptr)
		{
			shtack.Push(current->leftChild);
		}
	}
}