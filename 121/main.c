#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProfit(int *prices, int pricesSize) {
    int result = 0;
    int min = prices[0], max = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (max < prices[i]) {
            max = prices[i];
            result = result < max - min ? max - min : result;
        }
        if (min > prices[i]) {
            min = prices[i];
            max = prices[i];
        }
    }
    return result;
}

int main() {
    int arr1[] = { 7,1,5,3,6,4 };
    printf("%d\n", maxProfit(arr1, 6));
    return 0;
}
