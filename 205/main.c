#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool inner(char *first, char *second) {
    char map[127] = { 0 };
    for (int i = 0; i < strlen(first); i++) {
        if (map[first[i]] == 0) {
            map[first[i]] = second[i];
        } else if (map[first[i]] != second[i]) {
            return false;
        }
    }
    return true;
}

bool isIsomorphic(char *s, char *t){
    return inner(s, t) && inner(t, s);
}


int main() {
    printf("false - %s\n", is_isomorphic("foo", "bar") ? "true" : "false");
    printf("true - %s\n", is_isomorphic("add", "egg") ? "true" : "false");
    printf("true - %s\n", is_isomorphic("paper", "title") ? "true" : "false");
    printf("false - %s\n", is_isomorphic("badc", "baba") ? "true" : "false");
    printf("true - %s\n", is_isomorphic("ACAB", "XCXY") ? "true" : "false");
    printf("false - %s\n", is_isomorphic("ACAB", "XCWY") ? "true" : "false");
    printf("true - %s\n", is_isomorphic("a", "a") ? "true" : "false");

    return 0;
}
