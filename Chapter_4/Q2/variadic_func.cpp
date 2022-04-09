#include <stdarg.h>
#include <math.h>
#include <iostream>

void computeMeanAndSTD(int count, ...)
{
    double mean(0), stdv(0);
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
        mean += va_arg(args, double);
    mean /= count;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        double n = va_arg(args, double);
        stdv += (n - mean) * (n - mean);
    }
    stdv = sqrt(stdv/count);
    std::cout << "mean: " << mean << std::endl << "std: " << stdv << std::endl;
    
}

int main()
{
    computeMeanAndSTD(1, 1.0);
    computeMeanAndSTD(5, 4.5, 6.5, 1.2, 4.0, 2.8);
    return 0;
}