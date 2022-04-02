- Examine the solution from the viewpoints of the ISO 9126 product quality standard. The characteristics of ISO 9126 that we address in this exercise are:
    1. functionality: a set of attributes that bear on the existence of a set of functions and their specified properties. The functions are those that satisfy stated or implied needs.
    2. reliability: a set of attributes that bear on the capability of software to maintain its level of performance under stated conditions for a stated period of time.
    3. efficiency: a set of attributes that bear on the relationship between the level of performance of the software and the amount of resources used, under stated conditions
    4. maintainability: a set of attributes that bear on the effort needed to make specified modifications.
    5. portability: a set of attributes that bear on the ability of software to be transferred from
one environment to another
- Note
    - transformed from Bridge Design Pattern
    - class NumericalIntegrator
        - Function
            - func
            - func2
        - QuadMethod
            - MidpointRule
            - HitorMissMonteCarlo
        - operator (): call the quad scheme as a function object
- A specific use case:
    - The ability of the software to operate with different programming styles.
    - Supporting double and float types.
    - Integrating (possibly incompatible) libraries and code with the current software.
    - Avoiding run-time memory allocation and deallocation.
```
Answer:
1. functionality: bar
2. reliability: bar
3. efficiency: yes, no virtual pointer used
4. maintainability: yes, no need to extend by writing a new class, just new functions will do.
5. portability: bar
```