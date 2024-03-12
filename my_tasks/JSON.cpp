#include <iostream>
#include <string>

class Serializer{
public:
	virtual void BeginArray() = 0;
	virtual void AddArrayItem(const std::string&) = 0;	
	virtual void EndArray() = 0;
	Serializer(){}
	virtual ~Serializer(){}
};

class JsonSerializer : public Serializer{
public:
	void BeginArray() override{
		std::cout << "[";
	}
	void AddArrayItem(const std::string& str) override{
		std::string comma = ",";
		base_str += str;
		base_str += comma;
		// std::cout << "\"" << str << "\"" << ",";
	}
	void EndArray() override{
		if(!base_str.empty()){
			base_str.pop_back();
			std::cout << "\"" << base_str << "\"" << "]";	
			base_str.clear();
		}
		else{
			std::cout << "]";
		}
	}
private:
	std::string base_str = {};
};

int main(){
	JsonSerializer j;
	Serializer& s = j;
	s.BeginArray();
	s.BeginArray();
	s.AddArrayItem("hi");
	s.AddArrayItem("John");
	s.EndArray();
	s.EndArray();
	return 0;
}
