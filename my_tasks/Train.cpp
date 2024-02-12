#include <iostream>
#include <deque>
#include <string>
#include <assert.h>

void MakeTrain();

int main(){
	
	MakeTrain();
	return 0;
}

void MakeTrain(){
	static int checker = 0;
	static std::deque<int> Train;
	std::string train_command;
	while(checker < 6){
	getline(std::cin, train_command);

	int space_index = train_command.find(" ");
	
	if(train_command.substr(0, 1) == "+"){
		if(train_command.substr(1, space_index - 1) == "left"){
			Train.push_front(atoi(train_command.substr(space_index + 1).c_str())); 
		}
		else if(train_command.substr(1, space_index - 1) == "right"){
			Train.push_back(atoi(train_command.substr(space_index + 1).c_str()));
		}
	}
	else if(train_command.substr(0, 1) == "-"){
		assert(atoi(train_command.substr(space_index + 1).c_str()) >= 0);

		if(atoi(train_command.substr(space_index + 1).c_str()) > static_cast<int>(Train.size())){
			Train.clear();
		}
		if(train_command.substr(1, space_index - 1) == "left"){
			auto del_iter = Train.begin();
			Train.erase(del_iter, del_iter + atoi(train_command.substr(space_index + 1).c_str())); 
		}
		else if(train_command.substr(1, space_index - 1) == "right"){
			auto del_iter = Train.end();
			Train.erase(del_iter - atoi(train_command.substr(space_index + 1).c_str()), del_iter);
		}
	}
	checker++;
	}
	auto iter_start = Train.begin();
	auto iter_finish = Train.end();

	for(;iter_start != iter_finish; iter_start++){
		std::cout << *iter_start << " ";
	}
}
