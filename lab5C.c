#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

bool hasCycle(struct ListNode* head) {
    if (head == NULL) return false;
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct ListNode* head = createNode(3);
    head->next = createNode(2);
    head->next->next = createNode(0);
    head->next->next->next = createNode(-4);
    head->next->next->next->next = head->next;
    printf("%s\n", hasCycle(head) ? "true" : "false");

    freeList(head);

    return 0;
}
