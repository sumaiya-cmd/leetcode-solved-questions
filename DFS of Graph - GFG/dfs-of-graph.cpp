//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsTraversal (int v ,vector<bool>&visited, vector<int>&dfs , vector<int>adj[] , int currentVertex ){
        if(visited[currentVertex] == true)
            return ;
        
        visited[currentVertex] = true ;
        dfs.push_back(currentVertex) ;
        
        vector<int>neighbours = adj[currentVertex] ;
        
        for(auto adjNeigh : neighbours){
            dfsTraversal(v , visited , dfs, adj , adjNeigh) ;
        }
    } 
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>visited(V , false) ;
        vector<int>dfs ;
        
        dfsTraversal(V,visited , dfs , adj ,0 ) ;
        return dfs ;
    }
    
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends