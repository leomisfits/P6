#include <iostream>
#include <vector>
usign namespace std;
class base{
public:
    base(int value): value_{value} { cout << "base(" << value << ")\n"; }
    base() : base{0} { cout << "base()\n"; }
    base(base const& copy)
    : value_{copy.value_}
    { cout << "copy base(" << value_ << ")\n"; }
    ~base() { cout << "~base(" << value_ << ")\n"; }

    int value() const { return value_; }
    base& operator++()
    {
        ++value_;
        return *this;
    }
private:
    int value_;
};

class derived : public base{
    public:
    derived(int value): base{value} { cout << "derived(" << value << ")\n"; }
    derived() : base{} { cout << "derived()\n"; }
    derived(derived const& copy)
    : base{copy}
    { cout << "copy derived(" << value() << "\n"; }
    ~derived() { cout << "~derived(" << value() << ")\n"; }
};

derived make_derived(){
    return derived{42};
} 

base increment(base b){
    ++b;
    return b;
}

void increment_reference(base& b){
    ++b;
}

int main(){
    derived d{make_derived()};
    base b{increment(d)};
    increment_reference(d);
    increment_reference(b);
    derived a(d.value() + b.value());
}