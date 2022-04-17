// is shared_ptr of pointer type?
// no, you should call .get()
#include <bits/stdc++.h>

template <typename T>
void IsPointer(const T& t)
{ // First example of type_traits;check if t is a pointer
    // Return type is std::true_type or std::false_type
    if (std::is_pointer<T>::value)
        std::cout << "This is a pointer type argument\n";
    else
        std::cout << "_not_ a pointer type argument\n";
}

int main()
{
    IsPointer(std::shared_ptr<int>());
    return 0;
}