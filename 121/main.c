#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProfit(int *prices, int pricesSize) {
    int maxPrice = 0;
    for (int i = 0; i < pricesSize; i++) {
        for (int j = i; j < pricesSize; j++) {
            if (prices[j] - prices[i] > maxPrice) {
                maxPrice = prices[j] - prices[i];
            }
        }
    }
    return maxPrice;
}

int main() {
    int arr1[] = { 7,6,4,3,1 };
    printf("%d\n", maxProfit(arr1, 5));
    return 0;
}
