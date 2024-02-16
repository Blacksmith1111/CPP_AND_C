#include <iostream>
#include <deque>
#include <string>
#include <vector>

std::string& checking_order(std::deque<std::string>& students_in_order, int student_number){
	return students_in_order[student_number];
};

std::deque<std::string>& students_order(std::deque<std::string>& students_works_in_order, const std::string& surname){
	int i = 0;
	for(; surname[i] != ' '; i++){}
	if(surname.substr(i+1) == "top"){
		students_works_in_order.push_front(surname.substr(0, i));
	}
	else if(surname.substr(i+1) == "bottom"){
		students_works_in_order.push_back(surname.substr(0, i));
	}	
	return students_works_in_order;
}

int main(){
	std::string surname;
	std::deque<std::string> students_works_in_order;
	int number_of_students = 0, number_of_works = 0, exact_number = 0;
	std::vector<int> exact_numbers;
	std::cin >> number_of_students;

	getline(std::cin, surname);

	for(int i = 0; i < number_of_students; i++){
		getline(std::cin, surname);
		students_order(students_works_in_order, surname);
	}

	std::cin >> number_of_works;

	for(int i = 0; i < number_of_works; i++){
		std::cin >> exact_number;
		exact_numbers.push_back(exact_number);
	}

	for(int i = 0; i < number_of_works; i++){
		std::cout << students_works_in_order[exact_numbers[i] - 1] << std::endl;
	}

	return 0;
}
