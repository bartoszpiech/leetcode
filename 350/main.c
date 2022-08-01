#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHMAPSIZE 1001

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int numshm[HASHMAPSIZE][2] = { 0 };
    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        numshm[nums1[i]][0]++;
    }
    for (int i = 0; i < nums2Size; i++) {
        if (numshm[nums2[i]][1] < numshm[nums2[i]][0]) {
            numshm[nums2[i]][1]++;
            (*returnSize)++;
        }
    }
    int *result = malloc(sizeof(int) * *returnSize);
    int resultInd = 0;

    int* shorter = nums1Size < nums2Size ? nums1 : nums2;
    int shorterSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    for (int i = 0; i < shorterSize; i++) {
        while (numshm[shorter[i]][1]-- > 0) {
            result[resultInd++] = shorter[i];
        }
    }
    return result;
}

int main() {
    int arr1[] = { 1000,1000,1000 };
    int arr2[] = { 1000,1000 };
    int *resSize = malloc(sizeof(int));
    int * res = intersect(arr1, 3, arr2, 2, resSize);
    for (int i = 0; i < *resSize; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}
