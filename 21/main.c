#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 */

 typedef struct ListNode {
     int val;
     struct ListNode *next;
 } ListNode;

void append(ListNode **h, int value) {
    ListNode *new = malloc(sizeof(ListNode));
    new->val = value;
    new->next = *h;
    *h = new;
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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    ListNode *h = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            append(&h, list1->val);
            list1 = list1->next;
        } else {
            append(&h, list2->val);
            list2 = list2->next;
        }
    }
    while (list1 != NULL) {
        append(&h, list1->val);
        list1 = list1->next;
    }
    while (list2 != NULL) {
        append(&h, list2->val);
        list2 = list2->next;
    }
    return h;
}

int main() {
    ListNode* h1 = NULL;
    append(&h1, 4);
    append(&h1, 2);
    append(&h1, 1);

    ListNode* h2 = NULL;
    append(&h2, 5);
    append(&h2, 3);
    append(&h2, 0);

    print(h1);
    print(h2);

    print(mergeTwoLists(h1, h2));
    return 0;
}
