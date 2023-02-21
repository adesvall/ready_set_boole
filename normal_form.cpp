#include <string>
#include <list>
#include <iostream>

using namespace std;

struct Node
{
    string  expr;
    Node*   left;
    Node*   right;
};

string tree_to_expr(Node* root)
{
    string res;

    if (!root)
        return res;
    res += tree_to_expr(root->left);
    res += tree_to_expr(root->right);
    res += root->expr;
    return res;
}

Node *expr_to_tree(string formula)
{
    list<Node*> stack;

    for (char c : formula)
    {
        if (c >= 'A' && c <= 'Z')   {
            stack.push_back(new Node());
            stack.back()->expr = c;
        }
        else if (c == '!')  {
            stack.back()->expr += '!';
        }
        else
        {
            Node *n = new Node();
            n->expr = c;
            n->right = stack.back();
            stack.pop_back();
            n->left = stack.back();
            stack.back() = n;
        }
    }
    return stack.back();
}

void clear_tree(Node *root)
{
    if (!root)
        return;
    clear_tree(root->left);
    clear_tree(root->right);
    delete root;    
}

void    print_tree(Node* root, int depth = 0)
{
    if (!root)  {
        return;
    }
    print_tree(root->left, depth+1);
    for (int i = 0; i<depth; i++)
        printf("    ");
    printf("%s\n", root->expr.c_str());
    print_tree(root->right, depth+1);
}

bool isoper(char c)
{
    return string("&|<>=^").find(c) != string::npos;
}

char opposite(char op)
{
    if (op == '&')
        return '|';
    if (op == '|')
        return '&';
    if (op == '=')
        return '^';
    if (op == '^')
        return '=';
    return op;
}

/*
!(a => b) == !(!a ou b) == (a et !b)
contraposée : (a => b) == (!b => !a)
!(!b => !a) == !(b ou !a) == (!b et a)
*/

void distribute_negation(Node* root)
{
    if (!root)
        return;
    while (root->expr.size() > 2 && root->expr.substr(root->expr.size() - 2, 2) == "!!")
        root->expr.resize(root->expr.size() - 2);
    if (root->expr.back() == '!' && isoper(root->expr[0]))
    {
        root->expr.resize(root->expr.size() - 1);
        root->expr[0] = opposite(root->expr[0]);
        // traiter les opearateurs = ^ et <, on en veut plus
        if (root->expr[0] == '>')
            root->expr[0] = '&';
        else
            root->left->expr += '!';
        root->right->expr += '!';

    }
    distribute_negation(root->left);
    distribute_negation(root->right);
}

string negation_normal_form(string expr)
{
    Node* root = expr_to_tree(expr);

    // print_tree(root);
    distribute_negation(root);
    // print_tree(root);
    string res = tree_to_expr(root);
    clear_tree(root);
    return res;
}

int main(int ac, char** argv)
{
    if (ac > 1)
        cout << negation_normal_form(argv[1]) << endl;
    cout << negation_normal_form("CD!&!") << endl;
    cout << negation_normal_form("AB|!") << endl;
    cout << negation_normal_form("AB>!") << endl;
    cout << negation_normal_form("AB=!") << endl;
    cout << negation_normal_form("AB^!") << endl;

    
}
