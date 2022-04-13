import java.util.*;

class RandomizedSet {
    private final List<Integer> data;
    private final Map<Integer, Integer> table;
    private final Random random;

    public RandomizedSet() {
        data = new ArrayList<>();
        table = new HashMap<>();
        random = new Random();
    }

    public boolean insert(int val) {
        if (table.containsKey(val)) {
            return false;
        } else {
            table.put(val, data.size());
            data.add(val);
            return true;
        }
    }

    public boolean remove(int val) {
        if (table.containsKey(val)) {
            int index = table.get(val);
            data.set(index, data.get(data.size() - 1));
            table.put(data.get(index), index);
            data.remove(data.size() - 1);
            table.remove(val);
            return true;
        } else {
            return false;
        }
    }

    public int getRandom() {
        return data.get(random.nextInt(0, data.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
