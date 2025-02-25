#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Allocator {
public:
    Allocator(int n)
    {
        mem_table[0] = n;
    }

    int allocate(int size, int mID)
    {
        int beg_addr = -1;
        for (auto [k, v] : mem_table) {
            if (v >= size) {
                beg_addr = k;
                break;
            }
        }
        if (beg_addr == -1)
            return -1;
        id2blocks[mID].emplace_back(beg_addr, size);
        if (mem_table[beg_addr] > size)
            mem_table[beg_addr + size] = mem_table[beg_addr] - size;
        mem_table.erase(beg_addr);
        return beg_addr;
    }

    int freeMemory(int mID)
    {
        vector<pair<int, int>>& blocks = id2blocks[mID];
        int ans = 0;
        for (const pair<int, int>& block : blocks) {
            ans += block.second;
            auto it = mem_table.emplace(block.first, block.second).first;

            if (it != mem_table.begin()) {
                auto prev_it = prev(it);
                if (prev_it->first + prev_it->second == block.first) {
                    prev_it->second += block.second;
                    mem_table.erase(it);
                    it = prev_it;
                }
            }

            auto next_it = next(it);
            if (next_it != mem_table.end() && it->first + it->second == next_it->first) {
                it->second += next_it->second;
                mem_table.erase(next_it);
            }
        }
        id2blocks.erase(mID);
        return ans;
    }

private:
    map<int, int> mem_table;
    unordered_map<int, vector<pair<int, int>>> id2blocks;
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */
