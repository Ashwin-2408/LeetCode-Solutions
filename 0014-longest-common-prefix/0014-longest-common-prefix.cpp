class Trie {
public:
    Trie* Link[26];
    bool end = false;
    int childcount = 0;

    void insert(string word, Trie* root) {
        Trie* curr = root;
        for (auto it : word) {
            if (curr->Link[it - 'a'] == nullptr) {
                curr->Link[it - 'a'] = new Trie();
                curr->childcount++;
            }
            curr = curr->Link[it - 'a'];
        }
        curr->end = true;
    }
    string walk(string word, Trie* root) {
        int i = 0;
        Trie* curr = root;
        for (auto it : word) {
            if (curr->childcount == 1 && curr->end != true) {
                i++;
            } else {
                break;
            }
            curr = curr->Link[it-'a'];
        }

        return word.substr(0, i);
    }
};

class Solution {

public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* root = new Trie();
        for (auto it : strs) {
            root->insert(it, root);
        }
        return root->walk(strs[0], root);
    }
};