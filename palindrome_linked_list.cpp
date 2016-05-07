#include <iostream>
#include "utility.hpp"
using namespace std;

/*
 * 234. Given a singly linked list, determine if it is a palindrome.
 * Could you do it in O(n) time and O(1) space?
 */



bool isPalindrome(ListNode* head) {
    if (head == NULL){
        return true;
    }
    //Firstly reverse the latter half part
    int size = 1;
    ListNode* p = head;

    while (p->next != NULL){
        size ++;
        p = p->next;
    }
    if (size == 1){
        return true;
    }
    int half_size = size/2;

    int i = 0;
    p = head;
    while (p->next != NULL && i < half_size){
        i ++;
        p = p->next;
    }
    ListNode* half_head = p;
    printList(half_head);
    //reverse
    ListNode* tail = reverseList(half_head);
    printList(tail);
    ListNode* p1 = head;
    ListNode* p2 = tail;
    i = 0;
    while (p1->next != NULL && i < half_size){
        i ++;
        if (p1->val != p2->val){
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}

/*
int main(int argc, char *argv[])
{
    int array[] = {1,1,2,1};
    ListNode* head = constructList(array, 4);

    cout << "result: " << isPalindrome(head);
}
*/
