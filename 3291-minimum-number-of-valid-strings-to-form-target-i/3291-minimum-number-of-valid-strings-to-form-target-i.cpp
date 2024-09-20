class TrieNode {
    public: 
    TrieNode *child[26];
    TrieNode() {
        for(int i=0; i<26; i++) {
            child[i] = NULL;
        }
    }
};

class Trie {
    public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string &s) {
        TrieNode* t = root;
        for(int i=0; i<s.size(); i++) {
            int key = s[i] - 'a';
            if(t->child[key] == NULL) {
                t->child[key] = new TrieNode();
            }
            t = t->child[key];
        }
    }
    vector<int> search(string &s, int start) {
        vector<int>ans;
        TrieNode* t = root;
        for(int i=start; i<s.size(); i++) {
            int key = s[i] - 'a';
            if(t->child[key]==NULL) break;
            t = t->child[key];
            ans.push_back(i - start + 1);
        }
        return ans;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        Trie* t = new Trie();
        for(int i=0; i<words.size(); i++) {
            t->insert(words[i]);
        }
        int n = target.size();
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=0; i<=n; i++) {
            if(dp[i] == INT_MAX) continue;
            vector<int> length = t->search(target, i);
            for(int x:length) {
                dp[i+x] = min(dp[i+x], dp[i]+1);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};