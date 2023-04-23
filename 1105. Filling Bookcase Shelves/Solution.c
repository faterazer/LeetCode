#include <math.h>
#include <string.h>

int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelfWidth)
{
    int f[booksSize + 1];
    f[0] = 0;
    for (int i = 0; i < booksSize; i++) {
        int thickness = books[i][0], height = books[i][1];
        f[i + 1] = f[i] + height;
        for (int j = i - 1; j >= 0 && thickness + books[j][0] <= shelfWidth; j--) {
            thickness += books[j][0];
            height = fmax(height, books[j][1]);
            f[i + 1] = fmin(f[i + 1], height + f[j]);
        }
    }
    return f[booksSize];
}
