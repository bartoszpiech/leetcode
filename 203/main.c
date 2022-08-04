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

struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL) {
        return NULL;
    }
    while (head != NULL && head->val == val) { // clear all head elements
        head = head->next;
    }
    ListNode *prev = head;
    ListNode *tmp = head;
    while (tmp != NULL) { // clear all elements inside
        if (tmp->val == val) {
            prev->next = tmp->next;
        } else {
            prev = tmp;
        }
        tmp = tmp->next;
    }
    return head;
}

int main() {
    ListNode* h1 = NULL;
    ListNode* h2 = NULL;
    ListNode* h3 = NULL;
    prepend(&h1, 6);
    prepend(&h1, 5);
    prepend(&h1, 4);
    prepend(&h1, 3);
    prepend(&h1, 6);
    prepend(&h1, 2);
    prepend(&h1, 1);

    prepend(&h2, 7);
    prepend(&h2, 7);
    prepend(&h2, 7);
    prepend(&h2, 7);

    prepend(&h3, 2);
    prepend(&h3, 1);
    print(h1);
    print(removeElements(h1, 6));
    print(h2);
    print(removeElements(h2, 7));
    print(h3);
    print(removeElements(h3, 1));
    //print(middleNode(h2));
    return 0;
}
