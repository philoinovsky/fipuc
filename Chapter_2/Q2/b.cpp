// b. see the shared_ptr count
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

void program()
{
    std::shared_ptr<double> sp(new double(1));
    C1 c1(sp);
    C2 c2(sp);
    std::cout << sp.use_count() << std::endl; // 3
    return;
}

int main()
{
    program();
    return 0;
}