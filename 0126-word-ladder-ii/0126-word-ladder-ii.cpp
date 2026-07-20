class Solution {
private:
    int cmp(string & s1, string & s2){
        int n = s1.size();
        int diff = 0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) diff++;
        }

        return diff;
    }
    void backT(vector<vector<string>>& ans, vector<string>& iter, vector<string>& wordList, unordered_map<int,unordered_set<int>>& um,vector<vector<int>>& adj,int node ,int i, string& beginWord){
        iter.push_back(wordList[node]);
        if(i==2){
            iter.push_back(beginWord);
            ans.push_back(iter);
            iter.pop_back();
        }
        else{
            for(int j :adj[node]){
                if(um[i-1].find(j)!=um[i-1].end()) backT(ans,iter,wordList,um,adj,j,i-1, beginWord);
            }
        }
        iter.pop_back();
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int endIn = -1;
        for(int i=0;i<n;i++){
            if(wordList[i]==endWord){
                endIn = i;
                break;
            }
        } 
        if(endIn==-1) return {};

        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(cmp(wordList[i],wordList[j])==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> dis(n,1e9);
        queue<int> q;
        unordered_map<int,unordered_set<int>> um;
        for(int i=0;i<n;i++){
            if(cmp(beginWord,wordList[i])==1){
                dis[i] = 2;
                um[2].insert(i);
                q.push(i);
            }
        }

        bool found = false;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int it: adj[node]){
                if(dis[node]+1<dis[it]){
                    dis[it] = dis[node]+1;
                    um[dis[it]].insert(it);
                    if(it==endIn){
                        found = true;
                        break;
                    } 
                    q.push(it);
                }
            }

            if(found) break;
        }

        if(dis[endIn]==1e9) return {};
        vector<vector<string>> ans;
        vector<string> iter;
        backT(ans,iter,wordList,um,adj,endIn,dis[endIn], beginWord);

        for(auto& it:ans){
            reverse(it.begin(),it.end());
        }

        return ans;
    }
};