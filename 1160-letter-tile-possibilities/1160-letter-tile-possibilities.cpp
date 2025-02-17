class Solution {
public:
   bitset<8>vis;
   unordered_set<string>st;
   void solve(string s,string cur){
        st.insert(cur);
        for(int i=0;i<s.size();i++){
            if(vis[i])continue;
            vis[i]=true;
            solve(s,cur+s[i]);
            vis[i]=false;
        }
   }
    int numTilePossibilities(string tiles) {   
         solve(tiles,"");
         return st.size()-1;
    }
};