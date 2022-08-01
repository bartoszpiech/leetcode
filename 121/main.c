#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProfit(int *prices, int pricesSize) {
    int minPrice = prices[0];
    int minPriceInd = 0;
    for (int i = 0; i < pricesSize; i++) {
        if (minPrice > prices[i]) {
            minPrice = prices[i];
            minPriceInd = i;
        }
    }
    int maxPrice = minPrice;
    for (int i = minPriceInd; i < pricesSize; i++) {
        if (maxPrice < prices[i]) {
            maxPrice = prices[i];
        }
    }
    return maxPrice - minPrice;
}

int main() {
    int arr1[] = { 7,1,5,3,6,4 };
    printf("%d\n", maxProfit(arr1, 6));
    return 0;
}
