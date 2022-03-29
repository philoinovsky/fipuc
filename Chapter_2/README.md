# Chapter 2: New and Imptoved C++ Fundamentals
## Takeaways
- Q5: custom deleter
    - types: free function, lambda, functor
    - how to indicate the type of free function?
        - `unique_ptr<FILE, decltype(fclose)> up(fp, &fclose);`
    - `make_unique` and `make_shared` can't be passed deleter to    
- Q10.b:
    - two ways to use `unique_ptr container`:
        1. `void add(unique_ptr<T>&& element)`, then `lup.push_back(move(element));`
        2. `void add(unique_ptr<T>& element)`, then `lup.push_back(move(element));`
        - which do you think is better?
            - advantage of 1: clearer interface
            - advantage of 2: less move, more concise underlying
- Q10.d: easy `foreach` function
    - interesting, use below for functor-for-all
```
template <typename T>
    using CommandFunctionType = std::function<void (T& t)>;
```

