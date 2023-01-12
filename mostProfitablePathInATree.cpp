class Solution {
public:
    void dfs(int node, int tme, vector<vector<int> > &adj, vector<int> &t, int temp, int &ans, vector<int> &amount, vector<bool> &vis){
        vis[node] = true;
        if(t[node]>tme) temp+=amount[node];
        else if(t[node]==tme) temp+=(amount[node]/2);

        // cout<<node<<" -- "<<temp<<" "<<t[node]<<"\n";
        if(adj[node].size()==1 && node!=0){
            ans = max(ans, temp);
            return;
        }

        for(auto i:adj[node]){
            if(!vis[i])
                dfs(i, tme+1, adj, t, temp, ans, amount, vis);
        }
    }

    bool dfs1(int node, vector<vector<int> > &adj, vector<bool> &vis, int tme, vector<int> &t){
        vis[node] = true;
        t[node] = tme;
        if(node==0){
            return true;
        }

        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs1(i, adj, vis, tme+1, t)){
                    return true;
                }
            }
        }

        t[node] = INT_MAX;
        // vis[node] = false;
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();

        // vector<int> par(n, -1);
        vector<bool> vis(n, false);
        vector<int> t(n, INT_MAX);

        vector<vector<int> > adj(n);

        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            // par[i[1]] = i[0];
        }

        int id = bob;
        int tme = 0;

        dfs1(bob, adj, vis, tme, t);

        // while(id!=0){
        //     t[id] = tme;
        //     tme++;
        //     id = par[id];
        // }
        t[id] = tme;

        // for(auto i:t){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";

        int ans = INT_MIN;

        int temp = 0;
        tme = 0;
        vector<bool> v1(n, false);

        // for(auto i:adj[0]){
        //     tme = 0;
        //     temp = 0;
        dfs(0, tme, adj, t, temp, ans, amount, v1);
        // }
        
        return ans;
    }
};