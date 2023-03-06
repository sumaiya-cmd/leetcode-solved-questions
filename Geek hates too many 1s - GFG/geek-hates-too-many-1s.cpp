//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        int maxBit = findmaxi(n);
        // cout<<maxBit ;
        int cons =0 ;
        
        for(int i=maxBit ;i>=0 ;i--){
            
            if(((1<<i)&n)!=0){
                
                cons++;
                
                if(cons==3){
                     n= n & (~(1<<i)) ;
                     cons= 0 ;
                }
                   
            }
            else
                cons =0 ;
        }
        
        return n ;
    }
    int findmaxi(int n){
        int x=0 ;
        while((1<<x)<n)
            x++;
        
        return x ;    
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends