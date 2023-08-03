//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>g[N] ;
        stack<int>s ;
        vector<int>vis(N, 0) ;
        
        for(auto i:edges){
            int src =i[0] ;
            int dest =i[1] ;
            int dist =i[2] ;
            
            g[src].push_back({dest, dist}) ;
        }
        
        for(int i=0 ;i<N;i++){
            if(!vis[i]){
                dfs(i , s, vis ,g); 
            }
        }
        
        vector<int>dist(N,1e9) ;
        dist[0]=0 ;
        
        while(!s.empty()){
            int node = s.top() ;
            s.pop() ;
            
            for(auto i :g[node]){
                int n_node =i.first ;
                int wt =i.second ;
                
                if(dist[n_node]>wt+ dist[node] ){
                    dist[n_node] =wt+dist[node] ;
                }
            }
        }
        
        for(int i=0 ;i<N;i++){
            if(dist[i]==1e9)
                dist[i]=-1 ;
        }
        
        return dist ;
    }
    
    void dfs(int node , stack<int>&s , vector<int>&vis,vector<pair<int,int>>g[]){
        vis[node] =1 ;
        
        for(auto i:g[node]){
            if(!vis[i.first])
                dfs(i.first , s, vis, g);
        }
        
        s.push(node); 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends