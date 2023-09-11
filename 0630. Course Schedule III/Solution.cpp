#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses)
    {
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int cur_day = 0;
        priority_queue<int> pq;
        for (const vector<int>& course : courses) {
            if (cur_day + course[0] <= course[1]) {
                cur_day += course[0];
                pq.emplace(course[0]);
            } else if (!pq.empty() && course[0] < pq.top()) {
                cur_day -= pq.top() - course[0];
                pq.pop();
                pq.emplace(course[0]);
            }
        }
        return pq.size();
    }
};
