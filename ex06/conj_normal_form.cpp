#include "../main.hpp"

// A | (B & C) -> (A | B) & (A | C)
// (A & B) | (C & D) -> ((A & B) | C) & ((A & B) | D)
void distribute_disjunction(Node* root)
{
    if (!root)
        return;

    // A | (B & C) -> (A | B) & (A | C)
    if (root->expr[0] == '|')
    {
        if (root->left->expr[0] == '&')
        {
            Node *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        if (root->right->expr[0] == '&')
        {
            Node *A = root->left;
            Node *Aclone = clone_tree(A);

            root->expr = "&";
            root->left = new Node();
            root->left->expr = "|";
            root->left->left = A;
            root->left->right = root->right->left;

            root->right->expr = "|";
            root->right->left = Aclone;
        }
    }

    distribute_disjunction(root->left);
    distribute_disjunction(root->right);

    char curr_op = root->expr[0];
    if (isoper(curr_op) && root->left->expr[0] == curr_op)
    {
        // rotate if &&&
        if (root->right->expr[0] == curr_op)
        {
            Node* lastright = root->right;
            root->right = root->left;
            root->left = root->right->left;
            root->right->left = root->right->right;
            root->right->right = lastright;
        }
        else
        {
            Node *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
    }

}

string conj_normal_form(string expr)
{
    if (eval_formula(expr) == -1)   {
        return "ERROR";
    }
    Node* root = expr_to_tree(expr);

    // print_tree(root);
    distribute_negation(root);
    // print_tree(root);
    distribute_disjunction(root);
    // print_tree(root);
    string res = tree_to_expr(root);
    clear_tree(root);
    return res;
}
