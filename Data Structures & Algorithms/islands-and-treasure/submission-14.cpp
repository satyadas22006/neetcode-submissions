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
    public:
        void islandsAndTreasure(vector<vector<int>>& grid) 
        {
            if(grid.empty() || grid[0].empty())
            {
                return;
            }
            int r=grid.size();
            int c=grid[0].size();
            vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(),0));
            queue<pair<int,int>> q;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if(grid[i][j]==0)
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
            
            //now we have all the rooms with us
            int m[4]={-1,1,0,0};
            int n[4]={0,0,1,-1};
            while(!q.empty())
            {
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nr=cr+ m[i];
                    int nc=cc+ n[i];
                    if(nr>=0 && nc>=0 && nr<r && nc<c && grid[nr][nc]==2147483647 && vis[nr][nc]==0)
                    {
                        vis[nr][nc]=1;
                        grid[nr][nc]=grid[cr][cc]+1;
                        q.push({nr,nc});
                    }
                }
            }
        }
};
