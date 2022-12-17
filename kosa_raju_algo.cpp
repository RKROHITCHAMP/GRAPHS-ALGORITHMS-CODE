//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(int i,vector<int> adj[],vector<int> &vis,stack<int> &s)
	{
	    vis[i]=true;
	    for(auto it : adj[i])
	      if(!vis[it])
	        dfs(it,adj,vis,s);
	   s.push(i);
	    
	}
	void dfs2(int i,vector<int> adj[],vector<int> &vis)
	{
	    vis[i]=true;
	    for(auto it : adj[i])
	      if(!vis[it])
	        dfs2(it,adj,vis);
	}
    int kosaraju(int n, vector<int> adj[])
    {
        vector<int> vis(n,0);
	    stack<int> s;
	    for(int i=0;i<n;i++)
	      if(!vis[i])
	        dfs(i,adj,vis,s);
	    int ans=0; 
	    vector<int> adj2[n];
	    for(int i=0;i<n;i++)
	      {
	          vis[i]=0;
	          for(auto it : adj[i])
	          {
	              adj2[it].push_back(i);
	          }
	      }
	      
	    while(!s.empty())
	      {
	          auto curr = s.top();
	          s.pop();
	          if(!vis[curr])
	           {
	               ans++;
	               dfs2(curr,adj2,vis);
	           }
	          
	      }
	    return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
