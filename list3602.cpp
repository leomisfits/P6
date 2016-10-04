#include <iostream>
using namespace std;
class base
{
public:
    base() {cout << "base\n";};
    ~base(){cout << "~base\n";};;

};

class middle : public base{
public:
    middle() {cout << "middle\n";};
    ~middle(){cout << "~middle\n";};;

};

class derived : public middle{
public:
    derived() {cout << "derived\n";};
    ~derived(){cout << "~derived\n";};;

};

int main()
{
    derived d;
}
