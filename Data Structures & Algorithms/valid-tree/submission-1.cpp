#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;


class Solution 
{
    bool ans=true;
    public:
        bool dfs(int node,int parent,vector<int>& vis,vector<vector<int>>& adj)
        {
            vis[node]=1;

            for(auto x:adj[node])
            {
                if(x==parent)
                    continue;
                if(vis[x])
                    return false;
                if(!dfs(x,node,vis,adj))
                    return false;
            }
            return true;
        }
    public:
        bool validTree(int n, vector<vector<int>>& edges) 
        {
            if(edges.size()!=n-1)
            {
                return false;
            }

            vector<vector<int>> adj(n);

            for(auto &e:edges)
            {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }

            vector<int> vis(n,0);

            if(!dfs(0,0,vis,adj))
            {
                return false;
            }

            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    return false;
                }
            }

            return true;
        }
};
