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
	SNode* Top();
	void Push(TreeNode*);
	// think Pop() needs fixed
	void Pop();
	// void Swap();
	void DestroyStack();
	void PrintStack();

private:
	SNode* top;
	SNode* bottom;
};