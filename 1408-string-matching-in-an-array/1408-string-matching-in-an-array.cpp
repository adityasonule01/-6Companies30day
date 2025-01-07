class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        unordered_set<string> result; // To avoid duplicates
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    result.insert(words[i]); // Insert into set to avoid duplicates
                    break;
                }
            }
        }
        
        return vector<string>(result.begin(), result.end()); // Convert set to vector
    }
};
