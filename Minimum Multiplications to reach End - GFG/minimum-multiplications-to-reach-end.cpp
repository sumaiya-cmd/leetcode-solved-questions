//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int ,int>>q ;
        q.push({0,start});
        vector<int>steps(100000 , 1e9);
        
        int mod =1e5 ;
        
        steps[start]=0;
        
        while(!q.empty()){
            int c_step =q.front().first ;
            int c_node = q.front().second ;
            
            q.pop();
            
            for(auto it:arr){
                int n_node= (c_node*it)%mod ;
                
                if((c_step+1)<steps[n_node]){
                    steps[n_node]=c_step+1 ;
                    
                    if(n_node==end)
                        return steps[n_node];
                    
                    q.push({c_step+1, n_node}) ;    
                }
            }
            
        }
        
        return -1; 
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends