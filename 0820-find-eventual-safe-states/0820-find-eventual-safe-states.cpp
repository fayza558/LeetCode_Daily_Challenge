class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n); // Reverse the edges
        vector<int> inDegree(n, 0);          // To track in-degree of nodes
        
        // Build the reverse graph and calculate in-degrees
        for (int i = 0; i < n; ++i) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
            inDegree[i] = graph[i].size(); // Original out-degree becomes in-degree
        }

        // Use a queue to process nodes with in-degree 0
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) q.push(i); // Terminal nodes
        }

        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : reverseGraph[node]) {
                --inDegree[neighbor]; // Reduce the in-degree
                if (inDegree[neighbor] == 0) q.push(neighbor); // Add new terminal nodes
            }
        }

        // Sort safe nodes in ascending order
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
