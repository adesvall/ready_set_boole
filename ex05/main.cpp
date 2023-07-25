#include "../main.hpp"

string negation_normal_form(string expr);

void    test(string expr)
{
    string res = negation_normal_form(expr);
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
        test("CD!&!");
        test("AB|!");
        test("AB>");
        test("AB<!");
        test("AB=");
        test("AB=!");
        test("AB^!");
        test("AB&!");
    }
}
