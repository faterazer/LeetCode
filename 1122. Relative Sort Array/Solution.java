class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] hash = new int[1001];
        for (int n : arr1)
            hash[n]++;
        int index = 0;
        for (int n : arr2)
            while (hash[n]-- > 0)
                arr1[index++] = n;
        for (int i = 0; i < hash.length; i++)
            while (hash[i]-- > 0)
                arr1[index++] = i;
        return arr1;
    }
}
