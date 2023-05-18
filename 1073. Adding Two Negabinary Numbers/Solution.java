import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        List<Integer> res = new ArrayList<>();
        int carry = 0, i = arr1.length - 1, j = arr2.length - 1;
        while (i >= 0 || j >= 0 || carry != 0) {
            if (i >= 0) {
                carry += arr1[i--];
            }
            if (j >= 0) {
                carry += arr2[j--];
            }
            res.add(carry & 1);
            carry = -(carry >> 1);
        }
        while (res.size() > 1 && res.get(res.size() - 1) == 0) {
            res.remove(res.size() - 1);
        }
        Collections.reverse(res);
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}
