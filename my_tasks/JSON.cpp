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
		base_str += "[";
	}
	void AddArrayItem(const std::string& str) override{
		base_str += quotation_mark;
		base_str += str;
		base_str += quotation_mark;
		base_str += comma;
	}
	void EndArray() override{
		if(base_str.rfind(comma) == base_str.size() - 1 && base_str.rfind(comma) != std::string::npos){
			base_str.pop_back();
		}
		base_str += "]";	
	}
	JsonSerializer(){}
	~JsonSerializer(){
		std::cout << base_str << "\n";
	}
private:
	std::string base_str = {};
	std::string comma = ",";
	std::string quotation_mark = "\"";
};
