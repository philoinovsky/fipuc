struct B
{
    explicit B(int) {}
    explicit B(int, int) {}
    explicit operator int() const { return 0; }
};

int main()
{
    // B b1 = 1; // error
    B b2(3);
    B b3{ 7,3 };
    B b4 = (B)42;
    return 0;
}