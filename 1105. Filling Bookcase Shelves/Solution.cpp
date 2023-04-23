#include <vector>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth)
    {
        vector<int> f(books.size() + 1, 0);
        for (size_t i = 0; i < books.size(); i++) {
            int thickness = books[i][0], height = books[i][1];
            f[i + 1] = f[i] + height;
            for (int j = i - 1; j >= 0 && thickness + books[j][0] <= shelfWidth; j--) {
                thickness += books[j][0];
                height = max(height, books[j][1]);
                f[i + 1] = min(f[i + 1], height + f[j]);
            }
        }
        return f.back();
    }
};
