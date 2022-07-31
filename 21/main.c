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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    /*
    printf("!!\n");
    print(list1);
    print(list2);
    */
    if (list2 == NULL) {
        return list1;
    }
    if (list1 == NULL) {
        return list2;
    }
    ListNode *put = list2;
    list2 = list2->next;

    ListNode *tmp = list1;
    ListNode *prev = NULL;
    while (tmp != NULL) {
        if (put->val <= tmp->val) {
            //printf("%d %d\n", put->val, tmp->val);
            put->next = tmp;
            if (prev != NULL) {
                prev->next = put;
            } else {
                list1 = put;
            }
            break;
        }
        if (tmp->next == NULL) {
            put->next = NULL;
            tmp->next = put;
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    /*
    printf("@@\n");
    print(list1);
    print(list2);
    */
    return mergeTwoLists(list1, list2);
}

int main() {
    ListNode* h1 = NULL;
    prepend(&h1, 4);
    prepend(&h1, 2);
    prepend(&h1, 1);

    ListNode* h2 = NULL;
    prepend(&h2, 5);
    prepend(&h2, 3);
    prepend(&h2, 0);

    print(h1);
    print(h2);

    print(mergeTwoLists(h1, h2));
    print(mergeTwoLists(NULL, h2));
    return 0;
}
