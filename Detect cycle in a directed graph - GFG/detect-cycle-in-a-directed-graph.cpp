//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool hasCycle( int c_vertex ,vector<int>adj[] , vector<bool>&visited , vector<bool>&recStack){
        visited[c_vertex] =true ;
        recStack[c_vertex] =true;
        
        vector<int>neighbours = adj[c_vertex] ;
        
        for(int neigh :neighbours ){
            if(visited[neigh]==false && hasCycle(neigh , adj , visited, recStack))
                return true ;
            
            else if(recStack[neigh]==true)
                return true ;
        }
        
        recStack[c_vertex]=false ;
        
        return false ;
        
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool>visited(V ,false);
        vector<bool>recStack(V, false) ;
        
        for(int currentVertex =0 ;currentVertex<V ;currentVertex++){
            if(visited[currentVertex] ==false && hasCycle(currentVertex, adj , visited ,recStack))
                return true ;
        }
        
        return false ;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends