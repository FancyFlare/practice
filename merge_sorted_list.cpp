#include <iostream>
#include "utility.hpp"
using namespace std;

/*
 * 21. Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * Notes: 注意保留返回链表的头指针
 */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    /*
    if(l1 && l2){
        if (l1->val <= l2->val){
            head = l1;
            l1=l1->next;
        }else{
            head=l2;
            l2=l2->next;
        }
    }else if (l1){
        head=l1;
        l1=l1->next;
    }else if (l2){
        head = l2;
        l2=l2->next;
    }else{
        return NULL;
    }*/

    if(l1 && (l2==NULL || l1->val <= l2->val)){
        head = l1;
        l1=l1->next;
    } else if(l2 && (l1==NULL || l2->val <= l1->val)){
        head = l2;
        l2=l2->next;
    }
    if(head == NULL)
        return head;

    ListNode* p=head;

    while (l1 != NULL && l2 != NULL){
        if (l1->val <= l2->val){
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }else{
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
    }
    while(l1 != NULL){
        p->next = l1;
        p = p->next;
        l1 = l1->next;
    }
    while(l2 != NULL){
        p->next = l2;
        p = p->next;
        l2 = l2->next;
    }
    return head;
}
/*
int main(int argc, char *argv[])
{
    int array1[] = {2};
    int array2[] = {1};

    ListNode* head1 = constructList(array1, 1);
    ListNode* head2 = constructList(array2, 1);
    ListNode* result = mergeTwoLists(head1, head2);
    printList(result);
}
*/
