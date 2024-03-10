#include <iostream>
#include <vector>

class Figure{
public:
	Figure(){}
	virtual ~Figure(){}
	virtual int Perimeter() const{
		return 1;
	}
	int a = 0, b = 0;
};

class Triangle : public Figure{
public:
	Triangle(int a, int b, int c): c(c){
		this -> a = a;
		this -> b = b;
	}
	~Triangle(){}
	int Perimeter() const override{
		return a + b + c;
	}
private: 
	int c = 0;
};

class Rectangle : public Figure{
public:
	Rectangle(int a, int b){
		this -> a = a;
		this -> b = b;
	}
	~Rectangle(){}
	int Perimeter() const override{
		return 2 * a + 2 * b;
	}
};

int main() {
    std::vector<Figure*> figures;

    std::string type;

    while (std::cin >> type) {
		if(type == "end"){
			break;
		}
        if (type == "Triangle") {
            int a, b, c;
            std::cin >> a >> b >> c;
            figures.push_back(new Triangle(a, b, c));
        } else if (type == "Rectangle") {
            int a, b;
            std::cin >> a >> b;
            figures.push_back(new Rectangle(a, b));
        }
    }

    for (Figure* f : figures) {
        std::cout << f->Perimeter() << "\n";
    }

    for (Figure* f : figures) {
        delete f;
    }
}
