#include <iostream>
#include <assert.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isValidBST(TreeNode* root){
		return isValidBST_helper(root, &low, &high);
	}

	bool isValidBST_helper(TreeNode* root, int* low, int* high){
		assert(root != nullptr && low != nullptr && high != nullptr);
		*low = *high = root -> val;
		if(root -> left != nullptr){
			if(root -> left -> val >= root -> val){
				return false;
			}
			int left_low = 0, left_high = 0;
			if(!isValidBST_helper(root -> left, &left_low, &left_high)){
				return false;
			}
			assert(left_low <= left_high);
			if(root -> val <= left_high){
				return false;
			}
			*low = left_low;
		}
		if(root -> right != nullptr){
			if(root -> right -> val <= root -> val){
				return false;
			}
			int right_low = 0, right_high = 0;
			if(!isValidBST_helper(root -> right, &right_low, &right_high)){
				return false;
			}
			assert(right_low <= right_high);
			if(root -> val >= right_low){
				return false;
			}
			*high = right_high;
		}
		return true;
	}

private:
	int low = 0;
	int high = 0;
};

int main(){
	TreeNode start(7);
	start.left = new TreeNode(5);
	start.left->left = new TreeNode(4);
	Solution a;

	if(a.isValidBST(&start)){
		std::cout << "The tree is valid" << std::endl;
	}
	if(!a.isValidBST(&start)){
		std::cout << "The tree is invalid" << std::endl;
	}

	return 0;
}
