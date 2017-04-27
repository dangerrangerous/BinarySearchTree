#pragma once

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
	void Enqueue(TreeNode*);
	void Dequeue(TreeNode*);
	bool IsEmpty();
	void PrintQueue();
	void DestroyQueue();

private:
	QNode* front;
	QNode* back;

};