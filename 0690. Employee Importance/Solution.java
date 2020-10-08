import java.util.HashMap;
import java.util.Map;

class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> map = new HashMap<>();
        for (Employee employee : employees) {
            map.put(employee.id, employee);
        }
        return this.dfs(map, id);

    }

    private int dfs(Map<Integer, Employee> map, int id) {
        int total = map.get(id).importance;
        for (int subId : map.get(id).subordinates)
            total += this.dfs(map, subId);
        return total;
    }
}
