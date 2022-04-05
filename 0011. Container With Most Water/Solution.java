class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int res = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                res = Math.max(res, (right - left) * height[left]);
                left += 1;
            } else {
                res = Math.max(res, (right - left) * height[right]);
                right -= 1;
            }
        }
        return res;
    }
}
