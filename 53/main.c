#include <stdio.h>


int maxSubArray(int* nums, int numsSize){
    int maxSum = nums[0];
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (maxSum < sum) {
            maxSum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}

int main() {
    int arr1[] = { -2,1,-3,4,-1,2,1,-5,4 };
    int arr2[] = { 5,4,-1,7,8 };
    int arr3[] = { -1 };
    printf("%d\n", maxSubArray(arr1, 9));
    printf("%d\n", maxSubArray(arr2, 5));
    printf("%d\n", maxSubArray(arr3, 1));
    return 0;
}
