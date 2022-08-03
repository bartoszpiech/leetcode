#include <stdio.h>
#include <string.h>

int firstUniqChar(char * s){
    int hashmap[26] = { 0 };
    for (int i = 0; i < strlen(s); i++) {
        hashmap[s[i] - 97]++;
    }
    for (int i = 0; i < strlen(s); i++) {
        if (hashmap[s[i] - 97] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    printf("%d\n", firstUniqChar("leetcode"));
    printf("%d\n", firstUniqChar("loveleetcode"));
    printf("%d\n", firstUniqChar("aabb"));
    return 0;
}
