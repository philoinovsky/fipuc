// c. transfer ownership
#include <iostream>
#include <memory>


// double-free
void initialize_two_up_to_the_same_pointer()
{
    double *p = new double(1);
    std::unique_ptr<double> up1(p);
    std::unique_ptr<double> up2(p);
}

// compiling error: move only
void assign_up_to_up()
{
    std::unique_ptr<double> up1 = std::make_unique<double>(1);
    std::unique_ptr<double> up2 = up1;
}

// ok
void transfer_ownership_up()
{
    std::unique_ptr<double> up1 = std::make_unique<double>(1);
    std::unique_ptr<double> up2 = std::move(up1);
}

int main()
{
    initialize_two_up_to_the_same_pointer();
    assign_up_to_up();
    transfer_ownership_up();
    return 0;
}