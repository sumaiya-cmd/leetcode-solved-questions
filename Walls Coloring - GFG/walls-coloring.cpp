//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>>dp(N+1 , vector<int>(4,-1));
        return solve(colors , N,0,0 ,dp);
    }
    int solve(vector<vector<int>>&color , int n , int c_index, int prev_color, vector<vector<int>>&dp){
        if(c_index ==n)
            return 0;
        
        if(dp[c_index][prev_color]!=-1)
            return dp[c_index][prev_color];
        
        int ans =INT_MAX ;
        
        for(int i=1;i<4 ;i++){
            if(i==prev_color)
                continue ;
            
            
            ans =min(ans , color[c_index][i-1]+solve(color , n, c_index+1 , i,dp));
            
        }
        
        return dp[c_index][prev_color] = ans ;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends