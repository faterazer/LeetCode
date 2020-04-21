/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
public:
    int guessNumber(int n);
};

int Solution::guessNumber(int n)
{
    int left = 1, right = n, mid;
    while (left < right) {
        mid = left + ((right - left) >> 1);
        int flag = guess(mid);
        if (flag == -1)
            right = mid - 1;
        else if (flag == 1)
            left = right + 1;
        else
            break;
    }
    return mid;
}
