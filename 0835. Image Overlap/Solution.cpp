#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        vector<int> A, B;
        int n = img1.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j])
                    A.emplace_back(i * 100 + j);
                if (img2[i][j])
                    B.emplace_back(i * 100 + j);
            }
        }
        unordered_map<int, int> cnt;
        for (const int& x : A)
            for (const int& y : B)
                ++cnt[x - y];
        int res = 0;
        for (const auto& it : cnt)
            res = max(res, it.second);
        return res;
    }
};
