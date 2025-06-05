class Disjoint_set {
public:
    vector<int> parent;
    Disjoint_set(int n) {
        parent.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_par(int u) {
        if (u == parent[u]) {
            return parent[u];
        }
        return parent[u] = find_par(parent[u]);
    }

    void union_by_rank(int u, int v) {
        int up = find_par(u);
        int vp = find_par(v);
        if (up == vp) {
            return;
        } else if (up < vp) {
            parent[vp] = up;
        } else {
            parent[up] = vp;
        }
    }
};

class Solution {
public:
    Disjoint_set ds;
    Solution():ds(26){}

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < s1.size(); i++) {
            ds.union_by_rank(s1[i] - 'a', s2[i] - 'a');
        }
        string ans = "";
        for (auto it : baseStr) {
            int val = ds.find_par(it - 'a');
            ans += (val + 'a');
        }
        return ans;
    }
};