import java.util.HashMap;
import java.util.Map;

class Record {
    public Record(int degree, int begin) {
        this.degree = degree;
        this.begin = begin;
    }

    public int degree;
    public int begin;
}

class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Record> map = new HashMap<>();
        int minLen = 1, maxDegree = 0;
        for (int i = 0; i < nums.length; i++) {
            if (!map.containsKey(nums[i])) {
                map.put(nums[i], new Record(0, i));
            }
            Record record = map.get(nums[i]);
            record.degree += 1;
            map.put(nums[i], record);
            if (record.degree > maxDegree) {
                maxDegree = record.degree;
                minLen = i - record.begin + 1;
            } else if (record.degree == maxDegree)
                minLen = Math.min(minLen, i - record.begin + 1);
        }
        return minLen;
    }
}
