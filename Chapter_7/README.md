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
12. 
    1. does each module satisfy SRP?
        - no
    2. describe the process of computing the option price
        - source -> sde, sde <- fdm <- rng, sde sends progress to MIS, sde sends results to pricer
    3. which steps/activities have no corresponding modules and which modules have less than or more than one major responsibility.
        - mediate is doing too much
        - source can feed data directly into SDE
    4. For each module determine the services that it provides to and the services that it requires from other modules.
    5. Create a small software prototype in C++ to implement the context diagram in Figure 7.1. The requirements are:
13. Consider the following class hierarchies and Gen/Spec relationships. Which ones are semantically correct, which ones are semantically incorrect and can you model them without the need for class hierarchies (general answers are sufficient)?
    1. Base class Lattice, derived classes BinomialLattice and TrinomialLattice.
        - yes
    2. CallOption and PutOption as derived classes of Option.
        - yes
    3. A Square class that is derived from a Rectangle.
        - yes
    4. PDE class hierarchies. How would you design them?
        - dont know leh
    5. The wisdom of inheriting from template classes.
        - wut?