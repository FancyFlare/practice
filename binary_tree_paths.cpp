#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include "utility.hpp"
using namespace std;

/*
 * 257. Binary Tree Paths: Given a binary tree, return all root-to-leaf paths.
 */

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if(!root)
        return ans;

    stringstream ss;
    ss << root->val;
    string rootStr = ss.str();

    vector<string> subLeft = binaryTreePaths(root->left);
    if(!subLeft.empty()){
        for(int i=0; i< subLeft.size(); i++){
            string newStr = rootStr;
            newStr += "->" + subLeft[i];
            ans.push_back(newStr);
            //cout << "path: " << newStr << endl;
        }
    }

    vector<string> subRight = binaryTreePaths(root->right);
    if(!subRight.empty()){
        for(int i=0; i< subRight.size(); i++){
            string newStr = rootStr;
            newStr += "->" + subRight[i];
            ans.push_back(newStr);
            //cout << "path: " << newStr << endl;
        }
    }

    if(subLeft.empty() && subRight.empty()){
        ans.push_back(rootStr);
    }

    return ans;
}
/*
int main(int argc, char *argv[])
{
    string array[7] = {"1","2","3","#","4","5","#"};
    vector<string> vec(array, array+7);
    TreeNode* root = constructBinaryTree(vec);
    vector<string> result = binaryTreePaths(root);
    for(int i=0; i<result.size(); i++){
        cout << "path: "<< result[i] << endl;
    }
}
*/
