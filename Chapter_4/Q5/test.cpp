#include <iostream>
using namespace std;

class A
{
};

int main()
{
    A a;
    A& b = a;
    A&& c = std::move(a);
    std::cout << "A\n";
    std::cout << std::boolalpha << "Check value ref: "
        << std::is_reference<decltype(a)>::value << "\n"; // false
    std::cout << std::boolalpha << "Check l-value ref: "
        << std::is_lvalue_reference<decltype(b)>::value << "\n"; // true
    std::cout << std::boolalpha << "Check r-value ref: "
        << std::is_rvalue_reference<decltype(c)>::value << "\n"; // true
    int d;
    int& e = d;
    int&& f = std::move(d);
    std::cout << "int\n";
    std::cout << std::boolalpha << "Check value ref: "
        << std::is_reference<decltype(d)>::value << "\n"; // false
    std::cout << std::boolalpha << "Check l-value ref: "
        << std::is_lvalue_reference<decltype(e)>::value << "\n"; // true
    std::cout << std::boolalpha << "Check r-value ref: "
        << std::is_rvalue_reference<decltype(f)>::value << "\n"; // true
    return 0;
}