//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int>queue ;
        queue.push(0) ;
        
        vector<bool>visited (V , false);
        vector<int>bfs ;
        
        
        while(!queue.empty()){
            int currentVertex = queue.front();
            queue.pop();
            
            if(visited[currentVertex] == true)
                continue ;
            
            visited[currentVertex ]=true ;
            bfs.push_back(currentVertex) ;
            
            vector<int>neighbours = adj[currentVertex] ;
            for(auto adjNeigh : neighbours)
                queue.push(adjNeigh);
        }
        
        return bfs ;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends