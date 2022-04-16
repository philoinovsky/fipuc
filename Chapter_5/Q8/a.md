```
std::vector<double> compute()
{ // Re-seed uniform generator when requesting a new path
    uniformGenerator.seed(seeder());
    std::vector<double> v(nSteps);
    std::transform(v.begin(), v.end(), v.begin(), normalGenerator);
    return v;
}
```
- how many temp vectors are created when this function is called from client code.
    - 1