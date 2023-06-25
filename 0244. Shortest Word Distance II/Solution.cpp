#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class WordDistance {
public:
    WordDistance(vector<string>& wordsDict)
    {
        int n = wordsDict.size();
        for (int i = 0; i < n; i++)
            s2idxs[wordsDict[i]].emplace_back(i);
    }

    int shortest(string word1, string word2)
    {
        vector<int> arr1 = s2idxs[word1], arr2 = s2idxs[word2];
        int m = arr1.size(), n = arr2.size();
        int i = 0, j = 0, res = INT_MAX;
        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                res = min(res, arr2[j] - arr1[i]);
                i++;
            } else {
                res = min(res, arr1[i] - arr2[j]);
                j++;
            }
        }
        return res;
    }

private:
    unordered_map<string, vector<int>> s2idxs;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
