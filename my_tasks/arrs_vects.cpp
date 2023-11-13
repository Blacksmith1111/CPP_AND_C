#include <iostream>

class arr{
	int value;
public:
	//arr(){};
 	int setter(int i);
	int getter();
	void printing();
	void printing(std::ostream& os, int val);	
	//~arr(){};
};

int main(){
	arr* p = new arr[10];
	for(int i = 0; i < 10; i++){
		p[i].setter(i);
		p[i].printing();
	}
	p[3].printing(std::cout, p[3].getter());
	delete [] p;
	return 0;
}

int arr::getter(){
	return value;
}

void arr::printing(std::ostream& os, int val){
	os << val << "\n"; 
}

void arr::printing(){
	std::cout << value << "\n";
}

int arr::setter(int i){
	value = i;
	return value;
}
