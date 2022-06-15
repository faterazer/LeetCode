#include <algorithm>
#include <functional>
#include <queue>
#include <random>
#include <set>
#include <string>
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

    bool operator<(const Edge& right) const
    {
        return len < right.len;
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
        return x != right.x ? x < right.x : y < right.y;
    }
};

class BIT {
public:
    BIT(int n)
        : tree(n, INT_MAX)
        , id_rec(n, -1)
    {
    }

    static int lowbit(int x)
    {
        return x & -x;
    }

    int query(int idx)
    {
        int minval = INT_MAX, res = -1, n = tree.size();
        while (idx < n) {
            if (tree[idx] < minval) {
                minval = tree[idx];
                res = id_rec[idx];
            }
            idx += lowbit(idx);
        }
        return res;
    }

    void update(int idx, int val, int id)
    {
        while (idx > 0) {
            if (tree[idx] > val) {
                tree[idx] = val;
                id_rec[idx] = id;
            }
            idx -= lowbit(idx);
        }
    }

private:
    vector<int> tree, id_rec;
};

class DisjointSetUnion {
public:
    DisjointSetUnion(int n)
        : tree(n, -1)
    {
    }

    bool unionSet(int a, int b)
    {
        int root_a = findRoot(a), root_b = findRoot(b);
        if (root_a == root_b)
            return false;
        tree[root_b] = root_a;
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

    vector<int> tree;
};

class Solution {
public:
    int minCostConnectPoints_MK1(vector<vector<int>>& points) // Kruskal
    {
        vector<Edge> edges;
        for (size_t i = 0; i < points.size(); ++i)
            for (size_t j = i + 1; j < points.size(); ++j)
                edges.emplace_back(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
        sort(edges.begin(), edges.end());

        int res = 0, cnt = 1, n = points.size();
        DisjointSetUnion dsu(n);
        for (size_t i = 0; i < edges.size() && cnt < n; ++i) {
            if (dsu.unionSet(edges[i].x, edges[i].y)) {
                res += edges[i].len;
                ++cnt;
            }
        }
        return res;
    }

    int minCostConnectPoints_MK2(vector<vector<int>>& points) // Prim
    {
        int n = points.size(), cnt = 0, res = 0;
        vector<bool> in_MST(n, false);
        vector<int> min_dist(n, INT_MAX);
        min_dist[0] = 0;
        while (cnt < n) {
            int cur_node = -1, cur_dist = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (!in_MST[i] && min_dist[i] < cur_dist) {
                    cur_node = i;
                    cur_dist = min_dist[i];
                }
            }
            in_MST[cur_node] = true;
            min_dist[cur_node] = cur_dist;
            res += cur_dist;
            ++cnt;
            for (int i = 0; i < n; ++i)
                if (!in_MST[i])
                    min_dist[i] = min(min_dist[i], abs(points[i][0] - points[cur_node][0]) + abs(points[i][1] - points[cur_node][1]));
        }
        return res;
    }

    int minCostConnectPoints_MK3(vector<vector<int>>& points) // Kruskal (Optimized)
    {
        vector<Edge> edges = buildEdges(points);
        sort(edges.begin(), edges.end());

        int res = 0, cnt = 1, n = points.size();
        DisjointSetUnion dsu(n);
        for (size_t i = 0; i < edges.size() && cnt < n; ++i) {
            if (dsu.unionSet(edges[i].x, edges[i].y)) {
                res += edges[i].len;
                ++cnt;
            }
        }
        return res;
    }

private:
    vector<Edge> buildEdges(vector<vector<int>>& points)
    {
        vector<Pos> pos;
        vector<Edge> edges;
        pos.reserve(points.size());
        for (size_t i = 0; i < points.size(); ++i)
            pos.emplace_back(Pos(points[i][0], points[i][1], i));
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
        vector<int> id_map;
        id_map.reserve(pos.size());
        for (const Pos& p : pos)
            id_map.emplace_back(p.y - p.x);
        sort(id_map.begin(), id_map.end());
        id_map.erase(unique(id_map.begin(), id_map.end()), id_map.end());

        BIT bit(id_map.size() + 1);
        for (int i = pos.size() - 1; i >= 0; --i) {
            int idx = lower_bound(id_map.begin(), id_map.end(), pos[i].y - pos[i].x) - id_map.begin() + 1;
            int j = bit.query(idx);
            if (j != -1)
                edges.emplace_back(Edge(pos[i].id, pos[j].id, abs(pos[i].x - pos[j].x) + abs(pos[i].y - pos[j].y)));
            bit.update(idx, pos[i].x + pos[i].y, i);
        }
    }
};
