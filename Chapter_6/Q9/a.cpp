#include <bits/stdc++.h>

int main()
{
    std::cout
        << std::is_array<int[]>::value
        << std::is_array<int>::value
        << std::endl;
    return 0;
}