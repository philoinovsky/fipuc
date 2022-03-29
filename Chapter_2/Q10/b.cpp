// b. method to add and remove members
#include <memory>
#include <iostream>
#include <list>
using namespace std;

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
private:
    list<unique_ptr<T>> lup;
};

int main()
{
    example<int> ei;
    unique_ptr<int> up(new int(1));
    ei.add(move(up));
    return 0;
}