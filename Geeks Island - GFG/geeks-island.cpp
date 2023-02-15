//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
        vector<vector<bool>>ind(N,vector<bool>(M ,false)) ;
        vector<vector<bool>>pac(N,vector<bool>(M ,false)) ;
        
        for(int i=0;i<M;i++)    //1st row
            if(!ind[0][i])
                dfs(mat , N,M, 0,i ,ind);
        
        for(int i=0;i<N ;i++)   //1st col
            if(!ind[i][0])
                dfs(mat , N,M,i ,0 ,ind);
        
        for(int i=0;i<M ;i++)
            if(!pac[N-1][i])
                dfs(mat , N,M,N-1 , i ,pac);
        
        for(int i=0;i<N ;i++)
            if(!pac[i][M-1])
                dfs(mat , N,M,i ,M-1 ,pac) ;
        
        int ans =0 ;
        
        for(int i=0;i<N ;i++){
            for(int j=0;j<M  ;j++)
                if(ind[i][j] && pac[i][j])
                    ans+=1;
        }
        
        return ans ;
                
    }
    
    void dfs(vector<vector<int>>&mat , int row , int col , int c_row, int c_col , vector<vector<bool>>&visited){
        if(c_row<0 || c_row >=row || c_col <0 || c_col>=col || visited[c_row][c_col])
            return ;
            
        visited[c_row][c_col]=true ;
        
        if( c_col+1<col && mat[c_row][c_col]<=mat[c_row][c_col+1])
            dfs(mat , row, col , c_row, c_col+1 ,visited);
        
        if( c_col-1>=0 && mat[c_row][c_col]<=mat[c_row][c_col-1])
            dfs(mat , row, col , c_row, c_col-1 ,visited);
        
        if( c_row-1>=0 && mat[c_row][c_col]<=mat[c_row-1][c_col])
            dfs(mat , row, col , c_row-1, c_col ,visited);
        
        if( c_row+1<row && mat[c_row][c_col]<=mat[c_row+1][c_col])
            dfs(mat , row, col , c_row+1, c_col ,visited);    
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends