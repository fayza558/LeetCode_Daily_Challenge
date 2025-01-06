class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> minOperations(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (boxes[j] == '1') {
                    minOperations[i] += abs(i - j);
                }
            }
        }
        
        return minOperations;
    }
};
