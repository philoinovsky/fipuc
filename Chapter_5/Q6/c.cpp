#include <bits/stdc++.h>

class a
{
public:
    a(const std::pair<int, double>& b)
    {
        // 1.
        c = b.first;
        d = b.second;
        // 2.
        std::tie(c, d) = b;
    }

    int c;
    int d;
};

int main()
{
    a aa({1, 2.0});
    std::cout << aa.c << " " << aa.d << std::endl;
    return 0;
}