#include <iostream>
#include <queue>
#include "utility.hpp"
using namespace std;

vector<string> splitString(string s, string delim){
    int fast = 0, slow = 0;
    int len = delim.size();
    vector<string> res;
    while(fast < s.size()){
        if (s.substr(fast, len).compare(delim)==0){
            if(fast>slow){
                res.push_back(s.substr(slow, fast-slow));
            }
            fast += len;
            slow = fast;
        }else{
            fast ++;
        }
    }
    res.push_back(s.substr(slow));
    return res;
}

void printList(ListNode* head){
    ListNode* p = head;
    while(p != NULL){
        cout << p->val << endl;
        p = p->next;
    }
}

ListNode* constructList(int array[], int num){
    if (num == 0){
        return NULL;
    }
    ListNode* head = new ListNode(array[0]);
    ListNode* p = head;

    for (int i = 1; i < num; i++){
        ListNode* newNode = new ListNode(array[i]);
        p->next = newNode;
        p = p->next;
    }
    return head;
}

ListNode* reverseList(ListNode* head){
    if (head == NULL || head->next == NULL){
        return head;
    }
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    ListNode* p3 = head->next->next;

    while (p3 != NULL) {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }

    p2->next = p1;
    head->next = NULL;

    return p2;
}

TreeNode* constructBinaryTree(const vector<string> &input){
    if(input.size()==0 || input[0].compare("#")==0){
        return NULL;
    }
    TreeNode* ret = new TreeNode(atoi(input[0].c_str()));
    vector<TreeNode*> currentLevel, nextLevel;
    currentLevel.push_back(ret);

    int p = 1;
    while(p < input.size()){
        for(int i=0; i< currentLevel.size(); i++){
            TreeNode* root = currentLevel[i];
            //left child
            if(p < input.size() && input[p].compare("#") != 0){
                TreeNode* node = new TreeNode(atoi(input[p].c_str()));
                root->left = node;
                nextLevel.push_back(node);
            }
            p ++;
            //right child
            if(p < input.size() && input[p].compare("#") != 0){
                TreeNode* node = new TreeNode(atoi(input[p].c_str()));
                root->right = node;
                nextLevel.push_back(node);
            }
            p ++;
        }
        currentLevel = nextLevel;
        nextLevel.clear();
    }
    return ret;
}

void printBinaryTree(TreeNode* root) {
    queue<TreeNode*> nodeQueue;
    if(!root)
        return;

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
        for(int i = 0; i < level.size(); i++){
            cout << level[i] << " ";
        }
        cout << endl;
        nodeQueue.pop();
        if(nodeQueue.size()){
            nodeQueue.push(NULL);
        }
    }
}
