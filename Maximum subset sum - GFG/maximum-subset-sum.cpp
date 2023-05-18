//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<long long >>dp(N+1 , vector<long long >(2 ,-1)) ;
        return solve(0 ,A, false , N,dp) ;
    }
    long long solve(int c_index , vector<int>&nums,bool flag,int n,vector<vector<long long >>&dp ){
        if(c_index>=n)
            return 0 ;
            
        if(dp[c_index][flag]!=-1)
            return dp[c_index][flag] ;
            
        int take=INT_MIN , notTake=INT_MIN ;
        
        if(flag){
            take =(long long)((long long )nums[c_index] + solve(c_index+1 , nums, false , n,dp)) ;
        }
        if(!flag){
            take=(long long )((long long )nums[c_index] + solve(c_index+1 , nums, false , n,dp));
            notTake =solve(c_index+1 , nums, true , n,dp) ;
        }
            
        return dp[c_index][flag]=max(take, notTake) ;    
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends