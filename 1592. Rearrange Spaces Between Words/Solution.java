class Solution {
    public String reorderSpaces(String text) {
        String[] words = text.trim().split("\\s+");
        int spaces = (int)text.chars().filter(c -> c == ' ').count();
        int gap = words.length > 1 ? spaces / (words.length - 1) : 0;
        int tail = spaces - gap * (words.length - 1);
        return String.join(" ".repeat(gap), words) + " ".repeat(tail);
    }
}
