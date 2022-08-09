#include <stdio.h>
#include <stdlib.h>

int minCostClimbingStairs(int* cost, int costSize){
    int *dp = malloc(sizeof(int) * costSize);
    dp[costSize - 1] = cost[costSize - 1];
    dp[costSize - 2] = cost[costSize - 2];
    for (int i = costSize - 3; i >= 0; i--) {
        int min = dp[i + 1] < dp[i + 2] ? dp[i + 1] : dp[i + 2];
        dp[i] = cost[i] + min;
    }
    return dp[0] < dp[1] ? dp[0] : dp[1];
}

int main() {
    int arr1[] = {10,15,20};
    int arr2[] = {1,100,1,1,1,100,1,1,100,1};
    int arr3[] = {0,1,2,2};
    printf("%d\n", minCostClimbingStairs(arr1, 3));
    printf("%d\n", minCostClimbingStairs(arr2, 10));
    printf("%d\n", minCostClimbingStairs(arr3, 4));
    return 0;
}
