#include <iostream>
#include <memory>
using namespace std;

template<typename T>
void count(T&& sp)
{
    cout << sp.use_count() << endl;
};

void create_sp_from_sp()
{
    shared_ptr<double> sp1(new double(1));
    count(sp1); // 1
    shared_ptr<double> sp2 = move(sp1);
    count(sp2); // 1
}

void create_sp_from_up()
{
    unique_ptr<double> up(new double(1));
    shared_ptr<double> sp = move(up);
    count(sp); // 1
}

int main()
{
    create_sp_from_sp();
    create_sp_from_up();
    return 0;
}