#include <algorithm>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> outerTrees_Jarvis(vector<vector<int>>& trees)
    {
        /*
        Time complexity: O(n^2)
        Space complexity: O(n)
        */
        int n = trees.size();
        if (n < 4)
            return trees;

        int left_most = 0;
        for (int i = 1; i < trees.size(); ++i)
            if (trees[i][0] < trees[left_most][0])
                left_most = i;

        vector<vector<int>> res;
        unordered_set<int> visited;
        int p = left_most;
        do {
            int q = (p + 1) % n;
            for (int r = 0; r < n; ++r)
                if (cross(trees[p], trees[q], trees[r]) < 0)
                    q = r;

            for (int r = 0; r < n; ++r) {
                if (visited.count(r) || r == p || r == q)
                    continue;
                if (cross(trees[p], trees[q], trees[r]) == 0) {
                    res.emplace_back(trees[r]);
                    visited.emplace(r);
                }
            }
            if (!visited.count(q)) {
                res.emplace_back(trees[q]);
                visited.emplace(q);
            }
            p = q;
        } while (p != left_most);
        return res;
    }

    vector<vector<int>> outerTrees_Graham(vector<vector<int>>& trees)
    {
        /*
        Time complexity: O(nlgn)
        Space complexity: O(n)
        */
        int n = trees.size();
        if (n < 4)
            return trees;

        int left_most = 0;
        for (int i = 1; i < n; ++i)
            if (trees[i][0] < trees[left_most][0])
                left_most = i;
        swap(trees[0], trees[left_most]);
        sort(trees.begin() + 1, trees.end(), [&](const vector<int>& a, const vector<int>& b) {
            int c = cross(trees[0], a, b);
            if (c != 0)
                return c > 0;
            else
                return distance(trees[0], a) < distance(trees[0], b);
        });

        int r = n - 2;
        while (r >= 0 && cross(trees[0], trees[n - 1], trees[r]) == 0)
            --r;
        reverse(trees.begin() + r + 1, trees.end());

        stack<int> stk;
        stk.emplace(0);
        stk.emplace(1);
        for (int i = 2; i < n; ++i) {
            int top = stk.top();
            stk.pop();
            while (!stk.empty() && cross(trees[stk.top()], trees[top], trees[i]) < 0) {
                top = stk.top();
                stk.pop();
            }
            stk.emplace(top);
            stk.emplace(i);
        }

        vector<vector<int>> res;
        while (!stk.empty()) {
            res.emplace_back(trees[stk.top()]);
            stk.pop();
        }
        return res;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees)
    {
        int n = trees.size();
        if (n < 4)
            return trees;

        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        vector<int> hull;
        vector<int> visited(n, 0);
        hull.emplace_back(0);
        for (int i = 1; i < n; ++i) {
            while (hull.size() > 1 && cross(trees[hull[hull.size() - 2]], trees[hull.back()], trees[i]) < 0) {
                visited[hull.back()] = 0;
                hull.pop_back();
            }
            visited[i] = true;
            hull.emplace_back(i);
        }
        int m = hull.size();
        for (int i = n - 2; i >= 0; i--) {
            if (!visited[i]) {
                while (cross(trees[hull[hull.size() - 2]], trees[hull.back()], trees[i]) < 0) {
                    visited[hull.back()] = 0;
                    hull.pop_back();
                }
                visited[i] = 1;
                hull.emplace_back(i);
            }
        }
        hull.pop_back();

        vector<vector<int>> res;
        for (const int& e : hull)
            res.emplace_back(trees[e]);
        return res;
    }

private:
    int cross(const vector<int>& p, const vector<int>& q, const vector<int>& r)
    {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    int distance(const vector<int>& p, const vector<int>& q)
    {
        return (q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1]);
    }
};
