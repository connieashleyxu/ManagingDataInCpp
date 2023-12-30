// TwoConnieXu.cpp
// lab match lists
// Connie Xu

/*
*resubmitted to accomodate the info added later in the assignment*

ANSWER

Two Lists
in both trees = 29727
tree1...
left side = 3609
right side = 27581
total = 31190
tree2...
left side = 3609
right side = 27581
total = 31190

*/

#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

// binary search tree node
struct Node
{
    int data;
    Node *left;
    Node *right;
    int count; // number of times data appears in file2
    Node(int val) : data(val), left(nullptr), right(nullptr), count(0) {}
};

// insert unique data into the binary search tree
Node *insert(Node *root, int data)
{
    if (!root)
    {
        return new Node(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// search for data in the binary search tree and update count
void searchAndUpdate(Node *root, int data, unordered_map<int, int> &uniqueNumbers)
{
    if (!root)
    {
        return;
    }

    if (data < root->data)
    {
        searchAndUpdate(root->left, data, uniqueNumbers);
    }
    else if (data > root->data)
    {
        searchAndUpdate(root->right, data, uniqueNumbers);
    }
    else
    {
        uniqueNumbers[data]++;
    }
}

void countNodes(Node *root, int &count)
{
    if (root)
    {
        countNodes(root->left, count);
        countNodes(root->right, count);
        count++;
    }
}

void printTreeStats(Node *root, const string &treeName)
{
    int leftCount = 0;
    int rightCount = 0;

    countNodes(root->left, leftCount);
    countNodes(root->right, rightCount);

    int total = leftCount + rightCount + root->count;

    cout << treeName << "..." << endl;
    cout << "left side = " << leftCount << endl;
    cout << "right side = " << rightCount << endl;
    cout << "total = " << total << endl;
}

int main()
{
    Node *root = nullptr;
    unordered_map<int, int> uniqueNumbers;

    ifstream file1("input/file1.txt");
    if (!file1.is_open())
    {
        cerr << "Error opening file1.txt" << endl;
        return 1; // !! added in error for file
    }

    int number;
    while (file1 >> number)
    {
        root = insert(root, number);
    }
    file1.close();

    ifstream file2("input/file2.txt");
    if (!file2.is_open())
    {
        cerr << "Error opening file2.txt" << endl;
        return 1; // !! added in error for file
    }

    while (file2 >> number)
    {
        searchAndUpdate(root, number, uniqueNumbers);
    }
    file2.close();

    int intersectionCount = 0;
    for (const auto &pair : uniqueNumbers)
    {
        if (pair.second > 0)
        {
            intersectionCount++;
        }
    }

    cout << "Two Lists\nin both trees = " << intersectionCount << endl;

    // tree statistics
    printTreeStats(root, "tree1");
    printTreeStats(root, "tree2");

    return 0;
}