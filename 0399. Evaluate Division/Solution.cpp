#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int n)
        : tree(n, -1)
        , weight(n, 1.0)
    {
    }

    void unionSet(int a, int b, double value)
    {
        int rootA = findRoot(a), rootB = findRoot(b);
        if (rootA != rootB) {
            tree[rootA] = rootB;
            weight[rootA] = value / weight[a] * weight[b];
        }
    }

    double compute(int a, int b)
    {
        int rootA = findRoot(a), rootB = findRoot(b);
        if (rootA != rootB)
            return -1.0;
        else
            return weight[a] / weight[b];
    }

private:
    int findRoot(int x)
    {
        if (tree[x] == -1)
            return x;
        int root = findRoot(tree[x]);
        weight[x] *= weight[tree[x]];
        tree[x] = root;
        return root;
    }

    vector<int> tree;
    vector<double> weight;
};

class Solution {
public:
    vector<double> calcEquation_UF(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        int n = equations.size();
        UnionFind unionFind(n * 2);
        unordered_map<string, int> idMap;
        int id = 0;
        for (size_t i = 0; i < equations.size(); ++i) {
            string a = equations[i][0], b = equations[i][1];
            if (!idMap.count(a))
                idMap[a] = id++;
            if (!idMap.count(b))
                idMap[b] = id++;
            unionFind.unionSet(idMap[a], idMap[b], values[i]);
        }

        vector<double> res;
        for (const vector<string>& query : queries) {
            if (!idMap.count(query[0]) || !idMap.count(query[1])) {
                res.emplace_back(-1.0);
                continue;
            }
            int a = idMap[query[0]], b = idMap[query[1]];
            res.emplace_back(unionFind.compute(a, b));
        }
        return res;
    }

    vector<double> calcEquation_dfs(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        unordered_map<string, unordered_map<string, double>> table;
        for (size_t i = 0; i < equations.size(); ++i) {
            string a = equations[i][0], b = equations[i][1];
            table[a][b] = values[i];
            table[b][a] = 1 / values[i];
        }
        vector<double> res;
        for (const vector<string>& query : queries) {
            string a = query[0], b = query[1];
            unordered_set<string> visited;
            res.emplace_back(helper(table, visited, a, b));
        }
        return res;
    }

private:
    double helper(const unordered_map<string, unordered_map<string, double>>& table, unordered_set<string>& visited, const string& a, const string& b)
    {
        if (visited.count(a) || !table.count(a))
            return -1.0;
        if (table.at(a).count(b))
            return table.at(a).at(b);
        visited.emplace(a);
        for (auto& it : table.at(a)) {
            if (!visited.count(it.first)) {
                double r = helper(table, visited, it.first, b);
                if (r != -1.0)
                    return it.second * r;
            }
        }
        visited.erase(a);
        return -1.0;
    }
};
