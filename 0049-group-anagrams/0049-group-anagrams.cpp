class Solution {
public:
    static bool custom_comparator(pair<int, string> a,
                           pair<int, string> b) {
        return a.second > b.second;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<pair<int, string>> ana;
        for (int i = 0; i < strs.size(); i++) {
            ana.push_back({i, strs[i]});
        }
        for (auto& it : ana) {
            sort(it.second.begin(), it.second.end());
        }
        sort(ana.begin(), ana.end(), custom_comparator);
        vector<vector<string>> ans;
        vector<string> temp;
        string curr = "";
        for (int i = 0; i < ana.size(); i++) {
            if (i == 0) {
                temp.push_back(strs[ana[i].first]);
                curr = ana[i].second;

            } else {
                if (ana[i].second == curr) {
                    temp.push_back(strs[ana[i].first]);

                } else {
                    ans.push_back(temp);
                    temp.clear();
                    temp.push_back(strs[ana[i].first]);
                    curr = ana[i].second;
                }
            }
        }
        ans.push_back(temp);
        return ans;
    }
};