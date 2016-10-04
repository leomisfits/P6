#include <iostream>
class base{
public:
	base() {std::cout <<"base\n";}
	~base() {std::cout <<"~base\n";}
};

class middle : public base {
public:
	middle() {std::cout << "middle\n";}
	~middle() { std::cout <<"~middle\n";}
};

int main() {
	derived d;
}