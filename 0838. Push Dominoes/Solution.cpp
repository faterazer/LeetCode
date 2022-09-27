#include <string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes)
    {
        int i = 0;
        char l = 'L';
        while (i < dominoes.size()) {
            int j = i;
            while (dominoes[j] == '.')
                ++j;
            char r = j < dominoes.size() ? dominoes[j] : 'R';
            if (l == r) {
                while (i < j)
                    dominoes[i++] = r;
            } else if (l == 'R' && r == 'L') {
                int k = j - 1;
                while (i < k) {
                    dominoes[i++] = 'R';
                    dominoes[k--] = 'L';
                }
            }
            l = r;
            i = j + 1;
        }
        return dominoes;
    }
};
