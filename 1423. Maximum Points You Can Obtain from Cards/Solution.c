#include <math.h>

int maxScore(int* cardPoints, int cardPointsSize, int k)
{
    int all_sum = 0, window_sum = 0, window_size = cardPointsSize - k;
    for (int i = 0; i < window_size; ++i) {
        all_sum += cardPoints[i];
        window_sum += cardPoints[i];
    }

    int min_sum = window_sum;
    for (int i = window_size; i < cardPointsSize; ++i) {
        all_sum += cardPoints[i];
        window_sum += cardPoints[i] - cardPoints[i - window_size];
        min_sum = fmin(min_sum, window_sum);
    }
    return all_sum - min_sum;
}
