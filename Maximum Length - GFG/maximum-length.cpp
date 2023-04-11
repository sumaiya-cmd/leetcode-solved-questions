//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        // code here
        int minn = b, maxx = max(a, max(b, c)) + 1;
        
        if(a < b){
            minn = a;
            if(a < c)   minn += min(b, c);
            else    minn += c;
        }else if(b < c) minn += min(a, c);
        else   minn += c;
        
        if(minn >= (maxx/2 - 1))   return a+b+c;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends