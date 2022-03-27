// a
#include <iostream>
class Base
{ // Base class
private:
public:
    Base() { }
    virtual void print() const = 0;
protected:
    virtual ~Base() { std::cout << "Base destructor\n\n"; }
};

class Derived : public Base
{ // Derived class
private:
public:
    Derived() : Base() { }
    ~Derived() { std::cout << "Derived destructor\n"; }
    void print() const { std::cout << "derived object\n";}
};