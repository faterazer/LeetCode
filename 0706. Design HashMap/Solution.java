class MyHashMap {
    class Node {
        public int key;
        public int value;
        public Node next;

        public Node() {
        }

        public Node(int key, int value) {
            this.key = key;
            this.value = value;
            this.next = null;
        }
    }

    private Node[] bucket = new Node[769];

    /** Initialize your data structure here. */
    public MyHashMap() {
    }

    /** value will always be non-negative. */
    public void put(int key, int value) {
        int idx = key % bucket.length;
        if (bucket[idx] == null) {
            bucket[idx] = new Node(key, value);
        } else {
            Node node = bucket[idx], pre = null;
            while (node != null) {
                if (node.key == key) {
                    node.value = value;
                    return;
                }
                pre = node;
                node = node.next;
            }
            pre.next = new Node(key, value);
        }
    }

    /**
     * Returns the value to which the specified key is mapped, or -1 if this map
     * contains no mapping for the key
     */
    public int get(int key) {
        for (Node node = bucket[key % bucket.length]; node != null; node = node.next)
            if (node.key == key)
                return node.value;
        return -1;
    }

    /**
     * Removes the mapping of the specified value key if this map contains a mapping
     * for the key
     */
    public void remove(int key) {
        Node tp = new Node(), newHead = tp;
        tp.next = bucket[key % bucket.length];
        for (; tp.next != null; tp = tp.next) {
            if (tp.next.key == key) {
                tp.next = tp.next.next;
                bucket[key % bucket.length] = newHead.next;
                return;
            }
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such: MyHashMap obj
 * = new MyHashMap(); obj.put(key,value); int param_2 = obj.get(key);
 * obj.remove(key);
 */
