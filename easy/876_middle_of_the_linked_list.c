#include<stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode *middleNode(struct ListNode *head);
struct ListNode *middleNode_twoPointer(struct ListNode *head);

int main() {
    struct ListNode* head = NULL;
    struct ListNode* second = NULL;
    struct ListNode* third = NULL;
    struct ListNode* fourth = NULL;
  
    // allocate 4 nodes in the heap
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    second = (struct ListNode*)malloc(sizeof(struct ListNode));
    third = (struct ListNode*)malloc(sizeof(struct ListNode));
    fourth = (struct ListNode*)malloc(sizeof(struct ListNode));

    head->val=1;
    head->next=second;

    second->val=2;
    second->next=third;

    third->val=3;
    third->next=fourth;

    fourth->val=4;
    fourth->next=NULL;

    struct ListNode* midNode = middleNode(head);

    free(fourth);
    free(third);
    free(second);
    free(head);

    return 0;
}

/**
 * @brief 
 * Given the head of a singly linked list, return the middle node of the linked list.

 * If there are two middle nodes, return the second middle node.
 * Time complexity O(n) 
 * Space complexity O(1)
 */
struct ListNode *middleNode(struct ListNode *head) {
    int size = 1;
    struct ListNode* current = head;
    while(current->next != NULL) {
        size++;
        current = current->next;
    }
    int mid = size/2;
    struct ListNode* middle = head;
    for (int i = 0; i < mid ; i++) {
        middle = middle->next;
    }
    return middle;
}

struct ListNode *middleNode_twoPointer(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}