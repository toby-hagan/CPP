#include <iostream>
#include "TreeNode.h"

using namespace std;
template<typename T>
void print(TreeNode<T>* tree)
{
    if (tree != NULL)
    {
        print(tree->leftTree);
        cout << tree->item << endl;
        print(tree->rightTree);
    }
}

int main1()
{
    TreeNode<char>* d_node = new TreeNode<char>('D');
    TreeNode<char>* e_node = new TreeNode<char>('E');
    TreeNode<char>* b_node = new TreeNode<char>('B', d_node, e_node);
    TreeNode<char>* c_node = new TreeNode<char>('C');
    TreeNode<char>* root_node = new TreeNode<char>('A', b_node, c_node);

    print(root_node);
    delete root_node;
    return 0;
}

template<typename T>
TreeNode<T>* search(T key, TreeNode<T>* tree)
{
    if (tree == NULL) // key not in tree, insert
    {
        tree = new TreeNode<T>(key);
    }
    else if (key < tree->item)
    {
        tree->leftTree = search(key, tree->leftTree);
    }
    else if (key > tree->item)
    {
        tree->rightTree = search(key, tree->rightTree);
    }
    return tree;
}

int main2()
{
    TreeNode<char>* tree = NULL;
    tree = search('L', tree);
    tree = search('X', tree);
    tree = search('J', tree);
    tree = search('P', tree);
    tree = search('R', tree);
    tree = search('B', tree);
    tree = search('W', tree);

    print(tree);
    delete tree;
    return 0;
}

int sumTree(TreeNode<int>* tree, int low, int high)
{
    if (tree == NULL)
        return 0;
    int total = 0;
    if (low < tree->item && tree->item < high)
    {
            total += tree->item;
    }

    return (total + sumTree(tree->leftTree, low, high) + sumTree(tree->rightTree, low, high));
}

int main()
{
    TreeNode<int>* intTree = NULL;
    intTree = search(2, intTree);
    intTree = search(3, intTree);
    intTree = search(4, intTree);
    intTree = search(5, intTree);
    intTree = search(6, intTree);
    intTree = search(7, intTree);
    intTree = search(8, intTree);

    cout << sumTree(intTree, 3, 9) << endl;
    delete intTree;
    return 0;
}