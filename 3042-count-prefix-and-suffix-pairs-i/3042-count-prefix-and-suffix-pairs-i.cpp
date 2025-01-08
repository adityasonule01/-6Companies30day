#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

using namespace std;

class TrieNode {
public:
    unordered_map<int, shared_ptr<TrieNode>> children;
    int count = 0;
};

class Trie {
public:
    Trie() : root(make_shared<TrieNode>()) {}

    int insert(const string& word) {
        int n = word.length();
        int pairCount = 0;
        auto node = root;
        for (int i = 0; i < n; ++i) {
            int key = hash(word[i], word[n - 1 - i]);
            if (node->children.find(key) == node->children.end()) {
                node->children[key] = make_shared<TrieNode>();
            }
            node = node->children[key];
            pairCount += node->count;
        }
        ++node->count;
        return pairCount;
    }

private:
    shared_ptr<TrieNode> root;

    int hash(char prefix, char suffix) {
        return 26 * (prefix - 'a') + (suffix - 'a');
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long result = 0;
        Trie trie;
        for (const auto& word : words) {
            result += trie.insert(word);
        }
        return result;
    }
};
