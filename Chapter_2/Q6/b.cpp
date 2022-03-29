// b. weak pointer not empty
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    double * dp = new double(1);
    shared_ptr<double> sp(dp);
    weak_ptr<double> wp;
    cout << wp.expired() << endl;
    wp = sp;
    cout << wp.expired() << endl;
    return 0;
}