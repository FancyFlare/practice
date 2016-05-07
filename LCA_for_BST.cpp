#include <iostream>
#include <vector>
#include <queue>
#include "utility.hpp"
using namespace std;
/*
 * 235. Lowest Common Ancestor of a Binary Search Tree
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 * According to the definition of LCA on Wikipedia:
 * "The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 */

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || !p || !q)
        return NULL;

    if(q->val < p->val){
        TreeNode *t = p;
        p = q;
        q = t;
    }
    while(root){
        if(root == p || root == q || root->val == p->val || root->val == q->val){
            return root;
        }
        if(p->val < root->val && q->val < root->val){
            root = root->left;
        }else if(p->val > root->val && q->val > root->val){
            root = root->right;
        }else if(p->val < root->val && q->val > root->val){
            return root;
        }
    }
}
/*
int main(int argc, char *argv[])
{
    string array[11] = {"6","2","8","0","4","7","9","#","#","3","5"};

    vector<string> vec(array, array+11);
    TreeNode* root = constructBinaryTree(vec);
    TreeNode* p = root->left->right->left;
    TreeNode* q = root->left->right->right;
    cout << "p->val=" << p->val << endl;
    cout << "q->val=" << q->val << endl;
    cout << lowestCommonAncestor(root, p, q)->val;

}
*/
