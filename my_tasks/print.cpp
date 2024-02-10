#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <array>
#include <forward_list> 
#include <list> 
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
template <typename T>
void Print(const T& container, const std::string& separator){
	auto iter = container.begin();
	for(; iter != container.end(); iter++){
		std::cout << *iter;
		if(std::next(iter) != container.end()){
			std::cout << separator;
		}
	}
	std::cout << std::endl;
}

int main(){
	std::vector<int> my_cont = {};
	std::string separ = ", ";
	for(size_t i = 0; i < 10; i++){
		my_cont.push_back(i + 5);
		std::cout << my_cont[i] << " ";
	}
	std::cout << std::endl;
	Print<std::vector<int>>(my_cont, separ);
	return 0;
}
