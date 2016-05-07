#include <iostream>
#include "utility.hpp"
using namespace std;

/*
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which
 * the depth of the two subtrees of every node never differ by more than 1.
 */

int balancedDepth(TreeNode* root){
    if(!root)
        return 0;

    int leftD = balancedDepth(root->left);
    int rightD = balancedDepth(root->right);
    if(leftD >= 0 && rightD >= 0){
        int depth = leftD > rightD ? (leftD-rightD) : (rightD-leftD);
        if(depth > 1) {
            return -1;
        } else {
            return (leftD > rightD ? leftD+1 : rightD+1);
        }
    } else {
        return -1;
    }
}

bool isBalanced(TreeNode* root) {
    if(!root){
        return true;
    }
    int leftD = -1, rightD = -1;
    leftD = balancedDepth(root->left);
    cout << "left depth = " << leftD << endl;
    rightD = balancedDepth(root->right);
    cout << "right depth = " << rightD << endl;
    if(leftD >= 0 && rightD >= 0 && abs(leftD-rightD) <= 1){
        return true;
    }else{
        return false;
    }
}
/*
int main(int argc, char *argv[])
{
    string array[5] = {"1","#","2","#","3"};

    vector<string> vec(array, array+5);
    TreeNode* root = constructBinaryTree(vec);

    cout << isBalanced(root);

}
*/
