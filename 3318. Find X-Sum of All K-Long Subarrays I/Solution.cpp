#include <functional>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x)
    {
        set<pair<int, int>> L, R; // L 存放频数 top x 的元素，R 存放其余元素
        unordered_map<int, int> cnt;
        int x_sum = 0;

        function<void(int)> add = [&](int x) -> void {
            pair<int, int> p = { cnt[x], x };
            if (p.first == 0)
                return;
            if (!L.empty() && p > *L.begin()) {
                L.insert(p);
                x_sum += p.first * p.second;
            } else
                R.insert(p);
        };

        function<void(int)> remove = [&](int x) -> void {
            pair<int, int> p = { cnt[x], x };
            if (p.first == 0)
                return;
            auto it = L.find(p);
            if (it != L.end()) {
                L.erase(it);
                x_sum -= p.first * p.second;
            } else
                R.erase(p);
        };

        function<void(void)> L2R = [&]() -> void {
            pair<int, int> p = *L.begin();
            L.erase(p);
            R.insert(p);
            x_sum -= p.first * p.second;
        };

        function<void(void)> R2L = [&]() -> void {
            pair<int, int> p = *R.rbegin();
            R.erase(p);
            L.insert(p);
            x_sum += p.first * p.second;
        };

        int n = ssize(nums);
        vector<int> ans;
        ans.reserve(n - k + 1);
        for (int r = 0; r < n; ++r) {
            int in = nums[r];
            remove(in);
            ++cnt[in];
            add(in);

            int l = r + 1 - k;
            if (l < 0)
                continue;

            while (!R.empty() && L.size() < x)
                R2L();
            while (L.size() > x)
                L2R();
            ans.emplace_back(x_sum);

            int out = nums[l];
            remove(out);
            --cnt[out];
            add(out);
        }
        return ans;
    }
};
