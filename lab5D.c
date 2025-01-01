#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* second_half = slow;
    struct ListNode* prev = NULL;
    while (second_half != NULL) {
        struct ListNode* next = second_half->next;
        second_half->next = prev;
        prev = second_half;
        second_half = next;
    }

    struct ListNode* first_half = head;
    second_half = prev;

    while (second_half != NULL) {
        if (first_half->val != second_half->val) return false;
        first_half = first_half->next;
        second_half = second_half->next;
    }

    return true;
}

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);

    printf("%s\n", isPalindrome(head) ? "true" : "false");

    freeList(head);
    return 0;
}
