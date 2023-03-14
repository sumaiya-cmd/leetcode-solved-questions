//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
        int maxCoins(int N, vector <int> &a)
        {
                // write your code he
                a.push_back(1);
                a.insert(a.begin(),1) ;
                vector<vector<int>>dp(N+1 , vector<int>(N+1,-1)) ;
                
                return maxProfit(1,N , a,dp) ;
        }
        int maxProfit(int s , int e , vector<int>&a, vector<vector<int>>&dp ){
            if(s>e)
                return 0 ;
                
            if(dp[s][e]!=-1)
                return dp[s][e] ;
            
            int maxi =INT_MIN;
            for(int ind =s ;ind<=e ;ind++){
                int cost = a[s-1] *a[ind]*a[e+1] + maxProfit(s , ind-1 ,a,dp) +maxProfit(ind+1 , e , a,dp);
                maxi =max(maxi , cost) ;
            }    
            
            return dp[s][e]=maxi ;
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends