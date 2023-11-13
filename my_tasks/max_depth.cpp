#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	~TreeNode(){delete left; delete right;}
};

struct tree{
	public:
	TreeNode* nd = nullptr;
	TreeNode* add_to_the_left(TreeNode* curr, int number);
	TreeNode* add_to_the_right(TreeNode* curr, int number);
	
};

TreeNode* tree::add_to_the_left(TreeNode* curr, int number){
	TreeNode* temp = new TreeNode(number);
	curr -> left = temp;
	curr = curr -> left;
	return curr;
}

TreeNode* tree::add_to_the_right(TreeNode* curr, int number){
	TreeNode* temp = new TreeNode(number);
	curr -> right = temp;
	curr = curr -> right;
	return curr;
}


/*class Solution {
public:
	int maxDepth(TreeNode* root) {
	
}
};*/

int main(){
	tree our;
	if(our.nd == nullptr){
		our.nd = new TreeNode();
	}
	std::cout << our.nd -> val <<"\n";
	return 0;
}