#include <iostream>

double func(double d)
{
    return d*d;
}

double func()
{ // Return type (an int) convert to double
    int result = 1'000'000;
    return result;
    }

void ImplicitConversions()
{ // Simple examples of conversions
    // Assignment
    int i = 1L; // Convert long to int
    int j = 3.14; // Truncate a double
    // Scalar initialisation
    double d2 = 2.4;
    int i2 = 3;
    double d3 = i2*d2;
    // Function call expression
    int i3 = 5;
    std::cout << func(i3) << '\n';
    // Function return type
    int i4 = func(3.14);
    std::cout << i4 << '\n';
    std::cout << func() << '\n';
}

int main()
{
    ImplicitConversions();
    return 0;
}