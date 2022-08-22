class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return (int) Math.ceil(Math.log(buckets) / Math.log((double) minutesToTest / minutesToDie + 1) - 1e-5);
    }
}
