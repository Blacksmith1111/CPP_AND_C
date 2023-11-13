#include <iostream>
#include <vector>


std::vector<int> twoSum(std::vector<int>& nums, int target);
std::vector<int> vector_creating(int number);
void output(std::vector<int> vect);
int main(){
	int target, number;
	std::vector <int> nums;
	std::cout << "write the number of elements and the target\n";
	std::cin >> number >> target;
	std::cout << "\n";
	std::vector <int> ref = vector_creating(number);
	//std::vector <int> ref = {1, 1, 2, 3};
	output(ref);
	std::vector <int> & ptr = ref;
	std::vector <int> vect = twoSum(ptr, target);
	output(vect);
	return 0;
}

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::vector <int> result;	
    for(int i = 0; i < nums.size(); i++){
		for(int j = 0; j < nums.size(); j++){
			if((nums[i] + nums[j]) == target & (i != j)){
				result = {j, i};
			}
		}
	}	
	return result;
}

std::vector<int> vector_creating(int number){
	std::vector<int> creation;
	for(int i = 0; i < number; i++){
		creation.push_back(i);
	}
	return creation;
}

void output(std::vector<int> vect){
	for(int i = 0; i < vect.size(); i++){
		std::cout << vect[i] << " ";
	}
	std::cout << "\n";
}

