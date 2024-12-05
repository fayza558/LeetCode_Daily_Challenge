class Solution {
public:
    bool canChange(string start, string target) {
        vector<int>v1,v2;
        int n=start.size();
        for(int i=0;i<n;i++)
        {
           if(start[i]!='_') v1.push_back(i);
           if(target[i]!='_') v2.push_back(i);
        }
        if(v1.size()!=v2.size()) return false;
        for(int i=0;i<v1.size();i++)
        {
            if(start[v1[i]]!=target[v2[i]])return false;
            if(start[v1[i]]=='L' &&v1[i]<v2[i]) return false ;
            if(start[v1[i]]=='R' &&v1[i]>v2[i]) return false ;
        }
        return true;
    }
};