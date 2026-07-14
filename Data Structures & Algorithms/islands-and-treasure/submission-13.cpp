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

            int m=grid.size();
            int n=grid[0].size();

            queue<pair<int,int>> q;

            // Put all gates into queue
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==0)
                    {
                        q.push({i,j});
                    }
                }
            }


            int r[4]={-1,1,0,0};
            int s[4]={0,0,1,-1};


            while(!q.empty())
            {
                int row=q.front().first;
                int col=q.front().second;

                q.pop();


                for(int k=0;k<4;k++)
                {
                    int newRow=row+r[k];
                    int newCol=col+s[k];


                    if(newRow<0 || newCol<0 || 
                       newRow>=m || newCol>=n ||
                       grid[newRow][newCol]==-1)
                    {
                        continue;
                    }


                    // Only update unvisited rooms
                    if(grid[newRow][newCol]==2147483647)
                    {
                        grid[newRow][newCol]=grid[row][col]+1;

                        q.push({newRow,newCol});
                    }
                }
            }
        }
};