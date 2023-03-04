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
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        // code here
        set<int>set ;
        int maxi =INT_MIN;
        
        for(auto i:P)
            if(i!=-1)
                set.insert(i);
        
        for(int i=1 ;i<=N  ;i++){
            if(set.find(i)==set.end()){
                int sum=0 ;
                int node =i;
                
                while(node!=-1){
                    sum=sum*-1 ;
                    sum+=A[node-1] ;
                    maxi =max(maxi , sum);
                    node = P[node-1];
                }
            }
        }
        
        return maxi ;
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
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends