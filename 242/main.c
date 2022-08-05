#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char * s, char * t){
    int hashmap[26] = { 0 };
    int counter = 0; // counts if hashmap is empty after reorganazing all letters
    for (int i = 0; s[i] != '\0'; i++) {
        hashmap[s[i] - 'a']++;
        counter++;
    }
    for (int i = 0; t[i] != '\0'; i++) {
        if (--hashmap[t[i] - 'a'] < 0) {
            return false;
        }
        counter--;
    }
    return counter == 0;
}

int main() {
    printf("%s\n", isAnagram("anagram", "nagaram") ? "true" : "false");
    printf("%s\n", isAnagram("rat", "car") ? "true" : "false");
    printf("%s\n", isAnagram("ab", "a") ? "true" : "false");
    return 0;
}
