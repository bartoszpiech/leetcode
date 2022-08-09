#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int* findAnagrams(char * s, char * p, int* returnSize){
    if (strlen(s) < strlen(p)) {
        *returnSize = 0;
        return NULL;
    }
    int org_hashmap[26] = { 0 };
    int org_counter = 0; // counts if hashmap is empty after reorganazing all letters
    for (int i = 0; p[i] != '\0'; i++) {
        org_hashmap[p[i] - 'a']++;
        org_counter++;
    }
    int *anagramIndexes = malloc(sizeof(int) * strlen(s));
    int anagramIndexesSize = 0;
    for (int i = 0; s[i + strlen(p) - 1] != '\0'; i++) {
        char *str = malloc(sizeof(char) * strlen(p) + 1);
        strncpy(str, &s[i], strlen(p));
        str[strlen(p)] = '\0';
        int counter = org_counter;
        int hashmap[26];
        int flag = 0;
        memcpy(hashmap, org_hashmap, sizeof(int) * 26);
        for (int i = 0; str[i] != '\0'; i++) {
            if (--hashmap[str[i] - 'a'] < 0) {
                flag = 1;
                break;
            }
            counter--;
        }
        if (counter == 0 && flag == 0) {
            anagramIndexes[anagramIndexesSize++] = i;
        }
    }
    anagramIndexes = realloc(anagramIndexes, sizeof(int) * anagramIndexesSize);
    *returnSize = anagramIndexesSize;
    return anagramIndexes;
}

int main() {
    int returnSize;
    int *anagrams = findAnagrams("cbaebabacd", "abc", &returnSize);
    printf("%d %d %d", returnSize, anagrams[0], anagrams[1]);
    return 0;
}
