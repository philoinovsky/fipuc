// c. use user-defined data structure instead of double
#include <iostream>
#include <memory>

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

class C1
{
private:
    std::shared_ptr<Point> d;
public:
    C1(std::shared_ptr<Point> value) : d(value) {}
    virtual ~C1() { std::cout << "\nC1 destructor\n";}
    void print() const { std::cout << "Value " << d->x << " " << d->y; }
};

class C2
{
private:
    std::shared_ptr<Point> d;
public:
    C2(std::shared_ptr<Point> value) : d(value) {}
    virtual ~C2() { std::cout << "\nC2 destructor\n";}
    void print() const { std::cout << "Value " << d->x << " " << d->y; }
};

void program()
{
    std::shared_ptr<Point> sp(new Point(1, 2));
    C1 c1(sp);
    C2 c2(sp);
    std::cout << sp.use_count() << std::endl; // 3
    return;
}

int main()
{
    program();
    return 0;
}