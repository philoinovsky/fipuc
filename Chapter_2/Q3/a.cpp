// a. why does it give a run-time error?
// when auto_ptr is copied, the ownership is quietly transferred, which is bad!
#include <memory>
#include <iostream>

using std::auto_ptr;

int main()
{
    // Define auto_ptr pointers instead of raw pointers
    std::auto_ptr <double> d(new double (1.0));
    // Dereference
    *d = 2.0;
    // Change ownership of auto_ptr
    // (after assignment, d is undefined)
    std::auto_ptr <double> d2 = d;
    *d2 = 3.0;
    std::cout << "Auto values: " << *d.get() << ", " << *d2.get() << "\n";
    return 0;
}
