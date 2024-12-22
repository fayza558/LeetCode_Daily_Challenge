class Solution {
    //Segment Tree for RMQ: Range Max Query
    vector<int> segTree;//Segment Tree

    void buildSegmentTree(vector<int>& heights,int start,int end,int st_idx){
        if(start==end){
            segTree[st_idx]=start;
            return;
        }

        int mid = start + (end-start)/2;
        buildSegmentTree(heights,start,mid,2*st_idx);
        buildSegmentTree(heights,mid+1,end,2*st_idx+1);

        segTree[st_idx] = heights[segTree[2*st_idx]] >= heights[segTree[2*st_idx+1]] ?
                       segTree[2*st_idx] : segTree[2*st_idx+1];
    }
    int rangeMaxQuery(vector<int>& heights,int qs,int qe,int start,int end,int st_idx=1){
        if(start>=qs and end<=qe)//Total Overlap
            return segTree[st_idx];
        if(start>qe or end<qs)//No Overlap
            return INT_MIN;
        
        //Partial Overlap
        int mid = start + (end-start)/2;
        int left_max = rangeMaxQuery(heights,qs,qe,start,mid,2*st_idx);
        int right_max = rangeMaxQuery(heights,qs,qe,mid+1,end,2*st_idx+1);

        if(left_max==INT_MIN)   return right_max;
        if(right_max==INT_MIN)  return left_max;
        return heights[left_max] >= heights[right_max] ?
               left_max : right_max;
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segTree = vector<int>(4*n+1);
        int st_idx=1;//Segment Tree Index: Root at index-1 segment tree implementations

        buildSegmentTree(heights,0,n-1,st_idx);

        vector<int> res;
        for(auto query: queries){
            int alice = min(query[0],query[1]);
            int bob = max(query[0],query[1]);

            if(alice==bob or heights[bob]>heights[alice]){
                res.push_back(bob);
                continue;
            }
            //Binary Search + RMQ (Range Max Query)
            int low = bob;
            int high = n-1;
            int ans=INT_MAX;
            while(low <= high){
                int mid = low + (high-low)/2;
                int rmq = rangeMaxQuery(heights,low,mid,0,n-1,st_idx);

                if(heights[rmq] > heights[alice]){
                    high = mid-1;
                    ans = min(ans,rmq);
                }else{
                    low = mid+1;
                }
            }
            if(ans==INT_MAX)    res.push_back(-1);
            else                res.push_back(ans);
        }
        return res;
    }
};
/*
//JAVA
import java.util.*;

class Solution {
    private int[] segTree; // Segment Tree

    private void buildSegmentTree(int[] heights, int start, int end, int stIdx) {
        if (start == end) {
            segTree[stIdx] = start;
            return;
        }

        int mid = start + (end - start) / 2;
        buildSegmentTree(heights, start, mid, 2 * stIdx);
        buildSegmentTree(heights, mid + 1, end, 2 * stIdx + 1);

        segTree[stIdx] = heights[segTree[2 * stIdx]] >= heights[segTree[2 * stIdx + 1]]
                ? segTree[2 * stIdx] : segTree[2 * stIdx + 1];
    }

    private int rangeMaxQuery(int[] heights, int qs, int qe, int start, int end, int stIdx) {
        if (start >= qs && end <= qe) // Total Overlap
            return segTree[stIdx];
        if (start > qe || end < qs) // No Overlap
            return Integer.MIN_VALUE;

        // Partial Overlap
        int mid = start + (end - start) / 2;
        int leftMax = rangeMaxQuery(heights, qs, qe, start, mid, 2 * stIdx);
        int rightMax = rangeMaxQuery(heights, qs, qe, mid + 1, end, 2 * stIdx + 1);

        if (leftMax == Integer.MIN_VALUE) return rightMax;
        if (rightMax == Integer.MIN_VALUE) return leftMax;

        return heights[leftMax] >= heights[rightMax] ? leftMax : rightMax;
    }

    public List<Integer> leftmostBuildingQueries(int[] heights, int[][] queries) {
        int n = heights.length;
        segTree = new int[4 * n + 1];
        int stIdx = 1; // Segment Tree Index: Root at index 1

        buildSegmentTree(heights, 0, n - 1, stIdx);

        List<Integer> res = new ArrayList<>();
        for (int[] query : queries) {
            int alice = Math.min(query[0], query[1]);
            int bob = Math.max(query[0], query[1]);

            if (alice == bob || heights[bob] > heights[alice]) {
                res.add(bob);
                continue;
            }

            // Binary Search + RMQ (Range Max Query)
            int low = bob, high = n - 1, ans = Integer.MAX_VALUE;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int rmq = rangeMaxQuery(heights, low, mid, 0, n - 1, stIdx);

                if (heights[rmq] > heights[alice]) {
                    high = mid - 1;
                    ans = Math.min(ans, rmq);
                } else {
                    low = mid + 1;
                }
            }
            res.add(ans == Integer.MAX_VALUE ? -1 : ans);
        }
        return res;
    }
}

#Python
class Solution:
    def __init__(self):
        self.segTree = []  # Segment Tree

    def buildSegmentTree(self, heights, start, end, st_idx):
        if start == end:
            self.segTree[st_idx] = start
            return

        mid = start + (end - start) // 2
        self.buildSegmentTree(heights, start, mid, 2 * st_idx)
        self.buildSegmentTree(heights, mid + 1, end, 2 * st_idx + 1)

        self.segTree[st_idx] = (self.segTree[2 * st_idx]
                                if heights[self.segTree[2 * st_idx]] >= heights[self.segTree[2 * st_idx + 1]]
                                else self.segTree[2 * st_idx + 1])

    def rangeMaxQuery(self, heights, qs, qe, start, end, st_idx=1):
        if start >= qs and end <= qe:  # Total Overlap
            return self.segTree[st_idx]
        if start > qe or end < qs:  # No Overlap
            return float('-inf')

        # Partial Overlap
        mid = start + (end - start) // 2
        left_max = self.rangeMaxQuery(heights, qs, qe, start, mid, 2 * st_idx)
        right_max = self.rangeMaxQuery(heights, qs, qe, mid + 1, end, 2 * st_idx + 1)

        if left_max == float('-inf'):
            return right_max
        if right_max == float('-inf'):
            return left_max

        return left_max if heights[left_max] >= heights[right_max] else right_max

    def leftmostBuildingQueries(self, heights, queries):
        n = len(heights)
        self.segTree = [0] * (4 * n + 1)
        st_idx = 1  # Segment Tree Index: Root at index 1

        self.buildSegmentTree(heights, 0, n - 1, st_idx)

        res = []
        for query in queries:
            alice = min(query[0], query[1])
            bob = max(query[0], query[1])

            if alice == bob or heights[bob] > heights[alice]:
                res.append(bob)
                continue

            # Binary Search + RMQ (Range Max Query)
            low, high, ans = bob, n - 1, float('inf')
            while low <= high:
                mid = low + (high - low) // 2
                rmq = self.rangeMaxQuery(heights, low, mid, 0, n - 1, st_idx)

                if heights[rmq] > heights[alice]:
                    high = mid - 1
                    ans = min(ans, rmq)
                else:
                    low = mid + 1

            res.append(-1 if ans == float('inf') else ans)
        return res

*/