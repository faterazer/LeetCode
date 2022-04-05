#include <vector>
using namespace std;

class NumArray_Binary_Indexed_Tree {
public:
    NumArray_Binary_Indexed_Tree(vector<int>& nums)
        : data(nums.size(), 0)
        , tree(data.size() + 1, 0)
    {
        for (size_t i = 0; i < nums.size(); ++i)
            update(i, nums[i]);
    }

    void update(int index, int val)
    {
        int diff = val - data[index];
        data[index] = val;
        for (int i = index + 1; i < tree.size(); i += lowbit(i))
            tree[i] += diff;
    }

    int sumRange(int left, int right)
    {
        return query(right + 1) - query(left);
    }

    int query(int index)
    {
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= lowbit(index);
        }
        return res;
    }

    static int lowbit(int x)
    {
        return x & -x;
    }

private:
    vector<int> data;
    vector<int> tree;
};

class NumArray_Segment_Tree {
public:
    NumArray_Segment_Tree(vector<int>& nums) : n(nums.size()), tree(nums.size() * 2)
    {
        for (int i = n; i < 2 * n; ++i)
            tree[i] = nums[i - n];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int index, int val)
    {
        index += n;
        int diff = val - tree[index];
        while (index > 0) {
            tree[index] += diff;
            index >>= 1;
        }
    }

    int sumRange(int left, int right)
    {
        left += n;
        right += n;
        int res = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                res += tree[left];
                left += 1;
            }
            if (right % 2 == 0) {
                res += tree[right];
                right -= 1;
            }
            left >>= 1;
            right >>= 1;
        }
        return res;
    }

private:
    vector<int> tree;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
