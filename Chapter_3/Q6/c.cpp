// c. generalize the code
#include <vector>
#include <iostream>
#include <functional>
#include <math.h>

using vectorFuncType = std::function<double(std::vector<double>, std::vector<double>)>;

double innerProduct(std::vector<double> u, std::vector<double> v)
{
    double sum = 0;
    for (int i = 0; i < u.size(); i++)
        sum += u[i] * v[i];
    return sum;
}

double l1_dis(std::vector<double> u, std::vector<double> v)
{
    double sum = 0;
    for (int i = 0; i < u.size(); i++)
        sum += std::abs(u[i] - v[i]);
    return sum;
}

double l2_dis(std::vector<double> u, std::vector<double> v)
{
    double sum = 0;
    for (int i = 0; i < u.size(); i++)
        sum += std::abs(u[i] - v[i]) * std::abs(u[i] - v[i]);
    return std::sqrt(sum);
}

double linf_dis(std::vector<double> u, std::vector<double> v)
{
    double max = 0;
    for (int i = 0; i < u.size(); i++)
        max = std::max(max, std::abs(u[i] - v[i]));
    return max;
}

struct Distancer
{
    Distancer() {}
    vectorFuncType fun;
};


int main()
{
    Distancer distancer;
    distancer.fun = innerProduct;
    std::cout << distancer.fun({1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}) << std::endl;
    distancer.fun = l1_dis;
    std::cout << distancer.fun({1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}) << std::endl;
    distancer.fun = l2_dis;
    std::cout << distancer.fun({1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}) << std::endl;
    distancer.fun = linf_dis;
    std::cout << distancer.fun({1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}) << std::endl;

    return 0;
}