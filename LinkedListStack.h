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
	int Top();
	void Push(TreeNode*);
	void Pop(TreeNode* &);
	// void Swap();
	void DestroyStack();
	// void PrintStack();

private:
	SNode* top;
	SNode* bottom;
};