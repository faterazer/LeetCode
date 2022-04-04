class NumArray_Binary_Indexed_Tree {
    int[] tree, numArray;

    static public int lowBit(int x) {
        return x & -x;
    }

    public NumArray_Binary_Indexed_Tree(int[] nums) {
        numArray = new int[nums.length];
        tree = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            update(i, nums[i]);
        }
    }

    public void update(int index, int val) {
        int diff = val - numArray[index];
        numArray[index] = val;
        for (int i = index + 1; i < tree.length; i += lowBit(i)) {
            tree[i] += diff;
        }
    }

    public int query(int index) {
        int res = 0;
        while (index > 0) {
            res += tree[index];
            index -= lowBit(index);
        }
        return res;
    }

    public int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
}

class NumArray_Segment_Tree {
    private final int[] tree;

    public NumArray_Segment_Tree(int[] nums) {
        int n = nums.length;
        tree = new int[2 * n];
        System.arraycopy(nums, 0, tree, n, tree.length - n);
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    public void update(int index, int val) {
        index += tree.length / 2;
        int diff = val - tree[index];
        while (index > 0) {
            tree[index] += diff;
            index >>= 1;
        }
    }

    public int sumRange(int left, int right) {
        left += tree.length / 2;
        right += tree.length / 2;
        int sum = 0;
        while (left <= right) {
            if (left % 2 == 1) {
                sum += tree[left];
                left += 1;
            }
            if (right % 2 == 0) {
                sum += tree[right];
                right -= 1;
            }
            left >>= 1;
            right >>= 1;
        }
        return sum;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
