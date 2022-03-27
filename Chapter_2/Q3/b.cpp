// b. port to unique_ptr
#include <memory>
#include <iostream>

int main()
{
    // Define auto_ptr pointers instead of raw pointers
    std::unique_ptr <double> d(new double (1.0));
    // Dereference
    *d = 2.0;
    // Change ownership of unique_ptr
    // (after assignment, d is undefined)
    std::unique_ptr <double> d2 = std::move(d);
    *d2 = 3.0;
    std::cout << "Auto values: " << *d2.get() << "\n";
    return 0;
}
