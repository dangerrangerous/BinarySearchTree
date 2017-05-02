#pragma once

struct SNode
{
	TreeNode* sTreeNodePointer;
	SNode* previous;
	SNode* next;
};

class LinkedListStack
{
public:
	// Default constructor
	LinkedListStack(void);
	// Default destructor
	~LinkedListStack(void);

	// Public member functions
	void InitializeStack();
	bool IsEmpty();
	int Size();
	void Top();
	void Push();
	void Pop();
	void Swap();
};