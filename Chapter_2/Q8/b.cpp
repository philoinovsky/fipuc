// b. swap ups and sps
#include <iostream>
#include <memory>
using namespace std;

template<typename T>
void count(T&& sp)
{
    cout << sp.use_count() << endl;
};

void swap_sp()
{
    shared_ptr<double> sp1(new double(1));
    shared_ptr<double> sp2(new double(2));
    swap(sp1, sp2);
    count(sp1); // 1
    count(sp2); // 1
    cout << *sp1 << " " << *sp2 << endl; // 2 1
}

void swap_up()
{
    unique_ptr<double> up1(new double(1));
    unique_ptr<double> up2(new double(2));
    swap(up1, up2);
    cout << *up1 << " " << *up2 << endl; // 2 1
}

int main()
{
    swap_sp();
    swap_up();
    return 0;
}