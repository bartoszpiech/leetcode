#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isSubsequence(char * s, char * t){
    int s_index = 0;
    for (int i  = 0; i < strlen(t); i++) {
        if (t[i] == s[s_index]) {
            s_index++;
        }
    }
    return s_index == strlen(s);
}

int main() {
    printf("true - %s\n", isSubsequence("abc", "ahbgdc") ? "true" : "false");
    printf("false - %s\n", isSubsequence("axc", "ahbgdc") ? "true" : "false");
}
