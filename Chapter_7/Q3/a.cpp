// all compiles
#include <iostream>

struct A
{
    int Z;
    A(int z) {Z = z;}
    A(const A&) = delete;
    A& operator = (const A&) = delete;
};

struct B
{
    int Z;
    B(int z) {Z = z;}
    B(const B&) = default;
    B& operator = (const B&) = default;
};

struct C
{
    int Z;
    C(int z) {Z = z;}
    C(const C&) = default;
    C& operator = (const C&) = delete;
};

struct F
{
    int Z;
    F(int z) {Z = z;}
    F(const F&) = delete;
    F& operator = (const F&) = default;
};

int main()
{
    C a{1};
    C b = a;
    std::cout << b.Z << std::endl;
    F c{1};
    F d{2};
    d = c;
    std::cout << d.Z << std::endl;
    return 0;
}