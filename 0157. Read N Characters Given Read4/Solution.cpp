#include <algorithm>
using namespace std;

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

int read4(char *buf4);

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int res = 0;
        for (int i = 0; i < n; i += 4)
        {
            res += read4(buf);
            buf += 4;
        }
        return min(res, n);
    }
};
