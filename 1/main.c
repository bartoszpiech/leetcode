#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

int main() {
    int arr1[] = { 2,7,11,15 };
    int *res = malloc(sizeof(int) * 2);
    res= twoSum(arr1, 4, 9, res);
    printf("%d - %d, %d", 9, res[0], res[1]);
    free(res);
    return 0;
}
