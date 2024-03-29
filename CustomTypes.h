#pragma once
// Custom Types Header file
// Brian Keppinger

struct TreeNode
{
	int nodeData;
	TreeNode* leftChild;
	TreeNode* rightChild;
};

enum MenuChoices { Quit, Insert, BreadthFirst, IterativeInOrder, IterativePreOrder, 
					IterativePostOrder,	Delete, Height, Find, LeafCount, NodeCount };