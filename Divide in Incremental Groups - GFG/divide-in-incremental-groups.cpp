//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<vector<vector<int>>>memo(N+1 , vector<vector<int>>(N+1 , vector<int>(K+1 ,-1)));
        return solve( K,N,0,0,1 ,memo );
    }
    int solve(int groups, int n , int c_sum ,int c_group, int no , vector<vector<vector<int>>>&memo){
        if(c_sum==n && c_group==groups)
            return 1 ;
        
        if(c_group == groups || c_sum>n)
            return 0;
        
        if(memo[no][c_sum][c_group]!=-1)
            return memo[no][c_sum][c_group] ;
            
        int sum =0 ;
        
        for(int i=no ;i<=n ;i++){
            sum+=solve(groups, n , c_sum+i , c_group+1 , i,memo);
        }    
        
        return memo[no][c_sum][c_group] = sum ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends