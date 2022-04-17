1. Compare generic lambdas and template functions with regard to reliability, maintainability and understandability
    - reliability: same
    - maintainability: template should be better, because it provides more functionalities
    - understandability: lambdas seem more understandable
2. We can capture by value, by reference, by generalised capture, by local variables and by emulation using std::bind. Give the two best candidates from this list that satisfy the following requirements: maintainability, efficiency, understandability and interoperability with client code.
    - maintainability: Bind binds by name and as a result if you have multiple functions with the same name (overloaded functions) bind doesn't know which one to use. The following example won't compile, while lambdas wouldn't have a problem with it
    - efficiency: When using bind functions are less likely to be inlined
    - understandability: same
    - interoperability: ?
3. How do the techniques in part b) scale to larger and more complex code blocks? In which sense are encapsulation and information hiding potentially compromised (if at all) by the introduction of captured variables?
    - can't imagine
4. As a follow-on to question c), in which circumstances would we prefer to use function objects instead of the other techniques? Would they improve maintainability or efficiency?
    - if it is simple, just use lambda lah
    - complex? use functor lah
5. Is there a need to emulate generalised lambda capture using C++11 and std::bind? Are there potential benefits?
    - why you need this?
6. How would you reimplement the code in Section 6.7.1 using a function object? Would it be a better solution?
    - can, but why? it would be much more messy