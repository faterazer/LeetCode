#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    int x, y, len;

    Edge(int _x, int _y, int _len)
        : x(_x)
        , y(_y)
        , len(_len)
    {
    }

    bool operator<(const Edge& a) const
    {
        return len < a.len;
    }
};

struct Pos {
    int x, y, id;

    Pos(int _x, int _y, int _id)
        : x(_x)
        , y(_y)
        , id(_id)
    {
    }

    bool operator<(const Pos& right) const
    {
        return x == right.x ? y < right.y : x < right.x;
    }
};

class BIT {
public:
    BIT(int _n)
        : n(_n)
        , tree(_n, INT_MAX)
        , id_rec(_n, -1)
    {
    }

    static int lowbit(int x)
    {
        return x & -x;
    }

    void update(int pos, int val, int id)
    {
        while (pos > 0) {
            if (tree[pos] > val) {
                tree[pos] = min(tree[pos], val);
                id_rec[pos] = id;
            }
            pos -= lowbit(pos);
        }
    }

    int query(int pos)
    {
        int minval = INT_MAX, res = -1;
        while (pos < n) {
            if (tree[pos] < minval) {
                minval = tree[pos];
                res = id_rec[pos];
            }
            pos += lowbit(pos);
        }
        return res;
    }

private:
    int n;
    vector<int> tree, id_rec;
};

class DisjointSetUnion {
public:
    DisjointSetUnion(int _n)
        : tree(_n, -1)
        , rank(_n, 1)
    {
    }

    bool unionSet(int x, int y)
    {
        int root_x = findRoot(x), root_y = findRoot(y);
        if (root_x == root_y)
            return false;
        tree[root_y] = root_x;
        rank[root_x] += rank[root_y];
        return true;
    }

private:
    int findRoot(int x)
    {
        if (tree[x] == -1)
            return x;
        int root = findRoot(tree[x]);
        tree[x] = root;
        return root;
    }

    vector<int> tree, rank;
};

class Solution {
public:
    int minCostConnectPoints_MK1(vector<vector<int>>& points) // Kruskal
    {
        vector<Edge> edges;
        for (size_t i = 0; i < points.size(); ++i)
            for (size_t j = i + 1; j < points.size(); ++j)
                edges.emplace_back(Edge(i, j, manhattanDistance(points[i], points[j])));
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.len < b.len;
        });
        vector<int> tree(points.size(), -1);
        int count = tree.size(), res = 0;
        for (size_t i = 0; i < edges.size() && count > 1; ++i) {
            int root_a = findRoot(tree, edges[i].x);
            int root_b = findRoot(tree, edges[i].y);
            int dist = edges[i].len;
            if (root_a != root_b) {
                res += dist;
                count -= 1;
                tree[root_b] = root_a;
            }
        }
        return res;
    }

    int minCostConnectPoints_MK2(vector<vector<int>>& points) // Prim
    {
        int res = 0, count = 0;
        vector<int> in_MST(points.size(), 0);
        vector<int> min_dist(points.size(), INT_MAX);
        min_dist[0] = 0;
        while (count < points.size()) {
            int cur_node = -1, cur_dist = INT_MAX;
            for (int i = 0; i < min_dist.size(); ++i) {
                if (!in_MST[i] && min_dist[i] < cur_dist) {
                    cur_node = i;
                    cur_dist = min_dist[i];
                }
            }
            in_MST[cur_node] = 1;
            res += cur_dist;
            count += 1;
            for (int i = 0; i < points.size(); ++i) {
                if (in_MST[i])
                    continue;
                int dist = manhattanDistance(points[cur_node], points[i]);
                if (dist < min_dist[i])
                    min_dist[i] = dist;
            }
        }
        return res;
    }

    int minCostConnectPoints_MK3(vector<vector<int>>& points) // Kruskal (Optimized)
    {
        vector<Edge> edges = build_edges(points);

        int n = points.size();
        DisjointSetUnion dsu(n);
        sort(edges.begin(), edges.end());
        int res = 0, count = n;
        for (size_t i = 0; i < edges.size() && count; ++i) {
            if (dsu.unionSet(edges[i].x, edges[i].y)) {
                res += edges[i].len;
                --count;
            }
        }
        return res;
    }

private:
    vector<Edge> build_edges(const vector<vector<int>>& points)
    {
        vector<Pos> pos;
        for (size_t i = 0; i < points.size(); ++i)
            pos.emplace_back(points[i][0], points[i][1], i);
        vector<Edge> edges;
        build(pos, edges);
        for (Pos& p : pos)
            swap(p.x, p.y);
        build(pos, edges);
        for (Pos& p : pos)
            p.x *= -1;
        build(pos, edges);
        for (Pos& p : pos)
            swap(p.x, p.y);
        build(pos, edges);
        return edges;
    }

    void build(vector<Pos>& pos, vector<Edge>& edges)
    {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        vector<int> idx_map(n);
        for (int i = 0; i < n; ++i)
            idx_map[i] = pos[i].y - pos[i].x;
        sort(idx_map.begin(), idx_map.end());
        idx_map.erase(unique(idx_map.begin(), idx_map.end()), idx_map.end());
        BIT bit(idx_map.size() + 1);
        for (int i = n - 1; i >= 0; --i) {
            int idx = lower_bound(idx_map.begin(), idx_map.end(), pos[i].y - pos[i].x) - idx_map.begin() + 1;
            int point_id = bit.query(idx);
            if (point_id != -1) {
                int distance = abs(pos[point_id].x - pos[i].x) + abs(pos[point_id].y - pos[i].y);
                edges.emplace_back(pos[i].id, pos[point_id].id, distance);
            }
            bit.update(idx, pos[i].x + pos[i].y, i);
        }
    }

    int manhattanDistance(const vector<int>& a, const vector<int>& b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    int findRoot(vector<int>& tree, int x)
    {
        if (tree[x] == -1)
            return x;
        int res = findRoot(tree, tree[x]);
        tree[x] = res;
        return res;
    }
};
