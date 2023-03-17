#include "../main.hpp"

int main()
{
    print_truth_table("AB&");
    print_truth_table("AB&C&");
    print_truth_table("AB&C|");
    print_truth_table("AB&!C^");
    print_truth_table("AB!|A!B|&");
}
