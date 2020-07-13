import java.util.*;

class Solution {
    public int[] intersect_MK1(int[] nums1, int[] nums2) {
        if (nums1.length > nums2.length)
            return intersect_MK1(nums2, nums1);

        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int n : nums1)
            map.put(n, map.getOrDefault(n, 0) + 1);
        List<Integer> list = new ArrayList<Integer>();
        for (int n : nums2) {
            if (map.getOrDefault(n, 0) > 0) {
                list.add(n);
                map.put(n, map.get(n) - 1);
            }
        }
        int[] ret = new int[list.size()];
        for (int i = 0; i < ret.length; i++)
            ret[i] = list.get(i);
        return ret;
    }

    public int[] interest_MK2(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        List<Integer> list = new ArrayList<Integer>();
        int i = 0, j = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j])
                i++;
            else if (nums1[i] > nums2[j])
                j++;
            else {
                list.add(nums1[i]);
                i++;
                j++;
            }
        }
        int[] ret = new int[list.size()];
        for (i = 0; i < ret.length; i++)
            ret[i] = list.get(i);
        return ret;
    }
}
