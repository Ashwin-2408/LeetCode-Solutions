class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<double, int>>> adjacencylist(n);
        for (int i = 0; i < edges.size(); i++) {
            adjacencylist[edges[i][0]].push_back({succProb[i], edges[i][1]});
        }

        vector<double> prob(n, 0.0);
        prob[start_node] = 1;
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<>> pq;
        pq.push({1, start_node});
        while (!pq.empty()) {
            int node = pq.top().second;
            double probability = pq.top().first;
            pq.pop();

            for (auto it : adjacencylist[node]) {
                if (prob[node] * it.first > prob[it.second]) {
                    prob[it.second] = prob[node] * it.first;
                    pq.push({prob[it.second], it.second});
                }
            }
        }

        return prob[end_node];
    }
};