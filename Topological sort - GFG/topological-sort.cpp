//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	 bool hasCycle( int c_vertex ,vector<int>adj[] , vector<bool>&visited ,vector<int>&order, vector<bool>&recStack){
        visited[c_vertex] =true ;
        recStack[c_vertex] =true;
        
        
        vector<int>neighbours = adj[c_vertex] ;
        
        for(int neigh :neighbours ){
            if(visited[neigh]==false && hasCycle(neigh , adj , visited,order, recStack))
                return true ;
            
            else if(recStack[neigh]==true)
                return true ;
        }
        
        recStack[c_vertex]=false ;
        order.push_back(c_vertex) ;
        
        return false ;
        
        
    }
    
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>order ;
	    vector<bool>visited(V, false ) ;
	    vector<bool>recStack(V, false ) ;
	    
	    for(int currentVertex =0 ;currentVertex<V; currentVertex++) {
	        if(visited[currentVertex]==false && hasCycle( currentVertex ,adj , visited , order , recStack))
	            return {};
	    }
	    
	   // reverse(order.begin() ,order.end()) ;
	    return order ;
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