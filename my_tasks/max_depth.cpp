#include <iostream>

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
	TreeNode(const TreeNode& temp) = delete;
	~TreeNode(){
		delete left; 
		delete right;
		}
};

class Solution {
public:
	int maxDepth(TreeNode* root){
		if(root == nullptr){
			return 0;
		}
		else{
			int number_left = maxDepth(root -> left);
			int number_right = maxDepth(root -> right);
			return maximum_number(number_left, number_right) + 1;
		}
	}

	int maximum_number(int f_number, int s_number){
		int result = f_number >= s_number ? f_number : s_number;
		return result;
	}

	Solution(){};
	~Solution(){}
};

int main(){
	TreeNode start;
	start.left = new TreeNode(5);
	start.left->left = new TreeNode(6);
	Solution a;
	std::cout << a.maxDepth(&start) << std::endl;
	return 0;
}
