// a. innerproduct in free function
#include <vector>
#include <iostream>

double innerProduct(std::vector<double> u, std::vector<double> v)
{
    double sum = 0;
    for (int i = 0; i < u.size(); i++)
        sum += u[i] * v[i];
    return sum;
}

int main()
{
    std::cout << innerProduct({1.0, 2.0, 3.0}, {1.0, 2.0, 3.0}) << std::endl;
    return 0;
}