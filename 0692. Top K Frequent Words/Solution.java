import java.util.*;

class Solution {
    public List<String> topKFrequent_MK1(String[] words, int k) {
        Map<String, Integer> counter = new HashMap<>();
        for (String word : words) {
            counter.put(word, counter.getOrDefault(word, 0) + 1);
        }
        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue().equals(b.getValue()) ? b.getKey().compareTo(a.getKey()) : a.getValue() - b.getValue());
        for (Map.Entry<String, Integer> entry : counter.entrySet()) {
            pq.offer(entry);
            if (pq.size() > k) {
                pq.poll();
            }
        }

        List<String> res = new ArrayList<>();
        while (!pq.isEmpty()) {
            res.add(pq.poll().getKey());
        }
        Collections.reverse(res);
        return res;
    }

    public List<String> topKFrequent_MK1(String[] words, int k) {
        return Arrays.stream(words)
                     .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()))
                     .entrySet()
                     .stream()
                     .sorted((o1, o2) -> {
                        if (o1.getValue().equals(o2.getValue())) {
                            return o1.getKey().compareTo(o2.getKey());
                        } else {
                                return o2.getValue().compareTo(o1.getValue());
                        }
                     })
                     .map(Map.Entry::getKey)
                     .limit(k)
                     .collect(Collectors.toList());
    }
}
