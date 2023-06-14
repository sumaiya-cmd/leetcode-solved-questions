//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m =grid.size() ;
        int n=grid[0].size() ;

        for(int row=0;row<m ;row++){
            int ans =0;
            if(grid[row][0]==1)
                dfs(grid,row, 0,ans);

            if(grid[row][n-1]==1)
                dfs(grid ,row ,n-1,ans) ;    
        }

        for(int col=0;col<n;col++){
            int ans =0 ;
            if(grid[0][col]==1)
                dfs(grid ,0 ,col, ans);

            if(grid[m-1][col] ==1)
                dfs(grid,m-1 ,col,ans ) ;    
        }

        int cnt =0;

        for(int i=0;i<m;i++){
            for(int j=0 ;j<n ;j++){
                if(grid[i][j]==1){
                    int ans=0;
                    dfs(grid , i , j ,ans); 
                    cnt +=ans ;
                }
            }
        }
        
        return cnt ;
    }
    
    void dfs(vector<vector<int>>&grid , int row, int col ,int &cnt){
        if(row<0 || row>=grid.size() ||col<0 || col>=grid[0].size() || grid[row][col]==0)
            return ;

        grid[row][col]=0 ;

        cnt++ ;

        dfs(grid , row+1 ,col,cnt);
        dfs(grid , row-1 , col,cnt);
        dfs(grid , row , col+1,cnt) ;
        dfs(grid , row, col-1,cnt) ;

        return ;    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends