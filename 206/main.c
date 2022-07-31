#include <stdio.h>
#include <stdlib.h>

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

struct ListNode* reverseList(struct ListNode* head){
    if (!head) {
        return NULL;
    }
    ListNode *tmp = head->next;
    ListNode *prev = head;
    while (tmp) {
        prev->next = tmp->next;
        tmp->next = head;
        head = tmp;
        tmp = prev->next;
    }
    return head;
}

int main() {
    ListNode* h1 = NULL;
    ListNode* h2 = NULL;
    prepend(&h1, 5);
    prepend(&h1, 4);
    prepend(&h1, 3);
    prepend(&h1, 2);
    prepend(&h1, 1);

    prepend(&h2, 3);
    prepend(&h2, 2);
    prepend(&h2, 1);
    //print(h1);
    print(reverseList(h1));
    print(reverseList(h2));
    return 0;
}
