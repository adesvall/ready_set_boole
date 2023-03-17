#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Node
{
    string  expr;
    Node*   left;
    Node*   right;
};

bool isoper(char c);
string replace_var(string formula, char *variables, int values);
int eval_formula(string formula);
void print_truth_table(string formula);
bool check_equivalence(string formula1, string formula2);

Node *expr_to_tree(string formula);
string tree_to_expr(Node* root);
Node *clone_tree(Node *root);
void distribute_negation(Node* root);
void print_tree(Node* root, int depth);
void clear_tree(Node *root);



#endif
