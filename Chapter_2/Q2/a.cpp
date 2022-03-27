// a. create two classes that share the same shared_ptr object
#include <iostream>
#include <memory>

class C1
{
private:
    std::shared_ptr<double> d;
public:
    C1(std::shared_ptr<double> value) : d(value) {}
    virtual ~C1() { std::cout << "\nC1 destructor\n";}
    void print() const { std::cout << "Value " << *d; }
};

class C2
{
private:
    std::shared_ptr<double> d;
public:
    C2(std::shared_ptr<double> value) : d(value) {}
    virtual ~C2() { std::cout << "\nC2 destructor\n";}
    void print() const { std::cout << "Value " << *d; }
};

int main()
{
    return 0;
}