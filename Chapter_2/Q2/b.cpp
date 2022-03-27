// b. see the shared_ptr count
// output:

// C2 destructor

// C1 destructor
// 0
#include <iostream>
#include <memory>
#include <cstdlib>

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

std::shared_ptr<double> sp(new double(1));
std::weak_ptr<double> wp(sp);

void use_count()
{
    std::cout << wp.use_count() << std::endl; // 0
};

int main()
{
    C1 c1(sp);
    C2 c2(sp);
    sp.reset();
    std::atexit(use_count);
    return 0;
}