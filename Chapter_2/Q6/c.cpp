// c
#include <iostream>
#include <memory>
using namespace std;

void assign_wp_to_wp()
{
    double * dp = new double(1);
    shared_ptr<double> sp(dp);
    weak_ptr<double> wp(sp);
    weak_ptr<double> wp2(wp);
    cout << sp.use_count() << endl;
}

void assign_wp_to_sp()
{
    double * dp = new double(1);
    shared_ptr<double> sp(dp);
    weak_ptr<double> wp(sp);
    shared_ptr<double> sp2(wp);
    cout << sp.use_count() << endl;
}

int main()
{
    assign_wp_to_wp();
    assign_wp_to_sp();
    return 0;
}