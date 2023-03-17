unsigned adder(unsigned a, unsigned b);

unsigned multiplier(unsigned a, unsigned b)
{
    unsigned result = 0;
    while (b != 0) {
        if (b & 1)
            result = adder(result, a);
        a <<= 1;
        b >>= 1;
    }
    return result;
}
