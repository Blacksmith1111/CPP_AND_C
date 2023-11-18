#include <iostream>
// make a delete_node function, solve the leetcode task, balance the tree
namespace Trees{
	class Tree{
	private:
		class Node{
		public:
			int key;
			Node* left = nullptr, *right = nullptr, *parent = nullptr;
			Node(int val = 0): key(val){};
			~Node(){
				delete left;
				delete right;
				std::cout << "Deleted the node" << std::endl;
			}
			Node(const Node& example) = delete;
		}; //class Node is over
		Node* root;
		using iterator = Node*;
		iterator current = root;
	public:
		Tree(int val):root(new Node(val)){};
		~Tree(){
			delete root;
			std::cout << "Deleted the tree" << std::endl;
		}
		Tree(const Tree& example) = delete;
		/*void setter_to_the_root(){
			current = root;
		}*/
		int getter(){
			return current -> key;
		}
		int getter_parent(){
			return current -> parent -> key;
		}
		void add_the_element(int val){
			current = root;
			while(1){
				if(val > current -> key && current -> right != nullptr){
					current = current -> right;
				}
				else if(val < current -> key && current -> left != nullptr){
					current = current -> left;
				}
				else{
					break;
				}
			}
			if(val > current -> key){
				current -> right = new Node(val);
				current -> right -> parent = current;
				current = current -> right;
			}
			else if(val < current -> key){
				current -> left = new Node(val);
				current -> left -> parent = current;
				current = current -> left;
			}
		}
		void delete_the_element(int val){
			current = root;
			while(1){
				if(val > current -> key && current -> right != nullptr){
					current = current -> right;
				}
				else if(val < current -> key && current -> left != nullptr){
					current = current -> left;
				}
				else{
					break;
				}
			}

			Node* temp;
			if(current -> right != nullptr && current -> left != nullptr){
				(current -> right) -> parent = current -> parent;
				for(temp = (current -> right); temp != nullptr; temp = temp -> left){}
				(current -> left) -> parent = temp;	
			}

			if((current -> parent) -> key > val){
					if(current -> right != nullptr){
						(current -> right) -> parent = current -> parent;
						(current -> parent) -> left = current -> right;
					}
					else{
						(current -> left) -> parent = current -> parent;
						(current -> parent) -> left = current -> left;
					}		
				}
			else{
				if(current -> right != nullptr){
					(current -> right) -> parent = current -> parent;
					(current -> parent) -> right = current -> right;
				}
				else{
					(current -> left) -> parent = current -> parent;
					(current -> parent) -> right = current -> left;
				}		
			}
		}
	};	
}

int main(){
	Trees::Tree my_tree(5);
	// my_tree.setter_to_the_root();
	std::cout << my_tree.getter() << std::endl;
	my_tree.add_the_element(6);
	std::cout << my_tree.getter() << std::endl;
	my_tree.add_the_element(3);
	std::cout << my_tree.getter() << std::endl;
	std::cout << my_tree.getter_parent() << std::endl;
	return 0;
}
