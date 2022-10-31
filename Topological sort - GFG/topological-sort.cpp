//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>inDegree(V , 0) ;
        vector<bool>visited(V,false) ;
        vector<int>ans ;
        
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
            
            ans.push_back(c_vertex) ;
            visited[c_vertex]=true ;
            
            vector<int>neighbours = adj[c_vertex] ;
            
            for(int neigh:neighbours){
                inDegree[neigh]-=1 ;
                
                if(inDegree[neigh]==0)
                    queue.push(neigh) ;
            }
        }
        
        
        // reverse(ans.begin(),ans.end());
        
        return ans ;
    
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends