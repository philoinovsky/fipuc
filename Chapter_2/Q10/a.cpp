// a. list of pointers of generic type
#include <memory>
#include <iostream>
#include <list>
using namespace std;

template <typename T>
struct example
{
    list<unique_ptr<T>> lup;
};

int main()
{
    return 0;
}