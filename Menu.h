#pragma once
#include <string>
#include "stdafx.h"
#include "CustomTypes.h"
#include "BinaryTree.h"

using namespace std;

class Menu
{
public:
	// Default constructor
	Menu(void);
	// Default destructor
	~Menu(void);

	// Accessor
	MenuChoices Menu::Get();

	// Mutator
	void Menu::Set(MenuChoices);
	void Menu::Display();
	void Menu::QueryUser();
	bool Menu::Continue();
	void Menu::ProcessCommand(BinaryTree&);

private:

	MenuChoices userMenuSelection;

};
