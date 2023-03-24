class Solution {
    public int maximalNetworkRank(int n, int[][] roads) {
        int[] degrees = new int[n];
        for (int[] road : roads) {
            ++degrees[road[0]];
            ++degrees[road[1]];
        }

        int max1 = 0, max2 = 0;
        for (int degree : degrees) {
            if (degree > max1) {
                max2 = max1;
                max1 = degree;
            } else if (degree > max2 && degree < max1) {
                max2 = degree;
            }
        }

        int count1 = 0, count2 = 0;
        for (int degree : degrees) {
            if (degree == max1) {
                ++count1;
            }
            if (degree == max2) {
                ++count2;
            }
        }

        if (count1 == 1) {
            int edgeCount = 0;
            for (int[] road : roads) {
                if (degrees[road[0]] == max1 && degrees[road[1]] == max2 || degrees[road[0]] == max2 && degrees[road[1]] == max1) {
                    ++edgeCount;
                }
            }
            return edgeCount == count2 ? max1 + max2 - 1 : max1 + max2;
        } else {
            int edgeCount = 0, limit = count1 * (count1 - 1) / 2;
            for (int[] road : roads) {
                if (degrees[road[0]] == max1 && degrees[road[1]] == max1) {
                    ++edgeCount;
                }
            }
            return edgeCount == limit ? max1 * 2 - 1 : max1 * 2;
        }
    }
}
