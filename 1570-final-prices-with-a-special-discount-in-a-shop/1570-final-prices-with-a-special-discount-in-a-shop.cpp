class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res = prices;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && prices[j] > prices[i]) j++;
            if (j < n) { 
                res[i] -= prices[j];
            }
        }
        return res;
    }
};
