#include <bits/stdc++.h>

template<typename T>
void print_impl(const T& t, std::true_type)
{
    std::cout << *t << std::endl;
}

template<typename T>
void print_impl(const T& t, std::false_type)
{
    if (std::is_scalar<T>::value)
        std::cout << t << std::endl;
}

template <typename T>
void print(const T& t)
{
    print_impl(t, std::is_pointer<T>());
}

int main()
{
    print(std::shared_ptr<int>(new int(123)).get());
    print(456);
    return 0;
}