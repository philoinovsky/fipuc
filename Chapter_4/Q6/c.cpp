// c. support heterogeneous data for below code
// // Using two predefined function objects using inner and outer
// // operations
// std::vector<int> vecInt{ 1, 2, 3, 4};
// int ip2 = std::inner_product(
//     std::begin(vecInt), std::end(vecInt),
//     std::begin(vecInt), 1, std::multiplies<int>(), // inner
//     std::plus<int>()); // outer
// std::cout << "Inner product2: " << ip2 <<std::endl;
#include <vector>
#include <list>
#include <iostream>

template<class Iter1, class Iter2, class Inner, class Outer, class T>
T inner_product(Iter1 first1, Iter1 last1, Iter2 first2, T init_val,
    Inner inner_op, Outer outer_op)
{
    T res = init_val;
    for (; first1 != last1; first1++, first2++)
        res = outer_op(res, inner_op(*first1, *first2));
    return res;
}

int main()
{
    std::vector<int> a{1, 2, 3};
    std::vector<double> b{1, 2, 3};
    std::cout << inner_product(a.begin(), a.end(), b.begin(), 0,
        std::multiplies<double>(), std::plus<double>()) << std::endl;
    std::cout << inner_product(a.begin(), a.end(), b.begin(), 1,
        std::plus<double>(), std::multiplies<double>()) << std::endl;
    return 0;
}