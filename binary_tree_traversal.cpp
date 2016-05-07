#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>
#include "utility.hpp"
using namespace std;
/*
 * 144. 102. 94. 297
 */

vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> nodeStack;
    vector<int> ret;
    if(!root)
        return ret;

    while(root || nodeStack.size()){
        while(root){
            nodeStack.push(root);
            ret.push_back(root->val);
            root = root->left;
        }
        if(nodeStack.size()){
            root = nodeStack.top();
            nodeStack.pop();
            root = root->right;
        }
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> nodeStack;
    vector<int> ret;
    if(!root)
        return ret;

    while(root || nodeStack.size()){
        while(root){
            nodeStack.push(root);
            root = root->left;
        }
        if(nodeStack.size()){
            root = nodeStack.top();
            nodeStack.pop();
            ret.push_back(root->val);
            root = root->right;
        }
    }
}

vector<vector<int> > levelOrder(TreeNode* root) {
    queue<TreeNode*> nodeQueue;
    vector<vector<int> > ret;
    if(!root)
        return ret;

    //first push the root of the tree to the queue, use 'NULL' as the end of a level
    nodeQueue.push(root);
    nodeQueue.push(NULL);

    while(nodeQueue.size()){
        vector<int> level;
        while (nodeQueue.front() != NULL){
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();
            level.push_back(node->val);
            if(node->left)
                nodeQueue.push(node->left);
            if(node->right)
                nodeQueue.push(node->right);
        }
        ret.push_back(level);
        nodeQueue.pop();
        if(nodeQueue.size()){
            nodeQueue.push(NULL);
        }
    }
    return ret;
}
//297. Serialize and Deserialize Binary Tree
// Encodes a tree to a single string like: 1,2,#,4
string serialize(TreeNode* root) {
    if(!root)
        return "";
    queue<TreeNode*> nodeQueue;
    stringstream ss;
    nodeQueue.push(root);
    while(nodeQueue.size()){
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        if(node == NULL){
            ss << "#,";
        } else{
            ss << node->val << ",";
            nodeQueue.push(node->left);
            nodeQueue.push(node->right);
        }
    }
    //remove '#'s at the end
    string ans = ss.str();
    int i = ans.size() -1;
    while (i>=0 && (ans[i]==','||ans[i]=='#')){
        ans.erase(i,1);
        i--;
    }
    cout << "the result of serialization: " << ans << endl;
    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.empty() || data.size() == 0)
        return NULL;

    vector<string> tokens = splitString(data, ",");
    if(tokens.empty() || !tokens.size() || tokens[0].compare("#")==0)
        return NULL;

    vector<TreeNode*> curLevel, nextLevel;
    TreeNode* root = new TreeNode(atoi(tokens[0].c_str()));
    curLevel.push_back(root);

    int t = 1;
    while(t < tokens.size()){
        for(int i=0; i< curLevel.size(); i++){
            TreeNode* cur = curLevel[i];
            if(t < tokens.size() && tokens[t].compare("#") != 0){
                TreeNode *node = new TreeNode(atoi(tokens[t].c_str()));
                cur->left = node;
                nextLevel.push_back(node);
            }
            t ++;
            if(t < tokens.size() && tokens[t].compare("#") != 0){
                TreeNode *node = new TreeNode(atoi(tokens[t].c_str()));
                cur->right = node;
                nextLevel.push_back(node);
            }
            t ++;
        }
        curLevel = nextLevel;
        nextLevel.clear();
    }
    return root;
}

void testVectorCopy(){
    int array[6] = {1,2,3,4,5,6};
    vector<int> vec1(array, array+3);
    vector<int> vec2(array+3, array+7);
    cout << vec1[0] << " " << vec1[1] << " " << endl;
    vec1=vec2;
    vec2.clear();
    cout << vec1[0] << " " << vec1[1] << " " << endl;
}
/*
int main(int argc, char *argv[])
{
    string array[7] = {"1","2","3","#","#","4","5"};
    vector<string> vec(array, array+7);
    TreeNode* root = constructBinaryTree(vec);
    string ser = serialize(root);
    root = deserialize(ser);

    vector<vector<int> > res = levelOrder(root);
    for (int i=0; i< res.size(); i++){
        for (int j=0; j< res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

}
*/
