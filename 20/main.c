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
        printf("%c ->", tmp->val);
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

bool isValid(char *s){
    stack_t *stack = stack_init();
    for (int i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '(':
                stack_push(stack, 1);
                break;
            case ')':
                if (stack_peek(stack) != 1) {
                    return false;
                }
                stack_pop(stack);
            case '[':
                stack_push(stack, 2);
                break;
            case ']':
                if (stack_peek(stack) != 2) {
                    return false;
                }
                stack_pop(stack);
            case '{':
                stack_push(stack, 3);
                break;
            case '}':
                if (stack_peek(stack) != 3) {
                    return false;
                }
                stack_pop(stack);
                break;
            default:
                fprintf(stderr, "Error, invalid character in isValid fcn argument\n");
                exit(1);
                break;
        }
    }
    return true;
}

int main() {
    printf("%s\n", isValid("()") ? "true" : "false");
    printf("%s\n", isValid("()[]{}") ? "true" : "false");
    printf("%s\n", isValid("(]") ? "true" : "false");
    printf("%s\n", isValid("(]]") ? "true" : "false");
    printf("%s\n", isValid("") ? "true" : "false");
    return 0;
}
