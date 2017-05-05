#pragma once

#include "stdafx.h"
#include "CustomTypes.h"
#include "Menu.h"
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
			<< left << setw(32) << "7: Delete" << endl;

	cout << left << setw(32) << "3: BreadthFirst" << left << setw(32) << "8: Height"
			<< left << setw(32) << "9: LeafCount" << endl;

	cout << left << setw(32) << "4: IterativeInOrder" << left << setw(32) << "10: Find"
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
	case 7: userMenuSelection = Delete;
		break;
	case 8: userMenuSelection = Height;
		break;
	case 9: userMenuSelection = Find;
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
