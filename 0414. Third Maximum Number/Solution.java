import java.util.TreeSet;

class Solution {
    public int thirdMax(int[] nums) {
        TreeSet<Integer> top3 = new TreeSet<>();
        for (int num : nums) {
            top3.add(num);
            if (top3.size() > 3) {
                top3.remove(top3.first());
            }
        }
        return top3.size() < 3 ? top3.last() : top3.first();
    }
}
