class Solution {
public:
    bool cycle(int node, vector<vector<int> > &adj, vector<bool> &vis, vector<bool> &curCycle){
        vis[node] = true;
        curCycle[node] = true;

        for(auto i:adj[node]){
            if(!vis[i]){
                if(cycle(i, adj, vis, curCycle)){
                    return true;
                }
            }
            else if(curCycle[i]){
                return true;
            }
        }

        curCycle[node] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adj(n);
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> vis(n, false);
        vector<bool> curCycle(n, false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(cycle(i, adj, vis, curCycle)){
                    return false;
                }
            }
        }

        return true;
    }
};