//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>inDegree(V , 0) ;
        vector<bool>visited(V, false) ;
        
        for(int c_vertex= 0;c_vertex<V ;c_vertex++){
            for(int neigh:adj[c_vertex])
                inDegree[neigh]++ ;
        }
        
        queue<int>queue ;
        
        for(int c_vertex =0 ; c_vertex<V ; c_vertex++){
            if(inDegree[c_vertex]==0)
                queue.push(c_vertex) ;
        }
        
        while(!queue.empty()){
            
            int c_vertex = queue.front();
            queue.pop();
            
            if(visited[c_vertex]==true)
                continue ;
            
            visited[c_vertex]=true ;
            
            vector<int>neighbours = adj[c_vertex] ;
            
            for(int neigh:neighbours){
                inDegree[neigh]-=1 ;
                
                if(inDegree[neigh]==0)
                    queue.push(neigh) ;
            }
        }
        
        for(int i =0 ;i<V ;i++){
            if(visited[i]==false)
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