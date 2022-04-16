#include <bits/stdc++.h>
using value_type = double;

int main()
{
    std::tuple<int, std::string> p1{1, "a"}, p2{2, "b"};
    std::cout << (p1 < p2) << std::endl;    
    return 0;
}