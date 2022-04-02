#include <bits/stdc++.h>
using namespace std;

using FuncType = function<void (double)>;

void functionNotDefined()
{
    try
    {
        FuncType fun;
        fun(2.0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n'; // bad_function_call
    }
}

void defineWrongInput()
{
    FuncType fun = [] (string s) {}; // compile error
    fun(2.0);
}

int main()
{
    functionNotDefined();
    defineWrongInput();
    return 0;
}