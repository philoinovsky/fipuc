#include <bits/stdc++.h>

template<class InputIt1, class InputIt2, class T>
T inner_product_custom(InputIt1 first1, InputIt1 last1, InputIt2 first2, T value)
{
    T res = value;
    auto c1 = first1;
    auto c2 = first2;
    for (; c1 != last1; c1++, c2++)
        res += *c1 * *c2;
    return res;
}

int main()
{
    std::vector<int> a{1, 2, 3};
    std::list<double> b{1, 2, 3};
    std::cout << inner_product_custom(a.begin(), a.end(), b.begin(), 0) << std::endl;
    return 0;
}

// understandability: surely use container instead of iterators would be more 
//      straightforward
// robustness: same?
// extendibility: use iterators generalizes the format

// introduce parrallelise the code, more convenient with iterators.
// introduce code to reduce round-off errors: not sure.