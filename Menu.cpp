#pragma once
// Menu implementation file
// Brian Keppinger

#include "stdafx.h"
#include "CustomTypes.h"
#include "Menu.h"
#include "BinaryTree.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Menu::Menu(void)
{
	userMenuSelection = Quit;
}

// Default destructor
Menu::~Menu(void)
{
	cout << "Destroying Menu." << endl;
}

// Getter
MenuChoices Menu::Get()
{
	return userMenuSelection;
}

// Setter
void Menu::Set(MenuChoices newValue)
{
	userMenuSelection = newValue;
}

void Menu::Display()
{
	cout << endl;
	cout << left << setw(10) << "1: Quit" << endl;
	cout << left << setw(32) << "2: Insert" << left << setw(32) << "6: IterativePostOrder"
			<< left << setw(32) << "9: Delete" << endl;

	cout << left << setw(32) << "3: BreadthFirst" << left << setw(32) << "7: Height"
			<< left << setw(32) << "10: LeafCount" << endl;

	cout << left << setw(32) << "4: IterativeInOrder" << left << setw(32) << "8: Find"
		<< left << setw(32) << "11: NodeCount" << endl;

	cout << left << setw(32) << "5: IterativePreOrder" << endl << endl;
}

void Menu::QueryUser()
{
	int selection;

	cout << "Please enter menu selection." << endl;

	cin >> selection;

	switch (selection)
	{
	case 1: userMenuSelection = Quit;
		break;
	case 2: userMenuSelection = Insert;
		break;
	case 3: userMenuSelection = BreadthFirst;
		break;
	case 4: userMenuSelection = IterativeInOrder;
		break;
	case 5: userMenuSelection = IterativePreOrder;
		break;
	case 6: userMenuSelection = IterativePostOrder;
		break;
	case 7: userMenuSelection = Height;
		break;
	case 8: userMenuSelection = Find;
		break;
	case 9: userMenuSelection = Delete;
		break;
	case 10: userMenuSelection = LeafCount;
		break;
	case 11: userMenuSelection = NodeCount;
		break;

	default: userMenuSelection = Quit;
	} // end switch
	cout << endl;
} // end QueryUser()

bool Menu::Continue()
{
	return userMenuSelection != Quit;
}

void Menu::ProcessCommand(BinaryTree& binaryTree)
{
	int key;

	if (userMenuSelection != Quit)
	{

		switch (userMenuSelection)
		{
		case Insert: 
			cout << "Please enter a value to be inserted into the tree." << endl;
			cin >> key;
			binaryTree.Insert(key);
			cout << endl;
			break;

		case BreadthFirst: 
			cout << "Performing BreadthFirst (Level Order) Traversal." << endl;
			binaryTree.BreadthFirstTraversal();
			cout << endl;
			break;

		case IterativeInOrder:
			cout << "Performing Iterative In Order Traversal." << endl;
			binaryTree.IterativeInOrderTraversal();
			break;

		case IterativePreOrder:
			cout << "Performing Iterative Pre Order Traversal." << endl;
			binaryTree.IterativePreOrderTraversal();
			break;

		case IterativePostOrder:
			cout << "Performing Iterative Post Order Traversal." << endl;
			binaryTree.IterativePostOrderTraversal();
			cout << endl;
			break;

		case Delete:
			cout << "Please enter a key value to be deleted." << endl;
			cin >> key;
			binaryTree.DeleteItem(key);
			cout << endl;
			break;
	
		case Height:
			cout << "Assessing the height of the tree:" << endl;
			cout << "The tree is " << binaryTree.TreeHeight() << " levels tall." << endl;
			cout << endl;
			break;

		case Find:
			cout << "Please enter the key value you are searching for." << endl;
			cin >> key;
			binaryTree.SearchTree(key);
			cout << endl;
			break;
	
		case LeafCount:
			cout << "Counting leaves." << endl;
			cout << "There are " << binaryTree.TreeLeafCount() << " leaves." << endl;
			cout << endl;
			break;

		case NodeCount:
			cout << "Counting the number of nodes." << endl;
			cout << "There are " << binaryTree.TreeNodeCount() << " nodes." << endl;
			cout << endl;
			break;
		}
	}

}
