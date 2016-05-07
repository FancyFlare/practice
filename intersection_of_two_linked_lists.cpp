#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        //get the size of the first list
        ListNode *p = headA;
        int countA = 0;
        while(p){
            countA ++;
            p = p->next;
        }
        cout << "coutA: " << countA << endl;
        //get the size of the second list
        p = headB;
        int countB = 0;
        while(p){
            countB ++;
            p = p->next;
        }
        cout << "coutB: " << countB << endl;

        ListNode *pA = headA, *pB = headB;
        int count_diff = countA - countB;
        if(count_diff > 0){
            int i = 0;
            while(i < count_diff){
                i++;
                pA = pA->next;
            }
        }else{
            int i = 0;
            while(i < 0-count_diff){
                i++;
                pB = pB->next;
            }
        }

        while(pA && pB){
            if(pA == pB){
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
/*
    int main(int argc, char *argv[])
    {
        ListNode *headA = new ListNode(3);
        ListNode *headB = new ListNode(2);
        headB->next = headA;
        ListNode *ret = getIntersectionNode(headA, headB);
        cout << ret->val;
    }
*/
