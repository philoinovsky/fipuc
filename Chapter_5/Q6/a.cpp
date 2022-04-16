#include <bits/stdc++.h>
using value_type = double;

int main()
{
    // Create pairs by calling constructors
    std::tuple<int, float> p1;
    std::cout << std::get<0>(p1) << "," << std::get<1>(p1) << '\n'; // 0,0
    std::tuple<int, value_type> p2(65, 2.01f);
    std::cout << std::get<0>(p2) << "," << std::get<1>(p2) << '\n'; // 65, 2.01
    value_type d = 2.2;
    std::complex<value_type> c(1.1, -1.7);
    return 0;
}