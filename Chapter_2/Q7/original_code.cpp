#include <bits/stdc++.h>

// C++03 approach
// Data storage types
template <typename T> struct Storage
{
    // Possible ADTs and their memory allocators
    // typedef std::vector<T, CustomAllocator<T>> type;
    // typedef std::vector<T, std::allocator<T>> type;
    typedef std::list<T, std::allocator<T>> type;
};

template <typename T>
class Client
{ // An example of Composition
private:
    typename Storage<T>::type data; // typename mandatory
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