#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{1,2,3,4,5,6,7};
    auto vv = move(v);
    for (auto i: vv)
        cout << i;
    cout << endl;
    return 0;
}