#pragma once

class BinaryTree
{
public:
	// Constructor
	BinaryTree(void);

	// Destructor	
	~BinaryTree(void);

	// Public member functions
	void BreadthFirstTraversal();
	void InitializeTree();
	void Insert();
	bool isEmpty();

private:
	// Private
	TreeNode* root;
};