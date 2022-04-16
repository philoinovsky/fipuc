//  Now consider the use case in which a single vector is created and modified 
// one million times. How would you modify the code of compute()and improve the
// run-time performance?
#include <bits/stdc++.h>

std::vector<double> compute(std::vector<double>& v)
{ // Re-seed uniform generator when requesting a new path
    uniformGenerator.seed(seeder());
    std::transform(v.begin(), v.end(), v.begin(), normalGenerator);
    return v;
}

int main()
{
    return 0;
}