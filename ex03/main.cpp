#include "../main.hpp"

int main()
{
    cout << eval_formula("10&") << endl;
    cout << eval_formula("01&") << endl;
    cout << eval_formula("11&") << endl;
    cout << eval_formula("001||") << endl;
    cout << eval_formula("00|1&") << endl;
    cout << eval_formula("0!1&!") << endl;
    cout << eval_formula("0!1!>!") << endl;
    cout << eval_formula("11&11&=") << endl;
}
