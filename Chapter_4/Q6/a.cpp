#include <bits/stdc++.h>
#include <type_traits>

template < typename T1, typename T2,
    template <typename TC1, typename TAlloc1> class Container1 =
    std::vector,
    template <typename TC2, typename TAlloc2> class Container2 =
    std::vector,
    typename TAlloc1 = std::allocator<T1>, typename TAlloc2 =
    std::allocator<T2>>
class Algorithms
{ // Wrappers/Composition for STL algorithms
public:
    static auto InnerProduct(const Container1<T1, TAlloc1>& con1,
    const Container2<T2, TAlloc2>& con2, const T1& initVal)
        -> typename std::common_type<T1, T2>::type
    {
        static_assert(std::is_arithmetic<T1>::value);
        static_assert(std::is_arithmetic<T2>::value);
        // Possible preprocessing on T1 and T2
        // Body
        return std::inner_product (std::cbegin(con1),
        std::cend(con1), std::cbegin(con2), initVal);
        // Possible postprocessing on T1 and T2
    }

    static auto InnerProduct_II(const Container1<T1, TAlloc1>& con1,
    const Container2<T2, TAlloc2>& con2, const T1& initVal)
        -> decltype(std::declval<T1>()*std::declval<T2>())
    { // Using decltype and declval
        static_assert(std::is_arithmetic<T1>::value);
        static_assert(std::is_arithmetic<T2>::value);
        // Possible preprocessing on T1 and T2
        // Body
        return std::inner_product (std::begin(con1), std::end(con1),
        std::begin(con2), initVal);
        // Possible postprocessing on T1 and T2
    }
};

int main()
{
    std::cout << Algorithms<double, int, std::list, std::list>::InnerProduct(
        std::list<double>{1,2,3}, std::list<int>{1,2,3}, 0) << std::endl;
    return 0;
}