#include <stdio.h>
#include <stdbool.h>

#define MAP_SIZE 100000


bool containsDuplicate(int* nums, int numsSize){
    int map[MAP_SIZE] = { 0 };
    for (int i = 0; i < numsSize; i++) {
        if (map[nums[i]]++ > 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int arr1[] = { 1,2,3,1 };
    int arr2[] = { 1,2,3,4 };
    printf("true - %s\n", containsDuplicate(arr1, 4) ? "true" : "false");
    printf("true - %s\n", containsDuplicate(arr2, 4) ? "true" : "false");
    return 0;
}
