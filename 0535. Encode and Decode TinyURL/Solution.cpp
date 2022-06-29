#include <random>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    Solution()
    {
        for (int i = 0; i < 26; ++i) {
            if (i < 10)
                candidates.emplace_back('0' + i);
            candidates.emplace_back('a' + i);
            candidates.emplace_back('A' + i);
        }
        dis = uniform_int_distribution<unsigned>(0, candidates.size() + 1);
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string key;
        for (int i = 0; i < 4; ++i)
            key.push_back(candidates[dis(rand_gen)]);
        while (code2url.count(key))
            key.push_back(candidates[dis(rand_gen)]);
        code2url[key] = longUrl;
        return "http://tinyurl.com/" + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        int idx = shortUrl.rfind('/') + 1;
        string key = shortUrl.substr(idx);
        return code2url[key];
    }

private:
    unordered_map<string, string> code2url;
    vector<char> candidates;
    default_random_engine rand_gen;
    uniform_int_distribution<unsigned> dis;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
