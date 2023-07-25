#include "../main.hpp"

string conj_normal_form(string expr);

void    test(string expr)
{
    string res = conj_normal_form(expr);
    cout << expr << "\t -> " << res << "\t" << (check_equivalence(expr, res)? "OK!" : "NOOOOPE!") << endl;
}

int main(int ac, char** argv)
{
    if (ac > 1)     {
        test(argv[1]);
        return 0;
    }
    else
    {
        test("AB&!");
        // A!B!|
        test("AB|!");
        // A!B!&
        test("AB|C&");
        // AB|C&
        test("AB|C|D|");
        // ABCD|||
        test("AB&C&D&");
        // ABCD&&&
        test("AB&!C!|");
        // A!B!C!||
        test("AB|!C!&");
    }
}
