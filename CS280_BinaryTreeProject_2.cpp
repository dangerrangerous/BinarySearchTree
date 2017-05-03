// CS280_BinaryTreeProject_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CustomTypes.h"
#include "BinaryTree.h"
#include "Queue.h"
#include "LinkedListStack.h"
#include <iostream>

using namespace std;

int main()
{
	BinaryTree integerTree;
	Queue q;
	LinkedListStack shtack;

	q.InitializeQueue();
	shtack.InitializeStack();
	integerTree.InitializeTree();

	integerTree.Insert(20);
	integerTree.Insert(5);
	integerTree.Insert(7);
	integerTree.Insert(34);
	integerTree.Insert(60);
	integerTree.Insert(24);
	integerTree.Insert(42);
	
	cout << endl;
	cout << "Breadth first traversal (level order traversal):" << endl;
	integerTree.BreadthFirstTraversal();

	cout << endl;

	cout << "attempting in order traversal.." << endl;
	integerTree.IterativeInOrderTraversal();

    return 0;
}

