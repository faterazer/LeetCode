#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int window_size = cardPoints.size() - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + window_size, 0);
        int min_sum = sum;
        for (int i = window_size; i < cardPoints.size(); ++i) {
            sum += cardPoints[i] - cardPoints[i - window_size];
            min_sum = min(sum, min_sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - min_sum;
    }
};
