#include <string.h>
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

int read4(char *buf4);

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
        int len = 0;
        while (buff[idx] && len < n)
            buf[len++] = buff[idx++];
        while (len < n)
        {
            int r = read4(buf + len);
            len += r;
            if (r < 4)
                break;
        }
        if (len > n)
        {
            strncpy(buff, buf + n, len - n);
            idx = 0;
            buff[len - n] = '\0';
            len = n;
        }
        return len;
    }

private:
    char buff[5] = {'\0'};
    int idx = 0;
};
