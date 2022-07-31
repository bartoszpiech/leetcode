#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_arr(char *name, int *arr, int arr_size) {
    printf("%s = { ", name);
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if (nums1Size < 1 || nums2Size < 1) {
        return;
    }
    int *nums3 = malloc(sizeof(int) * (m + n));
    int nums1ind = 0;
    int nums2ind = 0;
    for (int i = 0; i < m + n; i++) {
        if (nums1ind < m && nums2ind < n) {
            if (nums1[nums1ind] <= nums2[nums2ind]) {
                nums3[i] = nums1[nums1ind++];
            } else {
                nums3[i] = nums2[nums2ind++];
            }
        }
        else if (nums1ind < m) {
            nums3[i] = nums1[nums1ind++];
        }
        else {
            nums3[i] = nums2[nums2ind++];
        }
    }
    memcpy(nums1, nums3, sizeof(int) * (m + n));
    free(nums3);
}


int main() {
    int arr1[] = { 4,5,6,0,0,0 };
    int arr1_size = 6;
    int arr2[] = { 1,2,3 };
    int arr2_size = 3;

    int arr3[] = { 1 };
    int arr3_size = 1;
    int arr4[] = { };
    int arr4_size = 0;

    int arr5[] = { 0 };
    int arr5_size = 1;
    int arr6[] = { };
    int arr6_size = 0;

    int arr7[] = { 2,0 };
    int arr7_size = 2;
    int arr8[] = { 1 };
    int arr8_size = 1;

    int arr9[] = { 1,2,3,0,0,0 };
    int arr9_size = 6;
    int arr10[] = { 2,5,6 };
    int arr10_size = 3;

    int arr11[] = { 0 };
    int arr11_size = 1;
    int arr12[] = { 1 };
    int arr12_size = 1;

    int arr13[] = { 4,0,0,0,0,0 };
    int arr13_size = 6;
    int arr14[] = { 1,2,3,5,6 };
    int arr14_size = 5;

    int arr15[] = { 1,2,4,5,6,0 };
    int arr15_size = 6;
    int arr16[] = { 3 };
    int arr16_size = 1;
    merge(arr1, arr1_size, 3, arr2, arr2_size, 3);
    print_arr("arr1", arr1, arr1_size);
    merge(arr3, arr3_size, 1, arr4, arr4_size, 0);
    print_arr("arr3", arr3, arr3_size);
    merge(arr5, arr5_size, 1, arr6, arr6_size, 0);
    print_arr("arr5", arr5, arr5_size);
    merge(arr7, arr7_size, 1, arr8, arr8_size, 1);
    print_arr("arr7", arr7, arr7_size);
    merge(arr9, arr9_size, 3, arr10, arr10_size, 3);
    print_arr("arr9", arr9, arr9_size);
    merge(arr11, arr11_size, 0, arr12, arr12_size, 1);
    print_arr("arr11", arr11, arr11_size);
    merge(arr13, arr13_size, 1, arr14, arr14_size, 5);
    print_arr("arr13", arr13, arr13_size);
    merge(arr15, arr15_size, 5, arr16, arr16_size, 1);
    print_arr("arr15", arr15, arr15_size);
    return 0;
}
