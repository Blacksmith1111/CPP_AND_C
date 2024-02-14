#include <iostream>
#include <assert.h>
#include <vector>
#include <deque>

void editor(std::deque<std::string>& strings, const std::string& command){
	assert(command == "Down" || command == "Up" || command == "Ctrl+X" || command == "Ctrl+V" || command == "");
	if(command == ""){
		return;
	}

	static std::string buffer = "";
	static auto iter_left = strings.begin(); 
	
	if(command == "Down" && *iter_left != ""){
		iter_left = std::next(iter_left);
	}
	else if(command == "Up" && iter_left != strings.begin()){
		iter_left = std::prev(iter_left);
	}
	else if(command == "Ctrl+X" && *iter_left != ""){
		buffer = *iter_left;
		iter_left = strings.erase(iter_left);
	}
	else if(command == "Ctrl+V" && buffer != ""){
		iter_left = std::next(strings.insert(iter_left, buffer));
	}
	else{
		return;
	}
}

void filling_the_commands(std::deque<std::string>& mystrings){
	std::string command("f");
	while(command != ""){
		getline(std::cin, command, '\n');
		editor(mystrings, command);
	}
}

void filling_the_text(std::deque<std::string>& mystrings){
	std::string str("f");
	while(1){
		if(str == ""){
			break;
		}
		getline(std::cin, str);
		mystrings.push_back(str);
	}
}

void show_edited_text(std::deque<std::string>& mystrings){
	for(std::string temp : mystrings){
		std::cout << temp << std::endl;
	}
}

int main(){
	std::vector<std::string> commands = {};
	std::deque<std::string> mystrings;

	filling_the_text(mystrings);
	filling_the_commands(mystrings);	
	show_edited_text(mystrings);
	return 0;
}

