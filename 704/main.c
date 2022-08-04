#include <stdio.h>

int search(int* nums, int numsSize, int target){
    int lind = 0;
    int rind = numsSize - 1;
    while (lind + 1 < rind) {
        int mid = (lind + rind) / 2;
        if (nums[mid] < target) {
            lind = mid;
        } else  if (nums[mid] > target) {
            rind = mid;
        } else {
            return mid;
        }
    }
    if (nums[rind] == target) {
        return rind;
    }
    if (nums[lind] == target) {
        return lind;
    }
    return -1;
}

/*
int search(int *nums, int numsSize, int lind, int rind, int target) {
    int mid = (lind + rind) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    if (nums[mid] < target) {
        lind = mid;
    } else {
        rind = mid;
    }
    return search(nums, numsSize, lind, rind, target);
}
*/

int main() {
    int arr[] = { -1,0,3,5,9,12 };
    int arr_size = 6;
    int arr2[] = { 2,5 };
    int arr2_size = 2;
    printf("%d\n", search(arr, arr_size, 12));
    printf("%d\n", search(arr2, arr2_size, 5));
    return 0;
}
