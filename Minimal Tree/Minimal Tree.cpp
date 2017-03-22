// Minimal Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode
{
	int value;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* buildTree(vector<int> input, int start, int end)
{
	if (start > end)		return nullptr;

	int mid = (start + end) / 2;
	TreeNode* root = new TreeNode();
	root->value = mid;
	root->left = buildTree(input, start, mid - 1);
	root->right = buildTree(input, mid + 1, end);
	return root;
}

void inorder(TreeNode* root)
{
	if (root == NULL)
		return;

	/* first recur on left child */
	inorder(root->left);

	/* then print the data of node */
	cout << root->value << endl;

	/* now recur on right child */
	inorder(root->right);
}

int main()
{
	vector<int> input = { 1,2,3,4,5,6,7,8 };
	TreeNode* root = buildTree(input, 0, input.size());
	inorder(root);
    return 0;
}


