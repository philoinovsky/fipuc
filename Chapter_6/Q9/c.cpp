// output:
// 40345
#include <bits/stdc++.h>

template<typename T>
void print(const T& t)
{
    std::cout
        << std::rank<T>::value
        << std::extent<T, 0>::value
        << std::extent<T, 1>::value
        << std::endl;
}

template<typename T>
void print_removed(const T& t) // remove first rank
{
    using removed = std::remove_extent_t<T>;
    std::cout
        << std::rank<removed>::value
        << std::extent<removed, 0>::value
        << std::extent<removed, 1>::value
        << std::endl;
}

template<typename T>
void print_removed_all(const T& t) // remove all ranks
{
    using removed_all = std::remove_all_extents_t<T>;
    std::cout
        << std::rank<removed_all>::value
        << std::extent<removed_all, 0>::value
        << std::extent<removed_all, 1>::value
        << std::endl;
}

int main()
{
    int a[][3] = {{1,2,3},{4,5,6}};
    print(a);
    print_removed(a);
    print_removed_all(a);
    return 0;
}