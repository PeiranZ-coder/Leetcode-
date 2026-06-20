class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<int>inDeg(26,-1);
        int kind=0;
        for(auto &s:words){
            for(auto &c:s){
                if(inDeg[c-'a']==-1){
                    inDeg[c-'a']=0;kind++;
                }
            }
        }
        vector<vector<int>>grids(26);
        for(int i=0;i<words.size()-1;i++){
            int cnt=0;
            for(int j=0;j<min(words[i].size(),words[i+1].size());j++){
                if(words[i][j]!=words[i+1][j]){
                    grids[words[i][j]-'a'].push_back(words[i+1][j]-'a');
                    inDeg[words[i+1][j]-'a']++;
                    break;
                }
                cnt++;
            }
            if(cnt==words[i+1].size()&&cnt<words[i].size()) return "";
        }
        string ans;
        queue<int>q;
        for(int i=0;i<26;i++){
            if(!inDeg[i]){
                q.push(i);ans+='a'+i;
            }
        }
        while(q.size()){
            int x=q.front();q.pop();
            for(auto &v:grids[x]){
                if(--inDeg[v]==0){
                    q.push(v);ans+='a'+v;
                }
            }
        }
        return ans.size()==kind?ans:"";
    }
};
