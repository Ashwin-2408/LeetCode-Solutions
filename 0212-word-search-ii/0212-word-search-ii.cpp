class Node {
public:
    Node* links[26];
    bool flag = false;
    void add_word(string word) {
        Node* curr = this;
        for (auto it : word) {
            if (curr->links[it - 'a'] == nullptr) {
                curr->links[it - 'a'] = new Node();
            }
            curr = curr->links[it - 'a'];
        }
        curr->flag = true;
    }
};

class Solution {
private:
public:
    vector<string> ans;
    Node* root;
    vector<vector<bool>> visited;
    Solution() { root = new Node(); }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        for (auto word : words) {
            root->add_word(word);
        }
        visited.assign(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, "");
            }
        }

        return ans;
    }
    void dfs(vector<vector<char>>& board, int row, int column, Node* node,
             string word) {
        int n = board.size();
        int m = board[0].size();
        if (row < 0 || row >= n || column < 0 || column >= m ||
            node->links[board[row][column] - 'a'] == nullptr ||
            visited[row][column] == true) {
            return;
        }
        visited[row][column] = true;
        node = node->links[board[row][column] - 'a'];
        word += board[row][column];
        if (node->flag) {
            ans.push_back(word);
            node->flag = false;
        }
        dfs(board, row + 1, column, node, word);
        dfs(board, row - 1, column, node, word);
        dfs(board, row, column + 1, node, word);
        dfs(board, row, column - 1, node, word);
        visited[row][column] = false;
    }
};