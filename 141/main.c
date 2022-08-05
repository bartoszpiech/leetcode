#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     struct ListNode *next;
 };

typedef struct ListNode ListNode;

void prepend(ListNode **h, int value) {
    ListNode *new = malloc(sizeof(ListNode));
    new->val = value;
    new->next = *h;
    *h = new;
}

void append(ListNode **h, int value) {
    ListNode *new = malloc(sizeof(ListNode));
    new->val = value;
    if (*h == NULL) {
        *h = new;
        return;
    }
    new->next = (*h)->next;
    (*h)->next = new;
}

void print(ListNode *h) {
    ListNode *tmp = h;
    printf("{ ");
    while (tmp != NULL) {
        printf("%d -> ", tmp->val);
        tmp = tmp->next;
    }
    printf("NULL }\n");
}

bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }
    while (head->next && head->val != 100001) {
        ListNode *tmp = head;
        head = head->next;
        tmp->val = 100001;
    }
    return head->val == 100001;
}
int main() {
    ListNode* h1 = NULL;
    ListNode* h2 = NULL;
    prepend(&h1, -4);
    prepend(&h1, 0);
    prepend(&h1, 2);
    prepend(&h1, 3);
    print(h1);
    h1->next->next->next->next = h1->next;

    prepend(&h2, 2);
    prepend(&h2, 1);
    print(h2);
    h2->next->next = h2;

    printf("%s\n", hasCycle(h1) ? "true" : "false");
    printf("%s\n", hasCycle(h2) ? "true" : "false");
    return 0;
}
