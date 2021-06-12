// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n);
};

int Solution::firstBadVersion(int n)
{
    int left = 0, right = n, mid;
    while (left < right) {
        mid = left + ((right - left) >> 1);
        if (isBadVersion(mid))
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
