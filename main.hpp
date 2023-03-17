#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <list>

using namespace std;

string replace_var(string formula, char *variables, int values);
bool eval_formula(string formula);
void print_truth_table(string formula);
bool check_equivalence(string formula1, string formula2);

#endif
