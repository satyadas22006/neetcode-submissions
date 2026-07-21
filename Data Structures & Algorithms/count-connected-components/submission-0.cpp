#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <queue>
#include <map>
using namespace std;


class Solution 
{
    public: 
        void dfs(int node,vector<int>& vis,vector<vector<int>>& adj)
        {
            if(vis[node]==1)
            {
                return;
            }
            vis[node]=1;
            for(int i:adj[node])
            {
                dfs(i,vis,adj);
            }
        }
    public:
        int countComponents(int n, vector<vector<int>>& edges) 
        {
            vector<int> vis(n,0);
            //queue<int> q;
            vector<vector<int>> adj(n);
            for(auto &e:edges)
            {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            } // adj list bangya
            
            int ans=0;
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {dfs(i,vis,adj);
                    ans++;}
            }
            return ans;
        }
};
