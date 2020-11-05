int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfsFill(int **image, int m, int n, int r, int c, int newColor)
{
    int originColor = image[r][c];
    image[r][c] = newColor;
    int x, y;
    for (int i = 0; i < 4; i++) {
        x = r + dirs[i][0];
        y = c + dirs[i][1];
        if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] != originColor)
            continue;
        dfsFill(image, m, n, x, y, newColor);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int newColor, int *returnSize, int **returnColumnSizes)
{
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    if (image[sr][sc] != newColor)
        dfsFill(image, imageSize, imageColSize[0], sr, sc, newColor);
    return image;
}
