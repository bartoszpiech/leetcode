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

/* recursive, not mine 
struct ListNode* deleteDuplicates(struct ListNode *head) {
    if(head == NULL || head->next == NULL) return head;
    head->next = deleteDuplicates(head->next);
    return head->val == head->next->val ? head->next : head;
}
*/

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    ListNode *prev = head;
    ListNode *tmp = head->next;
    while (tmp) {
        if (tmp->val == prev->val) {
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
    prepend(&h1, 3);
    prepend(&h1, 3);
    prepend(&h1, 2);
    prepend(&h1, 1);
    prepend(&h1, 1);

    prepend(&h2, 1);
    prepend(&h2, 1);
    prepend(&h2, 1);
    print(h1);
    print(deleteDuplicates(h1));
    print(h2);
    print(deleteDuplicates(h2));
    return 0;
}
