// b. method to add and remove members
// output:
// 2 4
// 4 6
// point destroyed
// point destroyed
#include <memory>
#include <iostream>
#include <list>
#include <functional>
using namespace std;

struct Point
{
    double x, y;
    Point() : x(0.0), y(0.0) {}
    Point(double xVal, double yVal) : x(xVal), y(yVal) {}
    void print() const {std::cout << "(" << x << "," << y << ")\n";}
    ~Point() { std::cout << "point destroyed\n"; }
    void X(double x) {this->x = x;}
    void Y(double y) {this->y = y;};
};

template <typename T>
using CommandFunctionType = std::function<void (T& t)>;

template <typename T>
class example
{
public:
    void add(unique_ptr<T>&& element)
    {
        lup.push_back(move(element));
    }

    void remove()
    {
        lup.pop_front();
    }

    void foreach(CommandFunctionType<T> f)
    {
        for (auto& up: lup)
            f(*up);
    }
private:
    list<unique_ptr<T>> lup;
};

using PolyLine = example<Point>;

int main()
{
    PolyLine pl;
    pl.add(unique_ptr<Point>(new Point(1, 2)));
    pl.add(unique_ptr<Point>(new Point(3, 4)));
    pl.foreach([] (Point& p) {
        p.x += 1;
        p.y += 2;
    });
    pl.foreach([] (Point& p) {
        cerr << p.x << " " << p.y << endl;
    });
    return 0;
}