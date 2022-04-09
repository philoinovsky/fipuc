// Q7: rewrite below code to remove overlapping enabler conditions

// template <class T>
// typename std::enable_if<std::is_integral<T>, void>::type
// foo(T t) {}

// template <class T>
// typename std::enable_if<std::is_arithmetic<T>, void>::type
// foo(T t) {}

#include <type_traits>

template <class T>
typename std::enable_if<
    !std::is_arithmetic<T>::value && std::is_integral<T>::value, void>::type
foo(T t) {}

template <class T>
typename std::enable_if<std::is_arithmetic<T>::value, void>::type
foo(T t) {}

int main()
{
    foo(1.0);
    return 0;
}