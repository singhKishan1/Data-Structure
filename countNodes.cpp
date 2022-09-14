// count Nodes in complete Binary tree
// using binary search --leetcode--problem--.
// solution of leetcode problem.

#include <iostream>
using namespace std;

class TreeNode{
public:
	TreeNode* left;
	TreeNode* right;
	int val;

	TreeNode(int x){
		val = x;
		left = right= NULL;
	}
};

// ---solution starts from here---

int leftHeight(TreeNode* root){
	int count = 0;
	while(root!=NULL){
		++count;
		root = root->left;
	}
	return count;
}

int rightHeight(TreeNode* root){
	int count = 0;
	while(root!=NULL){
		++count;
		root = root->right;
	}

	retur count;
}

int solve(TreeNode* root){
	if(root==NULL)
		return root;

	int left_height = leftHeight(root);
	int right_height = rightHeight(root);

	if(left_height==right_height)
		return (1<<left_height)-1;

	return 1+solve(root->left)+solve(root->right);
}

