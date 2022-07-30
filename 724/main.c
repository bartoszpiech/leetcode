#include <stdio.h>


int partial_sum(int* nums, int rind, int lind) {
    int result = 0;
    for (int i = rind; i < lind; i++) {
        result += nums[i];
    }
    return result;
}
int pivotIndex(int* nums, int nums_size){
    for (int i = 0; i < nums_size; i++) {
        if (partial_sum(nums, 0, i) == partial_sum(nums, i + 1, nums_size)) {
            return i;
        }
    }
    return -1;
}

int main() {
    int nums[] = {1,7,3,6,5,6};
    int nums2[] = {1,2,3};
    int nums3[] = {2,1,-1};
    printf("%d\n", pivotIndex(nums, 6));
    printf("%d\n", pivotIndex(nums2, 3));
    printf("%d\n", pivotIndex(nums3, 3));
    return 0;
}
