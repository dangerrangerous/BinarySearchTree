

#include "stdafx.h"
#include <iostream>
#include "CustomTypes.h"
#include "Queue.h"

using namespace std;

// Default constructor
Queue::Queue(void)
{
	front = nullptr;
	back = nullptr;
}

// Default destructor
Queue::~Queue(void)
{
	cout << "Destroying queue." << endl;
	// DestroyQueue();
}

void Queue::InitializeQueue()
{
	// DestroyQueue();
}

void Queue::Enqueue(TreeNode* treeNodePointer)
{
	QNode* newNode;

	// Initialize newNode and set its pointers
	newNode = new QNode;
	newNode->qTreeNodePointer = treeNodePointer;
	newNode->previous = nullptr;
	newNode->next = nullptr;

	if (IsEmpty())
	{
		front = newNode;
		back = newNode;
	}
	else
	{
		back->previous = newNode;
		newNode->next = back;
		back = newNode;
	}
} // end Enqueue()

bool Queue::IsEmpty()
{
	return (front == NULL);
}
