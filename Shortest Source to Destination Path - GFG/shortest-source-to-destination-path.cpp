//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> arr, int X, int Y) {
        // code here
        
        queue<pair<int ,int>>q ;
        int steps =0 ;
        
        q.push({0,0 });
        arr[0][0]=0 ;
        
        vector<pair<int,int>>dir ={{0,1} ,{1,0},{-1,0},{0,-1}} ;
        
        while(!q.empty()){
            int size= q.size();
            
             
            while(size--){
                int c_row =q.front().first ;
                int c_col =q.front().second ;
                
                q.pop() ;
                
                if(c_row==X && c_col == Y)
                    return steps ;
                    
                for(auto i:dir){
                    int n_row =i.first+c_row ;
                    int n_col =i.second+c_col;
                    
                    if(n_row>=0 && n_col>=0 && n_row<N && n_col<M && arr[n_row][n_col]!=0){
                        arr[n_row][n_col]=0 ;
                        q.push({n_row ,n_col}) ;
                    }
                }
            }
            steps++ ;
            
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends