#include <bits/stdc++.h>
using namespace std;
using nano_s = std::chrono::nanoseconds;

const int NUM = 10000000;

template <typename T>
void SwapCopyStyle(T& a, T& b)
{ // Swap a and b in copying way; temporary object needed
    T tmp(a); // Copy constructor
    a = b; // Copy all elements from b to a
    b = tmp; // Copy all elements from tmp to b
}

template <typename T>
void SwapMoveStyle(T& a, T& b)
{ // Swap a and b in copying way; temporary object needed
    T tmp = move(a); // Copy constructor
    a = move(b); // Copy all elements from b to a
    b = move(tmp); // Copy all elements from tmp to b
}

int main()
{
    vector<int> vi(NUM), vii(NUM);
    for (int i = 0; i < NUM; i++)
    {
        vi[i] = i;
        vii[i] = NUM - i;
    }
    auto t1 = chrono::steady_clock::now();
    SwapCopyStyle(vi, vii);
    auto t2 = chrono::steady_clock::now();
    SwapMoveStyle(vi, vii);
    auto t3 = chrono::steady_clock::now();

    auto d_nano_copy = chrono::duration_cast<nano_s>(t2 - t1).count();
    auto d_nano_move = chrono::duration_cast<nano_s>(t3 - t2).count();

    cout << "copy costs " << d_nano_copy << " ns\nmove costs " <<
        d_nano_move << " ns" << endl;
    return 0;
}
