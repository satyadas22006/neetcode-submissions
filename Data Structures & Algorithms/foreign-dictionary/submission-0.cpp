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
#include <math.h>
using namespace std;


class Solution 
{
    public:
        int diff_index(string a, string b)
        {
            int len = min(a.length(), b.length());
            for(int i = 0; i < len; i++)
            {
                if(a[i] != b[i])
                {
                    return i;
                }
            }
            return INT_MAX;
        }

        string topo(vector<vector<char>>& adj,vector<bool>& present)
        {
            vector<int> indegree(adj.size(),0);
            string ans="";
            //compute indegrees;
            for(int i=0;i<26;i++)
            {
                for(auto j:adj[i])
                {
                    indegree[j-'a']++;
                }
            }
            queue<int> q;
            for(int i=0;i<26;i++)
            {
                if(indegree[i]==0 && present[i])
                {
                    q.push(i);
                }
            }


            //kahn's algo
            while(!q.empty())
            {
                int top=q.front();
                q.pop();
                ans.push_back('a'+top);
                for(char i:adj[top])
                {
                    indegree[i-'a']--;
                    if(indegree[i-'a']==0)
                    {
                        q.push(i-'a');
                    }
                }
            }

            int totalpresent=0;
            for(int i=0;i<26;i++)
            {
                if(present[i])
                {
                    totalpresent++;
                }
            }
            if(totalpresent!=ans.length())
            {
                return "";
            }

            return ans;
        }

        string foreignDictionary(vector<string>& words) 
        {
            //rank and char
            //make topo sort
            //make the graph first then make topo sort
            vector<vector<char>> adj(26);
            vector<bool> present(26,false);
            for(string &word:words)
            {
                for(char c:word)
                {
                    present[c-'a']=true;
                }
            }
            //string topo="";
            //making the adj list for DAG
            for(int i=0;i<words.size()-1;i++)
            {
                string& a=words[i];
                string& b=words[i+1];
                int res=diff_index(a,b);
                if(res==INT_MAX)
                {
                    //equal words or nothing to add in adj list
                    if(a.length()>b.length())
                    {
                        return "";
                    }
                    continue;
                }
                
                int u=a[res]-'a';
                char v=b[res];

                bool alreadyExists=false;
                for(char c: adj[u])
                {
                    if(c==v)
                    {
                        alreadyExists=true;
                        break;
                    }
                }

                if(!alreadyExists)
                {
                    adj[u].push_back(v);
                }
            }
            return topo(adj,present);
        }
};
