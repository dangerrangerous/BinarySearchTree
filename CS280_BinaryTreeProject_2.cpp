// CS280_BinaryTreeProject_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CustomTypes.h"
#include "BinaryTree.h"
#include "Queue.h"
#include "LinkedListStack.h"
#include "Menu.h"
#include <iostream>

using namespace std;

int main()
{
	BinaryTree integerTree;
	Queue q;
	LinkedListStack shtack;
	Menu menu;

	q.InitializeQueue();
	shtack.InitializeStack();
	integerTree.InitializeTree();
	
	do
	{
		menu.Display();
		menu.QueryUser();
		menu.ProcessCommand(integerTree);
	} while (menu.Continue());

	/*
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

	cout << endl << endl;

	cout << "Iterative in order traversal:" << endl;
	integerTree.IterativeInOrderTraversal();

	cout << endl << endl;

	cout << "Iterative pre order traversal:" << endl;
	integerTree.IterativePreOrderTraversal();

	cout << endl << endl;

	cout << "Iterative post order traversal:" << endl;
	integerTree.IterativePostOrderTraversal();

	cout << endl << endl;

	cout << "Tree height:" << endl;
	cout <<	integerTree.TreeHeight() << endl;

	cout << "Node count:" << endl;
	cout << integerTree.TreeNodeCount() << endl;

	cout << "Leaf count: " << endl;
	cout << integerTree.TreeLeafCount() << endl;

	cout << "Search tree: " << endl;
	cout << integerTree.SearchTree(42) << endl;
	
	cout << "Delete node: " << endl;
	integerTree.DeleteItem(34);

	cout << "Iterative in order traversal." << endl;
	integerTree.IterativeInOrderTraversal();
	// integerTree.DeleteItem(60);
	*/

	integerTree.DestroyTree();

    return 0;
}

