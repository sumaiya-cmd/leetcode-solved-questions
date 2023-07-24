//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size()+1, vector<int>(sum+1,0)) ;
        // return solve(0,sum ,arr,dp) ;
        int n=arr.size() ;
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        vector<int>next(sum+1 ,0);
        next[0]=1 ;
        
        for (int i = n - 1; i >= 0; i--) {
            vector<int>curr(sum+1,0) ;
            curr[0]=1 ;
            
            for (int j = 1; j <= sum; j++) {
                bool take = false;
                if (j >= arr[i]) {
                    take = next[j-arr[i]];
                }
                bool not_take = next[j];
        
                curr[j] = (take || not_take);
            }
            next=curr ;
        }

        return next[sum];

    }
    
    bool solve(int c_index, int sum ,vector<int>arr , vector<vector<int>>&dp){
        if(!sum )
            return true ;
            
        if(c_index >=arr.size()){
            if(sum==0)
                return true ;
            return false ;    
        }
        bool take =false; 
        
        
        if(dp[c_index][sum]!=-1)
            return dp[c_index][sum] ;
        
        if(sum>=arr[c_index])
            take = solve(c_index+1,sum-arr[c_index] ,arr ,dp) ;
        
        bool not_take =solve(c_index+1, sum , arr,dp) ;
        
        
        
        return dp[c_index][sum] = take||not_take  ;
    }


};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends