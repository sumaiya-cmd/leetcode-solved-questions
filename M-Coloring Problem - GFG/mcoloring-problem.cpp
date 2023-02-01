//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>color(n , 0);
        return dfs(0, graph ,color ,m ,n );
    }
    
    bool dfs(int vertex , bool graph[101][101] , vector<int>&color, int m , int n){
        
        if(vertex ==n) 
            return true ;
        
        for(int i=1 ;i<=m ;i++){
            if(isPossible(vertex , color ,i,graph ,n)){
                color[vertex]=i;
                
                if(dfs(vertex+1 ,graph ,color ,m ,n))
                    return true ;
                
                color[vertex]=0;    
            }
        }        
        
        return false ;
    }
    
    bool isPossible(int vertex , vector<int>color ,int col,bool graph[101][101] ,int n){
        for(int i=0 ; i<n ;i++){
            if(i!=vertex && graph[vertex][i])
                if(color[i]==col)
                    return false ;
        }
        
        return true ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends