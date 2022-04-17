#include <bits/stdc++.h>

void func()
{
    using type = int;
    std::cout << std::is_pointer<type>::value << std::is_null_pointer<type>::value
            << std::is_lvalue_reference<type>::value << std::is_rvalue_reference<type>::value
            << std::endl;
}

int main()
{
    func();
    return 0;
}