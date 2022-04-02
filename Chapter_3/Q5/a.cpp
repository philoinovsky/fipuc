// a.bridge pattern
#include <functional>
#include <boost/random.hpp>

using FuncType = std::function<double(double)>;

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

double func(double x) { return x*x*x*x + 1; }
double func2(double x) { return exp(-x); }

class IntegratorImp
{
public:
    IntegratorImp() {}
    virtual double operator() (const FuncType& fun, const Range<double>& range, 
        std::size_t N) = 0;
};

class HitorMissImp: public IntegratorImp
{
public:
    HitorMissImp() {}
    double C = 2.0; // Max value of fun in range
    double operator() (const FuncType& fun, const Range<double>& range, 
        std::size_t N) override
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

class MidpointRule: public IntegratorImp
{
public:
    MidpointRule() {}
    double operator() (const FuncType& fun, const Range<double>& range, 
        std::size_t N) override
    {
        double A = range.low();
        double B = range.high();
        double res = 0.0;
        double h = range.spread() / double(N);
        for (double x = A + (0.5 * h); x < B; x += h)
            res += fun(x);
        return res*h;
    }
};

class NumIntegrator
{
public:
    NumIntegrator() {}
    Range<double> range;
    FuncType fun;
    IntegratorImp* integrator;
    double operator() (size_t N)
    {
        return integrator->operator()(fun, range, N);
    }
};

int main()
{
    NumIntegrator ni;
    ni.range = Range<double>(0.0, 1.0);
    ni.fun = func;
    ni.integrator = new HitorMissImp();
    std::cout << ni(1000) << std::endl;
    return 0;
}