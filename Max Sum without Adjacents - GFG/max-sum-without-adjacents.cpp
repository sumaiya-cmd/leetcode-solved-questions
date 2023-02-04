//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n,-1);
	    return solve(0,arr , n,dp);
	}
	int solve(int c_index, int arr[] , int n,vector<int>&dp){
	    if(c_index>=n)
	        return 0;
	   
	   if(dp[c_index]!=-1)
	        return dp[c_index] ;
	        
	   int take =arr[c_index]+solve(c_index+2 , arr , n,dp);
	   
	   int notTake = solve(c_index+1 , arr , n,dp);
	   
	   return dp[c_index]= max(take, notTake);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends