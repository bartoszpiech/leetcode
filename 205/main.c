#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool is_isomorphic(char * s, char * t){
    char map[128] = { 0 }; // ascii table size
    for (int i = 0; i < strlen(s); i++) {
        if (map[t[i]] == 0 && map[s[i]] == 0) {
            map[t[i]] = s[i];
            map[s[i]] = t[i];
        } else if (s[i] != map[t[i]]) {
            return false;
        }
    }
    return true;
}


int main() {
    printf("true - %s\n", is_isomorphic("add", "egg") ? "true" : "false");
    printf("false - %s\n", is_isomorphic("foo", "bar") ? "true" : "false");
    printf("true - %s\n", is_isomorphic("paper", "title") ? "true" : "false");
    printf("false - %s\n", is_isomorphic("badc", "baba") ? "true" : "false");
    printf("true - %s\n", is_isomorphic("ACAB", "XCXY") ? "true" : "false");
    printf("false - %s\n", is_isomorphic("ACAB", "XCWY") ? "true" : "false");
    printf("true - %s\n", is_isomorphic("a", "a") ? "true" : "false");

    return 0;
}
