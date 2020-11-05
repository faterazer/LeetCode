#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] != newColor)
            dfsFill(image, sr, sc, newColor);
        return image;
    }

private:
    void dfsFill(vector<vector<int>> &image, int r, int c, int newColor)
    {
        int m = image.size(), n = image[0].size();
        int originColor = image[r][c];
        image[r][c] = newColor;
        for (const auto &d : dirs) {
            int x = r + d.first;
            int y = c + d.second;
            if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] != originColor)
                continue;
            dfsFill(image, x, y, newColor);
        }
    }

    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
