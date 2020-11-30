import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> counter = new HashMap<>();
        for (String cpdomain : cpdomains) {
            int spaceIndex = cpdomain.indexOf(' ');
            int n = Integer.parseInt(cpdomain.substring(0, spaceIndex));
            String domain = cpdomain.substring(spaceIndex + 1);
            counter.put(domain, counter.getOrDefault(domain, 0) + n);
            for (int i = domain.indexOf('.'); i != -1; i = domain.indexOf('.', i)) {
                String subdomain = domain.substring(++i);
                counter.put(subdomain, counter.getOrDefault(subdomain, 0) + n);
            }
        }
        List<String> ret = new ArrayList<>();
        for (String k : counter.keySet()) {
            ret.add(counter.get(k) + " " + k);
        }
        return ret;
    }
}
