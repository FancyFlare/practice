#include <iostream>
#include <cmath>
#include "utility.hpp"
using namespace std;
/*
 * 270. Given a non-empty binary search tree and a target value,
 * find the value in the BST that is closest to the target.
 * Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
 */

int closestValue(TreeNode* root, double target) {
    if(!root){
        return INT_MAX;
    }
    if(root->left == NULL && root->right == NULL){
        return root->val;
    }
    int closest = root->val;
    if(target < root->val && root->left) { //left
        int sub_closest = closestValue(root->left, target);
        if (abs(target-(double)closest) > abs(target-(double)sub_closest)){
            closest = sub_closest;
        }
    }
    if(target > root->val && root->right) { //right
        int sub_closest = closestValue(root->right, target);
        if (abs(target-(double)closest) > abs(target-(double)sub_closest)){
            closest = sub_closest;
        }
    }
    return closest;
}
/*
int main(int argc, char *argv[])
{
    string array[5] = {"3","1","4","#","2"};

    vector<string> vec(array, array+5);
    TreeNode* root = constructBinaryTree(vec);

    cout << closestValue(root, 0.428571);

}
*/
