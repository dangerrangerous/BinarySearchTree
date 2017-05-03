
// TODO: some functions need to be changed from void...

#include "stdafx.h"
#include <iostream>
#include "CustomTypes.h"
#include "LinkedListStack.h"

using namespace std;

int stackSize = 0;

// Default constructor
LinkedListStack::LinkedListStack(void)
{
	top = nullptr;
	bottom = nullptr;
	stackSize = 0;
}

// Default destructor
LinkedListStack::~LinkedListStack(void)
{
	cout << "Destroying stack." << endl;
	DestroyStack();
}

void LinkedListStack::InitializeStack()
{
	DestroyStack();
}

bool LinkedListStack::IsEmpty()
{
	return top == nullptr;
}

// Return number of elements in stack
// Since it doesn't actually traverse the stack it potentially incorrect.
int LinkedListStack::Size()
{
	if (IsEmpty())
	{
		cout << "Stack is empty." << endl;
	}
	else
	{
		cout << "Stack size: " << stackSize << endl;
	}

	return stackSize;
}

// TODO: fix this so that it actually returns the top object
// and not just nodeData
// Return top element of stack
SNode LinkedListStack::Top()
{
	if (IsEmpty())
	{
		cout << "Stack is empty." << endl;
	}
	else
	{
		cout << "Top of stack: " << top->sTreeNodePointer->nodeData << endl;

		return *top;
	}

}

// Adds node to top of stack
void LinkedListStack::Push(TreeNode* treeNodePointer)
{
	// Initialize newNode and set it's pointers
	SNode* newNode;
	// when using 'new' remember to deallocate
	newNode = new SNode;
	newNode->sTreeNodePointer = treeNodePointer;
	newNode->previous = nullptr;
	newNode->next = nullptr;

	if (IsEmpty())
	{
		top = newNode;
		bottom = newNode;
	}
	else
	{
		top->next = newNode;
		newNode->previous = top;
		top = newNode;
	}

	stackSize++;
}

// Removes top element of the stack, reducing its size by one.
// I prefer that Pop() returns the value of the item removed.
void LinkedListStack::Pop(TreeNode* &treeNodePointer)
{
	SNode* temp;
	
	if (IsEmpty())
	{
		cout << "Stack is empty." << endl;
	}
	else
	{
		treeNodePointer = top->sTreeNodePointer;
		temp = top;
		top = top->previous;

		if (top != nullptr)
		{
			top->next = nullptr;
			delete temp;

			if (top == nullptr)
			{
				bottom = nullptr;
			}
		}
	} // end else
	stackSize--;
} // end Pop()

void LinkedListStack::DestroyStack()
{
	SNode* temp;

	while (top != nullptr)
	{
		temp = top;
		top = top->previous;
		delete temp;
	}

	bottom = nullptr;
}

void LinkedListStack::PrintStack()
{
	SNode* temp;
	temp = top;
	cout << "Printing stack: " << endl;

	while (top->previous != nullptr)
	{
		cout << temp->sTreeNodePointer->nodeData << ' ' << endl;
		temp = top->previous;
	}
}