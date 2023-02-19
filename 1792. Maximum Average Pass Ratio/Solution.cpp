#include <queue>
#include <vector>
using namespace std;

class Solution {
    struct cmp {
        bool operator()(const pair<double, double>& left, const pair<double, double>& right)
        {
            return (left.first + 1) / (left.second + 1) - left.first / left.second < (right.first + 1) / (right.second + 1) - right.first / right.second;
        }
    };

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        priority_queue<pair<double, double>, vector<pair<double, double>>, cmp> pq;
        for (const vector<int>& p : classes)
            pq.emplace(p[0], p[1]);
        for (int i = 0; i < extraStudents; i++) {
            pair<double, double> p = pq.top();
            pq.pop();
            pq.emplace(p.first + 1, p.second + 1);
        }
        double sum = 0.0;
        while (!pq.empty()) {
            pair<double, double> p = pq.top();
            pq.pop();
            sum += p.first / p.second;
        }
        return sum / classes.size();
    }
};
