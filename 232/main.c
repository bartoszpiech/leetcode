#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node_t {
    int val;
    struct node_t *next;
} node_t;

typedef struct {
    node_t *top;
    size_t size;
} stack_t;

stack_t *stack_init() {
    stack_t *new_stack = malloc(sizeof(stack_t));
    new_stack->top = NULL;
    new_stack->size = 0;
    return new_stack;
}

bool stack_is_empty(stack_t *s) {
    if (s->size <= 0) {
        return true;
    }
    return false;
}

int stack_pop(stack_t *s) {
    if (stack_is_empty(s)) {
        fprintf(stderr, "Error, stack underflow\n");
        exit(1);
    }
    int return_val = s->top->val;
    node_t *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    s->size--;
    return return_val;
}

int stack_peek(stack_t *s) {
    if (stack_is_empty(s)) {
        fprintf(stderr, "Error, stack underflow\n");
        exit(1);
    }
    return s->top->val;
}


void stack_free(stack_t *s) {
    while (!stack_is_empty(s)) {
        stack_pop(s);
    }
    free(s);
}

void stack_print(stack_t *s) {
    node_t *tmp = s->top;
    while (tmp) {
        printf("%d ->", tmp->val);
        tmp = tmp->next;
    }
    printf(" NULL\n");
}

void stack_push(stack_t *s, int value) {
    node_t *tmp = malloc(sizeof(node_t));
    tmp->val = value;
    tmp->next = s->top;
    s->top = tmp;
    s->size++;
}

void stack_move(stack_t *s1, stack_t *s2) {
    while (!stack_is_empty(s1)) {
        int tmp = stack_pop(s1);
        stack_push(s2, tmp);
    }
}

typedef struct {
    stack_t *s1;
    stack_t *s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *newQueue = malloc(sizeof(MyQueue));
    newQueue->s1 = stack_init();
    newQueue->s2 = stack_init();
    return newQueue;
}

void myQueuePush(MyQueue* obj, int x) {
    stack_move(obj->s1, obj->s2);
    stack_push(obj->s1, x);
    stack_move(obj->s2, obj->s1);
}

int myQueuePop(MyQueue* obj) {
    int result = stack_pop(obj->s1);
    return result;
}

int myQueuePeek(MyQueue* obj) {
    int result = stack_peek(obj->s1);
    return result;
}

bool myQueueEmpty(MyQueue* obj) {
    return (stack_is_empty(obj->s1));
}

void myQueueFree(MyQueue* obj) {
    stack_free(obj->s1);
    stack_free(obj->s2);
    free(obj);
}

void myQueuePrint(MyQueue* obj) {
    stack_print(obj->s1);
    stack_print(obj->s2);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
int main() {
    MyQueue* obj = myQueueCreate();
    myQueuePrint(obj);
    myQueuePush(obj, 1);
    myQueuePush(obj, 2);
    myQueuePrint(obj);
    printf("%d\n", myQueuePeek(obj));
    printf("%d\n", myQueuePop(obj));
    printf("%s\n", myQueueEmpty(obj) ? "true" : "false");
    myQueueFree(obj);
    return 0;
}
