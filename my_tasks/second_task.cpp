#include <iostream>
#include <string>

int romanToInt(std::string s);
int main(){
	std::string s;
	std::cin >> s;
	std::cout << romanToInt(s) << "\n";
	return 0;
}



int romanToInt(std::string s) {
	int sum = 0;
	std::string roman = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	int normal[] = {1, 5, 10, 50, 100, 500, 1000};
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'I' && s[i+1] == 'V'){
			sum += 4;
			i += 1;
		}
		else if(s[i] == 'I' && s[i+1] == 'X'){
			sum += 9;
			i += 1;
		}
		else if(s[i] == 'X' && s[i+1] == 'L'){
			sum += 40;
			i += 1;
		}
		else if(s[i] == 'X' && s[i+1] == 'C'){
			sum += 90;
			i += 1;
		}
		else if(s[i] == 'C' && s[i+1] == 'D'){
			sum += 400;
			i += 1;
		}
		else if(s[i] == 'C' && s[i+1] == 'M'){
			sum += 900;
			i += 1;
		}
		for(int j = 0; j < roman.size(); j++){
			if(s[i] == roman[j]){
				sum += normal[j]; 
			}
		}
	} 
	return sum;
}
