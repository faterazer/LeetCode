#include <unordered_map>
using namespace std;

class FrequencyTracker {
public:
    FrequencyTracker()
    {
    }

    void add(int number)
    {
        --freq_cnt[num2freq[number]];
        ++freq_cnt[++num2freq[number]];
    }

    void deleteOne(int number)
    {
        if (num2freq[number] == 0)
            return;

        --freq_cnt[num2freq[number]];
        ++freq_cnt[--num2freq[number]];
    }

    bool hasFrequency(int frequency)
    {
        return freq_cnt[frequency];
    }

private:
    unordered_map<int, int> num2freq;
    unordered_map<int, int> freq_cnt;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
