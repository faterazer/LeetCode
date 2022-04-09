import java.util.*;

class Solution {
    public int[] topKFrequent_MK1(int[] nums, int k) {
        if (k == nums.length) {
            return nums;
        }

        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        PriorityQueue<Integer> heap = new PriorityQueue<>(Comparator.comparingInt(count::get));
        for (Integer key : count.keySet()) {
            heap.add(key);
            if (heap.size() > k) {
                heap.poll();
            }
        }

        int[] res = new int[k];
        for (int i = 0; i < k; ++i) {
            res[i] = heap.remove();
        }
        return res;
    }

    public int[] topKFrequent_MK2(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }
        List<int[]> buff = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            buff.add(new int[]{entry.getKey(), entry.getValue()});
        }
        kthElement(buff, 0, buff.size() - 1, k);
        int[] res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = buff.get(i)[0];
        }
        return res;
    }

    private void kthElement(List<int[]> arr, int left, int right, int k) {
        if (k < left || k > right) {
            return;
        }
        int index = left + (int) (Math.random() * (right - left));
        int pivot = arr.get(index)[1];
        Collections.swap(arr, left, index);
        index = left;
        for (int i = left + 1; i <= right; ++i) {
            if (arr.get(i)[1] >= pivot) {
                Collections.swap(arr, ++index, i);
            }
        }
        Collections.swap(arr, left, index);
        if (index < k) {
            kthElement(arr, index + 1, right, k);
        } else if (index > k) {
            kthElement(arr, left, index - 1, k);
        }
    }
}
