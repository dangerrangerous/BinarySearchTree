

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
	// Return number of elements in stack
}

void LinkedListStack::Top()
{

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
} // end Pop()