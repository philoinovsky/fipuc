#include <functional>
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void print() const { std::cout << "Base\n";}
};

class D : public Base
{
public:
    void print() const { std::cout << "Derived\n";}
};

class D2 : public Base
{
public:
    void print() const { std::cout << "Derived2\n";}
};

int main()
{
    // Binding and polymorphism
    typedef std::function <void ()> FunType3;
    Base* b = new D;
    std::cout << b << std::endl;
    FunType3 myF3 = std::bind(&Base::print, std::ref(b));
    myF3(); // Derived class D print will be called
    delete b;
    auto c = new int;
    b = new D2;
    std::cout << b << std::endl;
    myF3(); // Derived class D2 print will be called
    delete b;
    delete c;
    return 0;
}