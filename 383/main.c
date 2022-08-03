#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char * ransomNote, char * magazine){
    int hashmap[26] = { 0 };
    // add to map letters from magazine
    for (int i = 0; magazine[i] != '\0'; i++) {
        hashmap[magazine[i] - 'a']++;
    }
    // check if letters are in magazine
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (--hashmap[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("%s\n", canConstruct("a", "b") ? "true" : "false");
    printf("%s\n", canConstruct("aa", "ab") ? "true" : "false");
    printf("%s\n", canConstruct("aa", "aab") ? "true" : "false");
    return 0;
}
