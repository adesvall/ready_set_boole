unsigned adder(unsigned a, unsigned b)
{
    while (b != 0) {
        unsigned temp = b;
        b = (a & temp) << 1;
        a ^= temp;
    }
    return a;
}
