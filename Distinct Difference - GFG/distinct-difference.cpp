//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
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
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        vector<int>ans(N) ;
        unordered_map<int,int>m;
        
        int dist=0;
        for(int i=0;i<N;i++){
            ans[i]=dist;
            
            if(m.find(A[i])==m.end())
                dist++;
                
            m[A[i]]++;
        }
        
        dist=0;
        m.clear();
        for(int i=N-1 ;i>=0 ;i--){
            ans[i]-=dist ;
            
            if(m.find(A[i])==m.end())
                dist++;
                
            m[A[i]]++;
        }
        
        return ans ;
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
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends