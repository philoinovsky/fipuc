// b. create Factory function
// output:
// compiling error, because of Base Destructor is protected
#include <iostream>
#include <list>
#include <memory>

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

class Factory
{
public:
    auto create_derived()
    {
        return std::make_unique<Derived>();
    }
};

int main()
{
    std::list<std::unique_ptr<Base>> l;
    for (int i = 0; i < 5; i++)
    {
        l.push_back(Factory().create_derived());
    }
    return 0;
}