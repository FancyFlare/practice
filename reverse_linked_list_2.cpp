#include <iostream>
#include "utility.hpp"
using namespace std;
/*
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 */


ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL || m < 1 || m >= n ){
        return head;
    }
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    ListNode* p3 = head->next->next;

    int i = 1;
    ListNode* mp = NULL;
    ListNode* pre = NULL;
    while (i <= n) {
        if(i < m){
            if(i == m-1){
                pre = p1;
            }
            p1 = p2;
            p2 = p3;
            if(p3!=NULL)
                p3 = p3->next;
            i ++;
        }
        else if (i >= m && i < n){
            if(i==m){
                mp = p1;
                cout << "mp=" << mp->val << endl;
            }
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if(p3!=NULL)
                p3 = p3->next;
            i ++;
        }else if(i == n){
            cout << "i=n "<< endl;
            if(pre != NULL)
                pre->next = p1;

            mp->next = p2;
            i ++;
        }
        cout << "round " << i << endl;
        //cout << p1->val << " " << mp->val << endl;

    }
    if (m == 1)
        return p1;

    return head;
}
/*
int main(int argc, char *argv[])
{
    int array[] = {1,2,3};
    ListNode* head = constructList(array, 3);
    ListNode* result = reverseBetween(head, 2,3);
    printList(result);
}
*/
