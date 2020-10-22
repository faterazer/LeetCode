import java.util.BitSet;

class MyHashSet {
    private BitSet barrel = new BitSet(1000001);

    /** Initialize your data structure here. */
    public MyHashSet() {

    }

    public void add(int key) {
        barrel.set(key, true);
    }

    public void remove(int key) {
        barrel.set(key, false);
    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return barrel.get(key);
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such: MyHashSet obj
 * = new MyHashSet(); obj.add(key); obj.remove(key); boolean param_3 =
 * obj.contains(key);
 */
