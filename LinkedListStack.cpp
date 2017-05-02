

#include "stdafx.h"
#include <iostream>
#include "CustomTypes.h"
#include "LinkedListStack.h"

using namespace std;

// Default constructor
LinkedListStack::LinkedListStack(void)
{
	top = nullptr;
	bottom = nullptr;
}

// Default destructor
LinkedListStack::~LinkedListStack(void)
{
	cout << "Destroying stack." << endl;
	// DestroyStack();
}

void LinkedListStack::InitializeStack()
{
	// DestroyStack();
}

bool LinkedListStack::IsEmpty()
{
	return top == nullptr;
}

int LinkedListStack::Size()
{

}

void LinkedListStack::Top()
{

}

void LinkedListStack::Push(TreeNode* treeNodePointer)
{

}

void LinkedListStack::Pop(TreeNode* &treeNodePointer)
{
	
}