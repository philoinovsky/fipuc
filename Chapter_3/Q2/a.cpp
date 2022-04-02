// a. write point class
// output:
// Taximan C and D points: 2
// Taximan D and C points: 2
#include <math.h>
#include <iostream>
#include <functional>

template <typename T>
struct Point
{
    using FuncType = std::function<T (const Point<double>&, const Point<double>&)>;
    T x, y;
    FuncType fun;
    Point(T xVal, T yVal, FuncType fun): x(xVal), y(yVal), fun(fun) {}
    T First() const {return x;}
    T Second() const {return y;}
    T Distance(const Point<T>& point) const { return fun(*this, point); }
};

// Library adapter
double Taximan3D(double x1, double y1, double z1,
            double x2, double y2, double z2)
{ // Distance between two points in 3d taxi space
    return std::abs(x1 - x2) + std::abs(y1 - y2) + std::abs(z1 - z2);
}

std::function<double (double x1,double y1,double x2,double y2)>
Taximan2D =
    std::bind(Taximan3D, std::placeholders::_1,
    std::placeholders::_2,0.0, std::placeholders::_3, std::placeholders::_4,0.0);

struct Taximan
{ // The scenic route(aka expensive way) from A to B.
    Taximan() {}
    double operator ()(const Point<double>& p,
        const Point<double>& p2) const
    {
        // For readability
        double x1 = p.First(); double x2 = p2.First();
        double y1 = p.Second(); double y2 = p2.Second();
        double result = Taximan2D(x1, y1, x2, y2);
        return result;
    }
};

int main()
{
    Taximan myTaxi;
    Point<double> pC(1.0, 1.0, myTaxi);
    Point<double> pD(2.0, 2.0, myTaxi);
    std::cout << "Taximan C and D points: " << pC.Distance(pD) << std::endl;
    std::cout << "Taximan D and C points: " << pD.Distance(pC) << std::endl;
    return 0;
}