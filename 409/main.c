#include <stdio.h>
#include <stdbool.h>

int longestPalindrome(char * s){
    int result = 0;
    int middleflag = 0;         // for letter in the middle
    int hashmap[128] = { 0 };   // for every ascii letter
    for (int i = 0; s[i] != '\0'; i++) {
        hashmap[s[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (hashmap[i] % 2 == 1) {
            middleflag = 1;
        }
        result += hashmap[i] / 2;
    }
    return result * 2 + middleflag;
}

int main() {
    printf("%d\n", longestPalindrome("abccccdd"));
    printf("%d\n", longestPalindrome("a"));
    return 0;
}
