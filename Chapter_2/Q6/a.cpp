// a. weak pointer and use_count()
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    double * dp = new double(1);
    shared_ptr<double> sp(dp);
    cout << sp.use_count() << endl;
    weak_ptr<double> wp(sp);
    cout << wp.use_count() << endl;
    return 0;
}