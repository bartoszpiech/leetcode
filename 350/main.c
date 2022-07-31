#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *first = NULL;
    int *last = NULL;
    /*
    int *longer = nums1Size >= nums2Size ? nums1 : nums2;
    int longerSize = nums1Size >= nums2Size ? nums1Size : nums2Size;
    for (int i = 0; i < longerSize; i++) {
        for (int j = 0; j < 
        if (
    }
    */
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                first = &nums1[i];
                last = &nums1[i];
                int ind1 = i;
                int ind2 = j;
                while (nums1[ind1++] == nums2[ind2++]) {
                    last++;
                }
            }
        }
    }
    *returnSize = last - first;
    int *result = malloc(sizeof(int) * *returnSize);
    memcpy(result, first, *returnSize * sizeof(int));
    printf("first = %d\n", *first);
    printf("last = %d\n", *last);
    printf("len = %d\n", *returnSize);
    return result;
}

int main() {
    int arr1[] = { 1,2,2,1 };
    int arr2[] = { 2,2 };
    int *resSize = malloc(sizeof(int));
    int * res = intersect(arr1, 4, arr2, 2, resSize);
    for (int i = 0; i < *resSize; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
