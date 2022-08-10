class Solution {
    private int[] parse(String s) {
        String[] tokens = s.split("(?=[+-])");
        int factor = 0, val = 0;
        for (String token : tokens) {
            if (token.equals("+x") || token.equals("x")) {
                factor += 1;
            } else if (token.equals("-x")) {
                factor -= 1;
            } else if (token.contains("x")) {
                factor += Integer.parseInt(token.substring(0, token.length() - 1));
            } else {
                val += Integer.parseInt(token);
            }
        }
        return new int[]{factor, val};
    }

    public String solveEquation(String equation) {
        String[] subEquation = equation.split("=");
        int[] left = parse(subEquation[0]);
        int[] right = parse(subEquation[1]);
        int factor = left[0] - right[0];
        int val = right[1] - left[1];
        if (factor == 0 && val == 0) {
            return "Infinite solutions";
        } else if (factor == 0) {
            return "No solution";
        } else {
            return "x=" + (val / factor);
        }
    }
}
