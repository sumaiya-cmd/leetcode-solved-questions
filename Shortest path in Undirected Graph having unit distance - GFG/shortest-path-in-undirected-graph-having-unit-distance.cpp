//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>graph[N];
        
        vector<int>dist(N,-1) ;
        
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        
        queue<pair<int,int>>q ;
        q.push({src,0});
        dist[src]=0 ;
        
        while(!q.empty()){
            int node= q.front().first ;
            int c_dist =q.front().second ;
            
            q.pop();
            
            for(auto neigh: graph[node]){
                if(dist[neigh]==-1){
                    dist[neigh]=1+c_dist;
                    q.push({neigh , dist[neigh]}) ;
                }
            }
        }
        
        return dist ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends