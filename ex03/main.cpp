#include "../main.hpp"

void test(string expr)
{
    cout << expr << " => " << eval_formula(expr) << endl;
}

int main()
{
    test("10&");
    test("01&");
    test("11&");
    test("001||");
    test("00|1&");
    test("0!1&!");
    test("0!1!>!");
    test("11&11&=");
}
