import java.util.HashSet;
import java.util.Set;

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        for (int num : nums1)
            set1.add(num);
        Set<Integer> set2 = new HashSet<>();
        for (int num : nums2)
            set2.add(num);
        set1.retainAll(set2);
        int[] ret = new int[set1.size()];
        int i = 0;
        for (Integer num : set1)
            ret[i++] = num;
        return ret;
    }
}
