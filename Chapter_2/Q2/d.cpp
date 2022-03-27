// d
#include <iostream>
#include <memory>
#include <cstdlib>
#include <assert.h>

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

void transfer_ownership()
{
    std::shared_ptr<Point> sp1(new Point(1, 3));
    auto sp2 = std::move(sp1);
    assert(sp2.use_count() == 1);
    assert(sp1.use_count() == 0);
    return;
}

void is_only_owner()
{
    std::shared_ptr<Point> sp1(new Point(1, 3));
    assert(sp1.use_count() == 1L);
    return;
}

void swap_ownership()
{
    std::shared_ptr<Point> sp1(new Point(1, 3));
    std::shared_ptr<Point> sp2(new Point(2, 3));
    std::swap(sp1, sp2);
    assert(sp1->x == 2 && sp2->x == 1);
    return;
}

void give_up_ownership()
{
    std::shared_ptr<Point> sp1(new Point(1, 3));
    sp1.reset();
    assert(sp1.use_count() == 0);
    return;
}

int main()
{
    transfer_ownership();
    is_only_owner();
    swap_ownership();
    give_up_ownership();
    return 0;
}