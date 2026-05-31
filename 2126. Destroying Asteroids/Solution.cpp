#include <algorithm>
#include <queue>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    {
        priority_queue<int, vector<int>, greater<>> pq(asteroids.begin(), asteroids.end());
        int max_mass = ranges::max(asteroids);
        while (!pq.empty() && mass < max_mass) {
            int asteroid = pq.top();
            pq.pop();
            if (mass < asteroid)
                return false;
            else
                mass += asteroid;
        }
        return true;
    }
};
