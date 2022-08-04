#include <stdio.h>
#include <stdbool.h>

// The API isBadVersion is defined for you.
bool isBadVersion(int version) {
    static int i = 0;
    printf("%d\n", i++);
    return version > 20;
}

int firstBadVersion(int n) {
    int lind = 0;
    int rind = n;
    int mid;
    while (lind <= rind) {
        mid = lind + (rind - lind) / 2;
        if (isBadVersion(mid) == true) {
            rind = mid;
        } else {
            lind = mid;
        }
        if (isBadVersion(mid) == false && isBadVersion(mid + 1) == true) {
            return mid + 1;
        }
    }
    return mid;
}

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

int main() {
    printf("%d\n", firstBadVersion(100));
    return 0;
}
