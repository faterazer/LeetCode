import java.util.ArrayList;
import java.util.List;

class OrderedStream {
    private final String[] arr;
    private final int size;
    private int ptr;

    public OrderedStream(int n) {
        arr = new String[n];
        size = n;
        ptr = 0;
    }

    public List<String> insert(int idKey, String value) {
        List<String> res = new ArrayList<>();
        int i = idKey - 1;
        arr[i] = value;
        if (i == ptr) {
            while (ptr < size && arr[ptr] != null) {
                res.add(arr[ptr]);
                ptr++;
            }
        }
        return res;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */
