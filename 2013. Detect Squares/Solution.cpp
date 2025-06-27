#include <unordered_map>
#include <vector>
using namespace std;

class DetectSquares {
public:
    DetectSquares()
    {
    }

    void add(vector<int> point)
    {
        int r = point[0], c = point[1];
        ++row2cnt[r][c];
    }

    int count(vector<int> point)
    {
        int ans = 0, r1 = point[0], c1 = point[1];
        for (const auto& [c2, cnt1] : row2cnt[r1]) {
            if (c2 == c1)
                continue;
            int side_length = abs(c2 - c1);
            int r2 = r1 - side_length;
            int cnt2 = row2cnt[r2][c1];
            int cnt3 = row2cnt[r2][c2];
            ans += cnt1 * cnt2 * cnt3;

            r2 = r1 + side_length;
            cnt2 = row2cnt[r2][c1];
            cnt3 = row2cnt[r2][c2];
            ans += cnt1 * cnt2 * cnt3;
        }
        return ans;
    }

private:
    unordered_map<int, unordered_map<int, int>> row2cnt;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
