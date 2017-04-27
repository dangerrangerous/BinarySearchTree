

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

void Queue::RemoveFront(TreeNode* treeNodePointer)
{
	QNode* temp;
	
	if (IsEmpty())
		treeNodePointer = nullptr;
	else
	{
		treeNodePointer = front->qTreeNodePointer;
		temp = front;
		front = front->previous;

		if (front != NULL)
		{
			front->next = NULL;
			delete temp;

			if (front == NULL)
			{
				back = NULL;
			}
		}
	} // end else

} // end RemoveFront()

bool Queue::IsEmpty()
{
	return (front == NULL);
}
