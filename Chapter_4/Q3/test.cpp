#include <iostream>

struct G
{
    int x, y, z;
};

int main()
{
    int a(1), b(2), c(3);
    int d = std::move(b);
    int e = std::move(a ? b : c);
    int f = std::move(5);
    G* g = new G{1, 2, 3};
    g->x = 2;
    (g->x) = 3;
    std::cout << g->x << std::endl;
    return 0;
}