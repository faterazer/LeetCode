class Solution {
    public boolean reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty) {
            if (tx < ty) {
                ty = ty % tx;
            } else {
                tx = tx % ty;
            }
        }
        return (sx == tx && ty >= sy && (ty - sy) % sx == 0) || (sy == ty && tx >= sx && (tx - sx) % ty == 0);
    }
}
