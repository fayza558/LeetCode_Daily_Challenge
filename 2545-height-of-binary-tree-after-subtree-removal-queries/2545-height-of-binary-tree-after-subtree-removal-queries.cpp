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
    int depth[100001],removed[100001];
    int calDepth(TreeNode* root){
        if(!root)
           return -1;
        if(depth[root->val]!=-1)
        return depth[root->val];
        return depth[root->val]=max(calDepth(root->left),calDepth(root->right))+1;

    }
    void dfs(TreeNode* root,int curDepth,int maxDepth){
        if(!root)
         return ;
        removed[root->val]=maxDepth;
        dfs(root->left,curDepth+1,max(maxDepth,curDepth+calDepth(root->right)+1));
        dfs(root->right,curDepth+1,max(maxDepth,curDepth+calDepth(root->left)+1));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        memset(depth,-1,sizeof depth);
        dfs(root,0,0);
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i]=removed[queries[i]];
            
        }
        return ans;
    }
};