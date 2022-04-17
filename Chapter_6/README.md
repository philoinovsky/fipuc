# Types
- is_arithmetic: integrals + floating points
- is_fundamentals: is_arithmetic + void + nullptr_t
- is_scalar: is_arithmetic + pointer + pointer to member + enum + nullptr_t
- is_object: any possibly cv-qualified type - function - reference - void types
- is_compound: array + function + object pointer + function pointer + member object pointer + member function pointer + reference + class + union + enum (including cv-qualified)
# Questions
1. top 2 advantages of type traits:
    - Compile time reflection
    - replacement for subtype polymorphism
2. is_arithmetic is only true for integrals and floating point.
    - false, false, true, false
3. 
    - Which of the following types are of arithmetic type? int, int const, int &, int*, float, float const, float &, float *
        - int, int const, int &, float, float const, float &
    - Consider std::complex<double>. Does it fit into the following composite type categories? is_{fundamental, arithmetic, scalar, object, compound}.
        - false, false, false, true, true
    - In which composite type categories does std::array<>fit? Is it a non-union class type?
        - object + compound
4. Which statements describe a variadic function?
    - Takes a variable number of arguments of specific types.
5. Which of the following statements are true regarding a variadic function?
    - It accepts any number of arguments.
6. This exercise entails determining which type traits functions to use for the following functionality. Having discovered the appropriate functions then create some code with two specific types to show how it works:
    - Is a type either a signed or an unsigned arithmetic type?
        - `is_signed`, `is_unsigned`
    - Make a given integral type signed/unsigned.
        - `make_signed`, `make_unsigned`
    - Obtain the number of dimensions of an array type.
        - use `rank` to get the number of dimensions
        - use `extent<T, n>` to get the length of the Nth dimension
    - Remove/add a pointer from or to a given type.
        - `add_pointer`
    - Remove/add a reference from or to a given type.
        - `add_lvalue_reference`, `add_rvalue_reference`