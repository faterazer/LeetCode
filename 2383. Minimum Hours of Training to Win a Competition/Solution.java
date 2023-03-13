import java.util.Arrays;

class Solution {
    public int minNumberOfHours(int initialEnergy, int initialExperience, int[] energy, int[] experience) {
        int res = Math.max(Arrays.stream(energy).sum() + 1 - initialEnergy, 0);
        for (int exp : experience) {
            if (exp >= initialExperience) {
                res += exp + 1 - initialExperience;
                initialExperience = exp + 1;
            }
            initialExperience += exp;
        }
        return res;
    }
}
