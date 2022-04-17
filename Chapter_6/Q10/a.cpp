// const int and volatile int returns int
#include <bits/stdc++.h>

template<typename T>
std::make_unsigned_t<T> make_unsigned(T t)
{
    return std::make_unsigned_t<T>(t);
}

template<typename T>
std::add_const_t<T> add_const(T t)
{
    return std::add_const_t<T>(t);
}

const int f()
{
    return 0;
}

template<typename T>
std::remove_pointer_t<T> remove_pointer(T t) // it removes cv as well
{
    return std::remove_pointer_t<T>(t);
}

template<typename T>
std::add_volatile_t<T> add_volatile(T t)
{
    return std::add_volatile_t<T>(t);
}

int main()
{
    int a;
    std::cout
        << std::is_same<unsigned int, decltype(make_unsigned(1))>::value
        << std::is_same<const int, decltype(add_const(a))>::value
        << std::is_same<int, decltype(remove_pointer(new int(2)))>::value
        << std::is_same<volatile int, decltype(add_volatile(a))>::value
        << std::endl;
    return 0;
}