//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        // code here
        
        vector<int>temp(N);
        vector<int>ans ;
        
        for(int i=0;i<N;i++){
            
            int elem =A[i];
            int count=1;
            
            for(int j=i+1 ;j<N ;j++){
                if(A[j]==elem)
                    count++;
            }
            
            temp[i]=count;
        }
        
        for(auto i:Q){
            
            int count=0;
            
            for(int j=i[0];j<=i[1] ;j++){
                if(temp[j]==i[2])
                    count++;
            }
            ans.push_back(count);
        }
        
        return ans ;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends