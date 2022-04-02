// c. implement the `trapezoidal rule` TrapezoidalRule
#include <math.h>
#include <functional>
#include <iostream>
#include <boost/random.hpp>

template <typename T>
struct Range
{
    T l, h;
    Range () {}
    Range (T l, T h) : l(l), h(h) {}
    T high() const { return h; }
    T low() const { return l; }
    T spread() const { return h - l; }
};

// Define interfaces
typedef std::function<double (double)> Function;
typedef std::function<double (const Function& fun,
    const Range<double>& range, std::size_t N)> QuadMethod;

class NumericalIntegrator
{
public: // Convenience only
    NumericalIntegrator() {}
    Function fun;
    Range<double> ran;
    QuadMethod quad;
    // Call the quad scheme as a function object
    double operator () (std::size_t N) { return quad(fun, ran, N);}
};

// Test data
double func(double x) { return x*x*x*x + 1; }
double func2(double x) { return exp(-x); }

// Q3.a
double TrapezoidalRule(const Function& fun, const Range<double>& range, 
    std::size_t _)
{
    return range.spread() / 2 * (fun(range.low()) + fun(range.high()));
}

double MidpointRule(const Function& fun, const Range<double>& range, std::size_t N)
{ // Global C function (based on Duffy 2004)
    double A = range.low();
    double B = range.high();
    double res = 0.0;
    double h = range.spread() / double(N);
    for (double x = A + (0.5 * h); x < B; x += h)
        res += fun(x);
    return res*h;
}

struct HitorMissMonteCarlo
{ // Based on Duffy and Kienitz 2009
    double C; // Max value of fun in range
    double operator()(const Function& fun, const Range<double>& range, std::size_t N)
    {
        double A = range.low();
        double B = range.high();
        double d = B - A;
        double V = C * d; // Volume of bounding box
        // A. Define the lagged Fibonacci and Normal objects
        boost::lagged_fibonacci607 rng;
        rng.seed(static_cast<boost::uint32_t> (std::time(0)));
        boost::uniform_real<> uni(A, B);
        boost::variate_generator<boost::lagged_fibonacci607&,
        boost::uniform_real<> > uniRng(rng, uni);
        long NH = 0; // Number of hits
        double tmp1;
        double tmp2;
        for (long j = 1; j <= N; ++j)
        {
            tmp1 = uniRng(); tmp2 = uniRng();
            if (fun(tmp1) > C*tmp2) // Then the point falls inside the curve f(x)
                NH++;
        }
        return V * double (NH) / double (N);
    }
};

int main()
{
    NumericalIntegrator myQuad;
    myQuad.fun = func;
    myQuad.ran = Range<double>(0.0, 1.0);
    // Integrator is midpoint rule
    myQuad.quad = MidpointRule;
    std::size_t N = 1000;
    std::cout << "Approx integral (Midpoint): " << myQuad(N) << std::endl;
    // Integrator is Monte Carlo 'dart throwing'
    HitorMissMonteCarlo mc;
    mc.C = 2.0;
    myQuad.quad = mc;
    N = 1000000;
    std::cout << "Approx integral (MC): " << myQuad(N) << std::endl;
    // Nasty functions
    myQuad.fun = func2;
    mc.C = func2(1.0);
    N = 1000000;
    std::cout << "Approx integral (MC): " << myQuad(N) << ", exact: "
    << -exp(-1.0) + 1.0 << std::endl;
    myQuad.quad = MidpointRule;
    N = 1000;
    std::cout << "Approx integral (Midpoint): " << myQuad(N) << std::endl;
    myQuad.quad = TrapezoidalRule;
    std::cout << "Approx integral (Trapezoidal): " << myQuad(N) << std::endl;
    return 0;
}