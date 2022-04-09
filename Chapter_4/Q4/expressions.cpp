#include <bits/stdc++.h>

void funcR(int&& z)
{ // r values and related issues
    std::cout << "func with rvalue input\n";
    std::cout << std::boolalpha << "Check value ref: "
        << std::is_reference<decltype(z)>::value << "\n"; // true
    std::cout << std::boolalpha << "Check l-value ref: "
        << std::is_lvalue_reference<decltype(z)>::value << "\n"; // false
    std::cout << std::boolalpha << "Check r-value ref: "
        << std::is_rvalue_reference<decltype(z)>::value << "\n"; // true
    std::cout << "\nMoved variable 2\n";
    auto&& v = std::move(z);
    std::cout << std::boolalpha << "Check value ref: "
        << std::is_reference<decltype(v)>::value << "\n";  // true
    std::cout << std::boolalpha << "Check l-value ref: "
        << std::is_lvalue_reference<decltype(v)>::value << "\n";  // false
    std::cout << std::boolalpha << "Check r-value ref: "
        << std::is_rvalue_reference<decltype(v)>::value << "\n";  // true
    std::cout << std::boolalpha << "Same as int?: "
        << std::is_same<decltype(v), int>::value << "\n";  // false
    std::cout << std::boolalpha << "Same as int?: "
        << std::is_same<decltype(v), int&&>::value << "\n";  // true
}

struct C
{
    C(double val, int valInt) : x(val) {}
    double x;
};

void ValueCategories()
{ // Value categories of expressions in C++11, decltype and type traits
    const C* c = new C{ 0.0, 1 };
    decltype(c -> x) y; // type of y is double
    decltype((c->x)) z = y; // type of z is const double&
    std::cout << std::boolalpha << "\nCheck value ref: "
        << std::is_reference<decltype(c->x)>::value << "\n"; // false
    std::cout << std::boolalpha << "Check l-value ref: "
        << std::is_lvalue_reference<decltype(c->x)>::value << "\n"; // false
    std::cout << std::boolalpha << "Check r-value ref: "
        << std::is_rvalue_reference<decltype(c->x)>::value << "\n"; // false
    // Non-reference type
    std::cout << std::boolalpha << "Check value ref: "
        << std::is_reference<decltype(y)>::value << "\n"; // false
    std::cout << std::boolalpha << "Check l-value ref: "
        << std::is_lvalue_reference<decltype(y)>::value << "\n"; // false
    std::cout << std::boolalpha << "Check r-value ref: "
        << std::is_rvalue_reference<decltype(y)>::value << "\n"; // false
    // Reference type
    std::cout << std::boolalpha << "Check value ref: "
        << std::is_reference<decltype(z)>::value << "\n"; // true
    std::cout << std::boolalpha << "Check l-value ref: "
        << std::is_lvalue_reference<decltype(z)>::value << "\n"; // true
    std::cout << std::boolalpha << "Check r-value ref: "
        << std::is_rvalue_reference<decltype(z)>::value << "\n"; // false
}

int main()
{
    funcR(3);
    ValueCategories();
    return 0;
}