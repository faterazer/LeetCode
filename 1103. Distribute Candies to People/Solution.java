class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int n = (int)(Math.sqrt(2 * candies + 0.25) - 0.5);
        int rows = n / num_people;
        int cols = n % num_people;
        int[] ret = new int[num_people];
        for (int i = 0; i < num_people; i++) {
            ret[i] = (int)((rows - 1) * rows * 0.5 * num_people) + rows * (i + 1);
            if (i < cols)
                ret[i] += rows * num_people + i + 1;
        }
        ret[cols] += candies - (1 + n) * n * 0.5;
        return ret;
    }
}
