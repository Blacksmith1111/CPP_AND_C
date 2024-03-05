#include <map>
#include <string>
#include <vector>
#include <iostream>


struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;
public:
    bool Has(const std::vector<std::string>& node) const;
    void Insert(const std::vector<std::string>& node);
    void Delete(const std::vector<std::string>& node);
};

bool Tree::Has(const std::vector<std::string>& node) const{
	if(root.children.empty()){
		return false;
	};
	
	const Node* temp = &root;

	for(auto iter = node.begin(); iter != node.end(); iter++){
		auto temp_it = temp -> children.find(*iter);
		if(temp_it == temp -> children.end()){
			return false;
		}
		temp = &(temp_it -> second);
	}

	return true;
};

void Tree::Insert(const std::vector<std::string>& node){
	if(Has(node)){
		return;
	}

	Node* temp = &root;
	for(auto iter = node.begin(); iter != node.end(); iter++){
		temp = &(temp->children[*iter]);
	}
};

void Tree::Delete(const std::vector<std::string>& node){
        Node* current = &root;
        for (const auto& key : node) {
            auto it = current->children.find(key);
            if (it == current->children.end()) {
                return; 
            }
            if (current->children.size() == 1) {
                current->children.erase(it);
                return;
            }
            current = &it->second;
        }
};
