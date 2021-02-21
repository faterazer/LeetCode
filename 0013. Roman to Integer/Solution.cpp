#include <iostream>
#include <map>
#include <string>
using namespace std;

#define I   1
#define V   5
#define X   10
#define L   50
#define C   100
#define D   500
#define M   1000

class Solution 
{
public:
    Solution();

    int romanToInt_MK1(string);
    int romanToInt_MK2(string);
private:
    map<char, int> mapping;
};

Solution::Solution()
{
    mapping['I'] = 1;
    mapping['V'] = 5;
    mapping['X'] = 10;
    mapping['L'] = 50;
    mapping['C'] = 100;
    mapping['D'] = 500;
    mapping['M'] = 1000;
}

int Solution::romanToInt_MK1(string s)
{
    char c, lastc = '\0';
    int result = 0;

    for (auto iter = s.cbegin(); iter != s.cend(); iter++) {
        c = *iter;
        switch (c) {
            case 'I':
                result += I;
                break;
            case 'V':
                if (lastc == 'I')
                    result += V - I * 2;
                else
                    result += V;
                break;
            case 'X':
                if (lastc == 'I')
                    result += X - I * 2;
                else
                    result += X;
                break;
            case 'L':
                if (lastc == 'X')
                    result += L - X * 2;
                else
                    result += L;
                break;
            case 'C':
                if (lastc == 'X')
                    result += C - X * 2;
                else
                    result += C;
                break;
            case 'D':
                if (lastc == 'C')
                    result += D - C * 2;
                else
                    result += D;
                break;
            case 'M':
                if (lastc == 'C')
                    result += M - C * 2;
                else
                    result += M;
            default:
                break;
        }
        lastc = c;
    }

    return result;
}

int Solution::romanToInt_MK2(string s)
{
    int result = 0;

    for (size_t i = 0; i < s.size(); ) {
        int nowi = mapping[s[i]], nexti;
        if (i+1 < s.size() && (nexti = mapping[s[i+1]]) > nowi) {
            result += nexti - nowi;
            i += 2;
        }
        else {
            result += nowi;
            i++;
        }
    }

    return result;
}