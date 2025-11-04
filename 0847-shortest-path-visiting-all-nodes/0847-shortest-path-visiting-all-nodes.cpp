class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        int hops = 0;
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front().first;
                int mask = q.front().second;
                q.pop();
                if (mask == (1 << n) - 1) {
                    return hops;
                }
                for (auto it : graph[node]) {
                    int new_mask = mask | (1 << it);
                    if (!visited[it][new_mask]) {
                        visited[it][new_mask] = true;
                        q.push({it, new_mask});
                    }
                }
            }
            hops++;
        }
        return hops;
    }
};