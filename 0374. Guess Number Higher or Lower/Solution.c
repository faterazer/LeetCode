/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 */

int guess(int num);

int guessNumber(int n)
{
    int l = 1, r = n, m;
    while (l < r) {
        m = l + ((r - l) >> 1);
        if (guess(m) < 0) {
            r = m - 1;
        } else if (guess(m) > 0) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return l;
}
