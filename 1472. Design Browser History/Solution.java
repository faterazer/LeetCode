import java.util.ArrayList;
import java.util.List;

class BrowserHistory {
    private final List<String> history = new ArrayList<>();
    private int length = 0;
    private int index = -1;

    public BrowserHistory(String homepage) {
        history.add(homepage);
        index++;
        length++;
    }

    public void visit(String url) {
        if (history.size() == index + 1) {
            history.add(url);
            index++;
        } else {
            history.set(++index, url);
        }
        length = index + 1;
    }

    public String back(int steps) {
        if (index - steps >= 0) {
            index -= steps;
        } else {
            index = 0;
        }
        return history.get(index);
    }

    public String forward(int steps) {
        if (index + steps < length) {
            index += steps;
        } else {
            index = length - 1;
        }
        return history.get(index);
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */
