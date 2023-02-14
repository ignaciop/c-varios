#include <iostream>

using namespace std;

int main() {
    double yard_length, tree_radius, required_space;

    cout << "Enter the length of the yard: ";
    cin >> yard_length;

    cout << "Enter the radius of a fully grown tree: ";
    cin >> tree_radius;

    cout << "Enter the required space between fully grown trees: ";
    cin >> required_space;

    double tree_spacing = tree_radius * 2 + required_space;
    int num_trees = (yard_length - tree_radius) / tree_spacing;

    double total_space = num_trees * (tree_radius * 2 + required_space);
    
    cout << "Number of trees that can be planted: " << num_trees << endl;
    cout << "Total space occupied by fully grown trees: " << total_space << endl;

    return 0;
}
