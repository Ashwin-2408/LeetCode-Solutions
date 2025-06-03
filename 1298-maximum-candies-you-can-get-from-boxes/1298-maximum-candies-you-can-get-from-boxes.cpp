class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int collected_candies = 0;
        stack<int> s;
        for (auto it : initialBoxes) {
            s.push(it);
        }
        vector<int> unopened_boxes;
        while (!s.empty()) {
            int box_index = s.top();
            s.pop();
            if (status[box_index] == 1) {
                status[box_index] = -1;
                collected_candies += candies[box_index];
                for (auto it : keys[box_index]) {
                    if (status[it] == 0) {
                        status[it] = 1;
                        if (find(unopened_boxes.begin(), unopened_boxes.end(),
                                 it) != unopened_boxes.end()) {
                            collected_candies += candies[it];
                            status[it] = -1;
                        }
                    }
                }
                for (auto it : containedBoxes[box_index]) {
                    s.push(it);
                }
            } else {
                unopened_boxes.push_back(box_index);
                for (auto it : containedBoxes[box_index]) {
                    s.push(it);
                    
                }
            }
        }
        return collected_candies;
    }
};