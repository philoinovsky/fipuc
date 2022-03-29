#include <bits/stdc++.h>

template <typename T>
using Storage_t = std::list<T, std::allocator<T>>;

template <typename T>
class Client
{ // An example of Composition
private:
    Storage_t<T> data;
public:
    Client(int n, const T& val) : data(n, val) {}

    void print() const
    {
        std::for_each(data.begin(), data.end(),
            [] (const T& n) {std::cout << n << ","; });
        std::cout << '\n';
    }
};

int main()
{
    // Client of storage using typedef
    int n = 10; int val = 2;
    Client<int> myClient(n, val);
    myClient.print();
    return 0;
}