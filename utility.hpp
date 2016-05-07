#include <iostream>
#include <vector>
using namespace std;

vector<string> splitString(string s, string delim);

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head);
ListNode* constructList(int array[], int num);
ListNode* reverseList(ListNode* head);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructBinaryTree(const vector<string> &input);
void printBinaryTree(TreeNode* root);
