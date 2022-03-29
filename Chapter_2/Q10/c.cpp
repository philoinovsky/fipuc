// c. function
#include <memory>
#include <iostream>
#include <list>
#include <functional>
using namespace std;

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
        {
            f(*up);
        }
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