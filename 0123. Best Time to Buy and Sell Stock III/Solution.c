#include <limits.h>
#include <math.h>

int maxProfit(int* prices, int pricesSize)
{
    int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
    for (int i = 0; i < pricesSize; i++) {
        buy1 = fmax(buy1, -prices[i]);
        sell1 = fmax(sell1, buy1 + prices[i]);
        buy2 = fmax(buy2, sell1 - prices[i]);
        sell2 = fmax(sell2, buy2 + prices[i]);
    }
    return sell2;
}
