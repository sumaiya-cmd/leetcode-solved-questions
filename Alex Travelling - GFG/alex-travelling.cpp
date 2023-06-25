//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int,int>>adj[n+1];
        
        for(auto i:flights){
            adj[i[0]].push_back({i[1] ,i[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq ;
        pq.push({0,k});
        
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        
        while(!pq.empty()){
            int c_dist = pq.top().first ;
            int c_node= pq.top().second;
            
            pq.pop();
            
            for(auto it :adj[c_node]){
                int n_dist =it.second ;
                int n_node=it.first;
                
                if(c_dist+n_dist<dist[n_node]){
                    dist[n_node] =c_dist+n_dist ;
                    pq.push({dist[n_node]  , n_node});
                }
            }
        }
        
        int maxi =INT_MIN;
        
        for(int i=1;i<=n ;i++){
            maxi =max(dist[i] , maxi);
        }
        
        return maxi==1e9?-1 :maxi ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends