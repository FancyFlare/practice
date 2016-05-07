#include <iostream>
#include "utility.hpp"
using namespace std;

/*Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
*/

ListNode* oddEvenList(ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    ListNode *pOddHead = head;
    ListNode* pEvenHead = head->next;
    ListNode* pOdd = head;
    ListNode* pEven = pEvenHead;
    /*
     * 两个指针同时移动时注意判断: p && p->next
     * 指针移动永远是 p = p->next
     */
    while(pEven && pEven->next){
        pOdd->next = pEven->next;
        pOdd = pOdd->next;
        pEven->next = pOdd->next;
        pEven = pEven->next;
    }
    pOdd->next = pEvenHead;
    if (pEven){
        pEven->next=NULL;
    }
    return pOddHead;

}
/*
int main(int argc, char *argv[])
{

    int array1[] = {2,1,3};

    ListNode* head1 = constructList(array1, 3);
    ListNode* result = oddEvenList(head1);
    printList(result);

}
*/
