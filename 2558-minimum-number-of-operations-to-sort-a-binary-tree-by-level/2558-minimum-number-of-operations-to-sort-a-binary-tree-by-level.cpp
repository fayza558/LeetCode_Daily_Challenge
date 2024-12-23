/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int cntr=0;
        while(q.size())
        {
            int n=q.size();//levels 
            vector<int>v(n);
            for(int i=0;i<n;i++)
            {
                 auto cur=q.front();q.pop();
                 v[i]=cur->val;
                 if(cur->left) q.push(cur->left);
                 if(cur->right) q.push(cur->right);
            }
            vector<int>sorted=v;
            sort(sorted.begin(),sorted.end());
            for(int i=0;i<n;i++)
            {
                int index=i;
                while(v[i]!=sorted[index])
                {
                      index++;
                }
                if(i!=index) 
                {
                    swap(sorted[i],sorted[index]);
                    cntr++;
                }
            }
        }
        return cntr;
    }
};
