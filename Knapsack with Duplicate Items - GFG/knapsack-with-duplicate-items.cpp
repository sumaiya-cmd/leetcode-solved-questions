//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1)) ;
        return solve(0 ,N,W,val ,wt ,dp);
    }
    int solve(int c_index, int n , int cap, int val[] ,int wt[] ,vector<vector<int>>&dp){
        if(cap==0 || c_index==n)
            return 0;
            
        if(cap<0)
            return INT_MIN ;
        
        if(dp[c_index][cap]!=-1)
            return dp[c_index][cap] ;
        
        int take =val[c_index] +solve(c_index,n ,cap-wt[c_index] ,val ,wt,dp) ;
        int not_take =solve(c_index+1 ,n ,cap ,val ,wt ,dp) ;
        
        return dp[c_index][cap] =max(take ,not_take) ;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends