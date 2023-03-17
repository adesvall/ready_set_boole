#include "../main.hpp"

void distribute_disjunction(Node* root)
{
    if (!root)
        return;

    if (root->expr[0] == '|')
    {
        if (root->left->expr[0] == '&')
        {
            // Node *clonel = clone_tree(root->left);
            // Node *cloner = clone_tree(root->left);
            // clear_tree(root->left->left);
            // clear_tree(root->left->right);
            // clonel->expr = "|";
            // cloner->expr = "|";
            // root->expr = "&";
            // root->left->left = clonel;
            // root->left->right = cloner;
        }
        if (root->right->expr[0] == '&')
        {
        }
    }
    distribute_disjunction(root->left);
    distribute_disjunction(root->right);
}

string conj_normal_form(string expr)
{
    if (eval_formula(expr) == -1)   {
        return "ERROR";
    }
    Node* root = expr_to_tree(expr);

    // print_tree(root);
    distribute_negation(root);
    print_tree(root);
    distribute_disjunction(root);
    print_tree(root);
    string res = tree_to_expr(root);
    clear_tree(root);
    return res;
}
