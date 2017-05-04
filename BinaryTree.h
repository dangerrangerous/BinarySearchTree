#pragma once
/*
struct TreeNode
{
	int nodeData;
	TreeNode* leftChild;
	TreeNode* rightChild;
};
*/
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
	void Insert(int);
	bool IsEmpty();
	void IterativeInOrderTraversal();
	void IterativePreOrderTraversal();

private:
	// Private
	void BreadthFirst(TreeNode*);
	void IterativeInOrder(TreeNode*);
	void IterativePreOrder(TreeNode*);

	TreeNode* root;
};