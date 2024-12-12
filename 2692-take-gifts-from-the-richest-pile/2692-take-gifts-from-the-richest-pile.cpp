class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pr(gifts.begin(),gifts.end());
        while(k--)
        {
            int x=sqrt(pr.top());
            pr.pop();
            pr.push(x);
        }
        long long sum=0;
        while(pr.size()) sum+=pr.top(),pr.pop();
        return sum;
        
    }
};