import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> mapper = new HashMap<>();
        for (String path : paths) {
            String[] values = path.split(" ");
            String dirPath = values[0];
            for (int i = 1; i < values.length; i++) {
                int l = values[i].indexOf('('), r = values[i].indexOf(')');
                String filename = values[i].substring(0, l);
                String content = values[i].substring(l + 1, r);
                if (!mapper.containsKey(content)) {
                    mapper.put(content, new ArrayList<>());
                }
                List<String> fileList = mapper.get(content);
                fileList.add(dirPath + "/" + filename);
            }
        }
        List<List<String>> res = new ArrayList<>();
        for (List<String> value : mapper.values()) {
            if (value.size() > 1) {
                res.add(value);
            }
        }
        return res;
    }
}
