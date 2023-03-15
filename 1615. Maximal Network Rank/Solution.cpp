#include <vector>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        vector<int> degrees(n, 0);
        for (const vector<int>& road : roads) {
            degrees[road[0]]++;
            degrees[road[1]]++;
        }

        int max1 = 0, max2 = 0;
        for (const int& degree : degrees) {
            if (degree > max1) {
                max2 = max1;
                max1 = degree;
            } else if (degree > max2 && degree < max1)
                max2 = degree;
        }

        int cnt1 = 0, cnt2 = 0;
        for (const int& degree : degrees) {
            if (degree == max1)
                cnt1++;
            else if (degree == max2)
                cnt2++;
        }

        if (cnt1 == 1) {
            int edge_count = 0;
            for (const vector<int>& road : roads) {
                if (degrees[road[0]] == max1 && degrees[road[1]] == max2)
                    edge_count++;
                if (degrees[road[0]] == max2 && degrees[road[1]] == max1)
                    edge_count++;
            }
            return max1 + max2 - (cnt2 == edge_count ? 1 : 0);
        } else {
            int limit = cnt1 * (cnt1 - 1) / 2;
            int edge_count = 0;
            for (const vector<int>& road : roads)
                if (degrees[road[0]] == max1 && degrees[road[1]] == max1)
                    edge_count++;
            return 2 * max1 - (edge_count == limit ? 1 : 0);
        }
    }
};
