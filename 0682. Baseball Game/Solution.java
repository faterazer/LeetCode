import java.util.ArrayList;
import java.util.List;

class Solution {
    public int calPoints(String[] ops) {
        List<Integer> scores = new ArrayList<>();
        for (String op : ops) {
            switch (op) {
                case "+" -> {
                    int last1 = scores.get(scores.size() - 1);
                    int last2 = scores.get(scores.size() - 2);
                    scores.add(last1 + last2);
                }
                case "D" -> scores.add(scores.get(scores.size() - 1) * 2);
                case "C" -> scores.remove(scores.size() - 1);
                default -> scores.add(Integer.valueOf(op));
            }
        }
        int sum = 0;
        for (Integer score : scores) {
            sum += score;
        }
        return sum;
    }
}
