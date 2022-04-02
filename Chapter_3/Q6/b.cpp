// c. innerproduct in lambda and functor
#include <vector>
#include <iostream>

struct innerProduct_ftor
{
    double operator() (std::vector<double> u, std::vector<double> v)
    {
        double sum = 0;
        for (int i = 0; i < u.size(); i++)
            sum += u[i] * v[i];
        return sum;
    }
};

auto innerProduct_lmd = [] (std::vector<double> u, std::vector<double> v) -> double
{
    double sum = 0;
    for (int i = 0; i < u.size(); i++)
        sum += u[i] * v[i];
    return sum;
};

int main()
{
    std::cout << innerProduct_lmd({1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}) << " "
        << innerProduct_ftor()({1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}) << std::endl;
    return 0;
}