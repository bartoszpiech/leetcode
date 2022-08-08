#include <stdio.h>

typedef struct Node {
    int val;
    int numChildren;
    struct Node** children;
} Node;

Node *tree_init(int val) {
    Node *t = malloc(sizeof(Node));
    t->val = val;
    t->numChildren = 0;
    t->children = NULL;
    return t;
}

void tree_free(Node *t) {

}

int countChildren(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int res = root->numChildren;
    for (int i = 0; i < root->numChildren; i++) {
        res += countChildren(root->children[i]);
    }
    return res;
}

void addChildren(Node *root, int *arr, int *ind) {
    if (root == NULL) {
        return;
    }
    arr[*ind] = root->val;
    *ind = *ind + 1;
    for (int i = 0; i < root->numChildren; i++) {
        addChildren(root->children[i], arr, ind);
    }
}

int* preorder(struct Node* root, int* returnSize) {
    int size = countChildren(root) + 1;
    int *result = malloc(sizeof(int) * size);
    int result_ind = 0;
    addChildren(root, result, &result_ind);
    *returnSize = result_ind;
    return result;
}

int main() {
    return 0;
}
