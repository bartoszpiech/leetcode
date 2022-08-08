#include <stdio.h>

/*
1 - 1   1
2 - 2   11  2
3 - 3   111 21  12
4 - 5   1111    112 211 121 22
5 - 8   11111   ...
6 - 13
7 - 21
8 - 34
9 - 55
10 - 89
*/


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

int climbStairs(int n) {
    return fib(n + 1);
}

int main() {
    printf("%d\n", climbStairs(10));
    return 0;
}
