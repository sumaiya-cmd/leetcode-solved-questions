//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int count=0 ;
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vector<int>adj[N+1] ;
        vector<int>visited(N+1,0);
        
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]) ;
        }
        
        dfs(1, adj ,visited);
        return count; 
    }
    
    bool dfs(int vertex ,vector<int>adj[] , vector<int>&visited){
        visited[vertex]=1;
        
        bool select =false ;
        
        for(auto i:adj[vertex]){
            if(!visited[i] && !dfs(i ,adj,visited))
                select=true ;
        }
        
        if(select )
            count+=1;
        return select ;    
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends