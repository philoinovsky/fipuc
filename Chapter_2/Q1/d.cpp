// d. alias template
// output:
// crashed
// 0x55c88fe1ced0
//  point destroyed
#include <iostream>
#include <memory>

// here you go
template<typename T>
using UP = std::unique_ptr<T>;

struct Point
{
    double x, y;
    Point() : x(0.0), y(0.0) {}
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}
    void print() const {std::cout << "(" << x << "," << y << ")\n";}
    ~Point() { std::cout << " point destroyed\n"; }
    void X(double x) {this->x = x;}
    void Y(double y) {this->y = y;};
};

void lifecycle()
{
    // Block with raw pointer lifecycle
    UP<double> d = std::make_unique<double>(1.0);
    UP<Point> pt = std::make_unique<Point>(1.0, 2.0); // Two-d Point class
    try
    {
        // Dereference and call member functions
        *d = 2.0;
        (*pt).X(3.0); // Modify x coordinate
        (*pt).Y(3.0); // Modify y coordinate
        // Can use operators for pointer operations
        pt->X(3.0); // Modify x coordinate
        pt->Y(3.0); // Modify y coordinate
        // Explicitly clean up memory (if you have not forgotten)
        throw 1;
    }
    catch(int& n)
    {
        std::cerr << "crashed" << std::endl;
        std::cout << pt.get() << std::endl;
    }
}

int main()
{
    lifecycle();
    return 0;
}