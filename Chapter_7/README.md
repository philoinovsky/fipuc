2. Which of the following statements are advantages of using deleted functions compared to declaring these functions as private as in the C++98 standard?
    - Making deleted functions public results in better error messages in general
4. Which of the following statements are true?
    - constexpr applies to both objects and functions.
    - The output from a constexpr function will be known at compile-time if its input arguments are known at compile-time.
    - constexpr functions need not necessarily produce values that are known at compiletim
5. why the following member function of class `Print` does not compile?
    - wtf. it does compile
    - furthermore, does the following code compile?
        - no, can't change `constexpr` object
6. Which two (most important) symptoms in your opinion can manifest themselves if a class does not satisfy SRP? (not sure)
    -  Class hierarchy nesting level (depth of inheritance hierarchy) (threshold value ∼ 6)
    - The number of methods in a class increases (threshold value ∼ 12)
7. what is the `fragile base class problem`
    - A base class which when modified can cause derived classes to malfunction
8. How can the Fragile Base Class Problem be resolved?
    - Making some base class methods final in order to preserve integrity
9. Give the top three risks associated with deep inheritance hierarchies
    - They become increasingly difficult to maintain.
    - Many developers create class hierarchies based on structure and not on behaviour.
    - Performance degradation as the depth of the hierarchy increases.
10. Which choice for modelling functions results in the most flexible software?
    - Universal function wrapper.
11. How can you identify code (in general terms) that is not using Whole–Part? (not sure)
    - Classes tend to have relatively many data members.