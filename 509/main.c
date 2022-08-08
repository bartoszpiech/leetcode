#include <stdio.h>

#define MEMSIZE 100
int fib(int n){
    static int mem[MEMSIZE];
    static int flag = 0;
    if (flag == 0) {    // fill the memory
        mem[0] = 0;
        mem[1] = 1;
        for (int i = 2; i < MEMSIZE; i++) {
            mem[i] = -1;
        }
        flag = 1;
    }
    if (mem[n] == -1) {
        mem[n] = fib(n - 1) + fib(n - 2);
    }
    return mem[n];
}

int main() {
    printf("%d\n", fib(0));
    printf("%d\n", fib(1));
    printf("%d\n", fib(2));
    printf("%d\n", fib(3));
    printf("%d\n", fib(4));
    printf("%d\n", fib(5));
    printf("%d\n", fib(6));
    printf("%d\n", fib(7));
    printf("%d\n", fib(8));
    printf("%d\n", fib(9));
    printf("%d\n", fib(10));
    return 0;
}
