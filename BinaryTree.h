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
	void IterativePostOrderTraversal();

	bool IsInTree(int);
	void Delete(int);
	// int Max(int, int);
	int TreeHeight();
	int TreeNodeCount();
	int TreeLeafCount();

private:
	// Private
	void BreadthFirst(TreeNode*);
	void IterativeInOrder(TreeNode*);
	void IterativePreOrder(TreeNode*);
	void IterativePostOrder(TreeNode*);
	
	int Height(TreeNode*);
	int NodeCount(TreeNode*);
	int LeafCount(TreeNode*);

	TreeNode* root;
};