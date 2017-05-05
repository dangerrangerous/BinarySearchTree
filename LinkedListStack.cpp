// LinkedList implementation
// Brian Keppinger

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
	// cout << "Destroying stack." << endl;
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

// Return number of elements in stack.
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

// Return top element of stack.
SNode* LinkedListStack::Top()
{
	if (IsEmpty())
	{
		cout << "Stack is empty." << endl;
	}

	return top;
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
} // end Push()

// Removes top element of the stack, reducing its size by one.
void LinkedListStack::Pop()
{
	SNode* temp;
	if (IsEmpty())
	{
		cout << "Stack is empty." << endl;
	}
	else
	{
		temp = top;
		top = top->previous;

		if (top != nullptr)
		{
			top->next = nullptr;
			delete temp;
		}

		if (top == nullptr)
		{
			bottom = nullptr;
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
} // end DestroyStack()

void LinkedListStack::PrintStack()
{
	SNode* temp;
	temp = top;
	// cout << "Printing stack: " << endl;

	while (temp->previous != nullptr)
	{
		cout << temp->sTreeNodePointer->nodeData << ' ';
		temp = top->previous;
		top = temp;
	}
	// print last item in the stack
	cout << temp->sTreeNodePointer->nodeData << ' ';
} // end PrintStack()