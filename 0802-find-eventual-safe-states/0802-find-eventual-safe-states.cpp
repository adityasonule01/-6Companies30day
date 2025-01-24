class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outDegree(n, 0);  
        vector<vector<int>> reverseGraph(n); 
        queue<int> q;                 

      
        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
            outDegree[i] = graph[i].size();
            if (outDegree[i] == 0) {
                q.push(i); 
            }
        }

        vector<int> safe;

     
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int parent : reverseGraph[node]) {
                --outDegree[parent];
                if (outDegree[parent] == 0) {
                    q.push(parent);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};


