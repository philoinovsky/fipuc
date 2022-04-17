// output:
// 40345
#include <bits/stdc++.h>

int main()
{
    std::cout
        << std::rank<int[][3][4][5]>::value
        << std::extent<int[][3][4][5], 0>::value
        << std::extent<int[][3][4][5], 1>::value
        << std::extent<int[][3][4][5], 2>::value
        << std::extent<int[][3][4][5], 3>::value
        << std::endl;
    return 0;
}