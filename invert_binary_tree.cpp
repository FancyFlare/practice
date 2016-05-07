#include <iostream>
#include <vector>
#include <queue>
#include "utility.hpp"
using namespace std;

/*
 * 226. Invert Binary Tree
 */

TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return NULL;

    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->right = left;
    root->left = right;
    return root;
}
/*
int main(int argc, char *argv[])
{
    string array[7] = {"1","2","3","#","4","5","#"};
    vector<string> vec(array, array+7);
    TreeNode* root = constructBinaryTree(vec);
    root = invertTree(root);
    printBinaryTree(root);

}
*/
