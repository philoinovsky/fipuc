#include <type_traits>
#include <iostream>

template <int N, typename std::enable_if_t<N == 0, bool> = true>
constexpr int factorial()
{
    return 1;
}

template <int N, typename std::enable_if_t<(N >= 1), bool> = true>
constexpr int factorial()
{
    return factorial<N-1>() * N;
}

int main()
{
    std::cout << factorial<10>() << std::endl;
    return 0;
}