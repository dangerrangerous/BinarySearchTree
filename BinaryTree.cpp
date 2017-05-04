// BinaryTree class implementation
// Brian Keppinger

#include "stdafx.h"
#include <iostream>
#include "CustomTypes.h"
#include "BinaryTree.h"
#include "Queue.h"
#include "LinkedListStack.h"
#include <algorithm>

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
	
	// cout << "Iterative In Order Traversal with Stack." << endl;
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
		shtack.Pop();

		if (current->rightChild != nullptr)
		{
			shtack.Push(current->rightChild);
		}
		
		if (current->leftChild != nullptr)
		{
			shtack.Push(current->leftChild);
		}
	} // end while
} // end Iterative PreOrder()

void BinaryTree::IterativePostOrderTraversal()
{
	IterativePostOrder(root);
}

void BinaryTree::IterativePostOrder(TreeNode* rootPointer)
{
	TreeNode* current = rootPointer;
	LinkedListStack stackOne;
	LinkedListStack stackTwo;

	stackOne.Push(current);
	
	while (!stackOne.IsEmpty())
	{
		current = stackOne.Top()->sTreeNodePointer;
		stackTwo.Push(current);
		stackOne.Pop();
		
		if (current->leftChild != nullptr)
		{
			stackOne.Push(current->leftChild);
		}

		if (current->rightChild != nullptr)
		{
			stackOne.Push(current->rightChild);
		}
	}
	
	stackTwo.PrintStack();
}

// Searches tree for key value, returns true and node data if found,
// false otherwise. I would prefer that it returned the node and not
// just the node data so that it can be used by the delete function.
int BinaryTree::SearchTree(int key)
{
	return IsInTree(root, key);
}

int BinaryTree::IsInTree(TreeNode* rootPointer, int key)
{
	TreeNode* treeNode = rootPointer;

	if (treeNode == nullptr)
	{
		return false;
	}
	else
	{
		if (key == treeNode->nodeData)
		{
			return true, treeNode->nodeData;
		}
		else if (key > treeNode->nodeData)
		{
			IsInTree(treeNode->rightChild, key);
		}
		else if (key < treeNode->nodeData)
		{
			IsInTree(treeNode->leftChild, key);

		}
	}
}

void BinaryTree::DeleteItem(int key)
{
	Delete(root, key);
}
// Delete the item from the tree if it exists.
// would be nice to be able to use the search function
TreeNode* BinaryTree::Delete(TreeNode* rootPointer, int key)
{
	TreeNode* current = rootPointer;
	TreeNode* previous = current;

	if (rootPointer == nullptr) return rootPointer;
	// Search for the node, iterative - not implemented
	/*
	while (current->nodeData != key)
	{
		
		if (key < current->nodeData)
		{
			previous = current;
			current = current->leftChild;
		}
		else
		{
			previous = current;
			current = current->rightChild;
		}
	}

	// found node to delete
	// if node has no children, delete it
	if (current->leftChild == nullptr && current->rightChild == nullptr)
	{
		// double check if tree is empty.
		if (current == rootPointer)
		{
			root = nullptr;
		}
		else if(current == previous->leftChild)
		{
			// disconnect previous node
			previous->leftChild = nullptr;
			delete current;
		}
		else
		{
			previous->rightChild = nullptr;
			delete current;
		}
	} // end if 
	// Delete node with one child
	else if (current->rightChild == nullptr)
	{
		if (current == rootPointer)
		{
			rootPointer = current->leftChild;
			delete current;
		}
		else if (current = previous->leftChild)
		{
			previous->leftChild = current->leftChild;
			delete current;
		}
		else
		{
			previous->rightChild = current->rightChild;
			delete current;
		}


	} // end else if
	*/
	// if key is smaller than node
	if (key < current->nodeData)
	{
		current->leftChild = Delete(current->leftChild, key);
	}
	// if key is larger than node
	if (key > current->nodeData)
	{
		current->rightChild = Delete(current->rightChild, key);
	}
	// if key is the same as node
	else
	{
		// if one child or no child
		if (current->leftChild == nullptr)
		{
			TreeNode* temp = current->rightChild;
			delete current;
			return temp;
		}
		else if (current->rightChild == nullptr)
		{
			TreeNode* temp = current->leftChild;
			delete current;
			return temp;
		}

		// Node with two children:
		// Find the successor node to replace the deleted node
		TreeNode* temp = FindMin(current->rightChild);

		current->nodeData = temp->nodeData;

		current->rightChild = Delete(current->rightChild, key);
	}

	return current;
}

TreeNode* BinaryTree::FindMin(TreeNode* rootPointer)
{
	TreeNode* current = rootPointer;
	while (current->leftChild != nullptr)
	{
		current = current->leftChild;
	}

	return current;
}

/*
int BinaryTree::Max(int argument1, int argument2)
{
	if (argument1 >= argument1)
	{
		return argument1;
	}
	else
	{
		return argument2;
	}
}
*/
int BinaryTree::TreeHeight()
{
	return Height(root);
}

int BinaryTree::Height(TreeNode* rootPointer)
{
	if (rootPointer == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + max(Height(rootPointer->leftChild), 
						Height(rootPointer->rightChild));
	}
}

int BinaryTree::TreeNodeCount()
{
	return NodeCount(root);
}

int BinaryTree::NodeCount(TreeNode* rootPointer)
{
	if (rootPointer == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + (NodeCount(rootPointer->leftChild) + 
					NodeCount(rootPointer->rightChild));
	}
}

int BinaryTree::TreeLeafCount()
{
	return LeafCount(root);
}

int BinaryTree::LeafCount(TreeNode* rootPointer)
{
	int numberOfLeaves = 0;
	if (rootPointer->leftChild != nullptr)
	{
		numberOfLeaves += LeafCount(rootPointer->leftChild);
	}
	if (rootPointer->leftChild == nullptr && rootPointer->rightChild == nullptr)
	{
		numberOfLeaves += 1;
	}
	if (rootPointer->rightChild != nullptr)
	{
		numberOfLeaves += LeafCount(rootPointer->rightChild);
	}

	return numberOfLeaves;
} // end LeafCount()