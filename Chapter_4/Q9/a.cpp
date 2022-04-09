#include <type_traits>
#include <iostream>


template <int M, int N, typename std::enable_if_t<M == 0, bool> = true>
constexpr int Ackermann()
{
    return N + 1;
}

template <int M, int N, typename std::enable_if_t<(M > 0) && (N == 0), bool> = true>
constexpr int Ackermann()
{
    return Ackermann<M - 1, 1>();
}

template <int M, int N, typename std::enable_if_t<(M > 0) && (N > 0), bool> = true>
constexpr int Ackermann()
{
    return Ackermann<M - 1, Ackermann<M, N - 1>()>();
}

int main()
{
    std::cout << Ackermann<1, 3>() << std::endl;
    return 0;
}