class Solution {
    private int findRoot(int[] tree, int x) {
        if (tree[x] == x) {
            return x;
        }
        tree[x] = findRoot(tree, tree[x]);
        return tree[x];
    }

    public boolean equationsPossible(String[] equations) {
        int[] tree = new int[26];
        for (int i = 0; i < tree.length; i++) {
            tree[i] = i;
        }
        for (String equation : equations) {
            int a = equation.charAt(0) - 'a', b = equation.charAt(3) - 'a';
            if (equation.charAt(1) == '=') {
                tree[findRoot(tree, a)] = findRoot(tree, b);
            }
        }
        for (String equation : equations) {
            int a = equation.charAt(0) - 'a', b = equation.charAt(3) - 'a';
            if (equation.charAt(1) == '!' && findRoot(tree, a) == findRoot(tree, b)) {
                return false;
            }
        }
        return true;
    }
}
