#include <bits/stdc++.h>
#include <boost/integer.hpp>
#include <boost/math/tools/roots.hpp>

// Function that maps a type to a tuple
template <typename T>
using FunctionType = std::function<std::tuple<T,T> (const T& t)>;

// Newton-Raphson, exp(x) = 148.4131591, x = 5
template <typename T>
class NRFunctions
{ // Functions needed for input to NR method
private:
public:
    NRFunctions() {}

    std::tuple<T, T> operator()(const T& x)
    { // x is estimate so far.
        // Return the function and its dervivative.
        return std::make_tuple(std::exp(x) - 148.4131591, std::exp(x));
    }
};

template <typename T>
std::tuple<T, boost::uintmax_t>
NewtonRaphson(const T& L, const T& R, FunctionType<T> func)
{
    using namespace std; // for frexp, ldexp, numeric_limits.
    using namespace boost::math::tools;

    T min = L;;
    T max = R;
    T guess = (L + R)/ 2; // Rough guess
    int digits = std::numeric_limits<T>::digits;
    boost::uintmax_t maxIter = 10;
    T val = boost::math::tools::newton_raphson_iterate
            (func, guess,min, max, digits, maxIter);
    return std::make_tuple(val, maxIter);
}

int main()
{
    double leftBracket = 0.0; double rightBracket = 10.0;
    FunctionType<double> func = NRFunctions<double>();
    auto result = NewtonRaphson(leftBracket, rightBracket, func);
    std::cout << "NR results: " << std::setprecision(8)
            << std::get<0>(result) << ", " << std::get<1>(result) << std::endl;
    return 0;
}