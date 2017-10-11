/*
https://www.hackerrank.com/challenges/ctci-linked-list-cycle
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node* tortoise = head;
    Node * hare = head;
    while(tortoise != NULL && hare != NULL){
        hare = hare->next;
        if(hare == NULL){
            return false;
        }
        hare = hare->next;
        tortoise = tortoise->next;
        if(tortoise == hare){
            return true;
        }
    }
    return false;
}
