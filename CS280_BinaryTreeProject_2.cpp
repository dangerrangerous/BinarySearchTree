// CS280_BinaryTreeProject_2.cpp : Defines the entry point for the console application.
// Brian Keppinger

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
	
	// User menu do while loop
	do
	{
		menu.Display();
		menu.QueryUser();
		menu.ProcessCommand(integerTree);
	} while (menu.Continue());

	// Cleanup
	integerTree.DestroyTree();

    return 0;
}

