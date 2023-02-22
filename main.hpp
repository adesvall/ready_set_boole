#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>

std::string replace_var(std::string formula, char *variables, int values);
bool eval_formula(std::string formula);
void print_truth_table(std::string formula);
bool check_equivalence(std::string formula1, std::string formula2);

#endif
