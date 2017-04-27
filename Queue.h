#pragma once

// Can cautiously move this to CustomTypes.h
struct QNode
{
	TreeNode* qTreeNodePointer;
	QNode* previous;
	QNode* next;

};

class Queue
{
public:
	// Default Constructor
	Queue(void);

	// Default Destructor
	~Queue(void);

	// Public member functions
	void InitializeQueue();
	void AddToQueue(TreeNode*);
	void RemoveFront(TreeNode*);
	bool IsEmpty();
	void PrintQueue();
	// void DestroyQueue();

private:
	QNode* front;
	QNode* back;

};