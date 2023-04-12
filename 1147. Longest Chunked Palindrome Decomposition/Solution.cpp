#include <string>
using namespace std;

class Solution {
public:
    int longestDecomposition(string text)
    {
        return helper(text, 0, text.size() - 1);
    }

private:
    int helper(const string& text, int left, int right)
    {
        if (left > right)
            return 0;
        if (left == right)
            return 1;
        if (text[left] == text[right])
            return 2 + helper(text, left + 1, right - 1);
        int mid = left + ((right - left) >> 1);
        for (size_t i = text.find(text[right], left); i != string::npos && i <= mid; i = text.find(text[right], i + 1)) {
            int n = i - left + 1;
            if (text.substr(left, n) == text.substr(right - n + 1, n))
                return 2 + helper(text, left + n, right - n);
        }
        return 1;
    }
};
