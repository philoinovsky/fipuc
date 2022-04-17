#include <bits/stdc++.h>

class A
{
public:
    void func() {};
};

void func()
{
    std::cout << std::is_member_function_pointer<decltype(&A::func)>::value
            << std::is_member_object_pointer<decltype(&A::func)>::value
            << std::endl;
}

int main()
{
    func();
    return 0;
}