//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        
        int ind=0;
        int len=1;
        
        for(int center_elem=1 ;center_elem<S.size();center_elem++){
            int l=center_elem-1;
            int r=center_elem;
            
            //for even 
            
            while(l>=0 && r<S.size() && S[l]==S[r]){
                if(r-l+1>len){
                    ind=l ;
                    len=r-l+1; 
                }
                l--;
                r++;
            }
            
            l=center_elem-1;
            r=center_elem+1;
            
            while(l>=0&& r<S.size()&&S[l]==S[r]){
                if(r-l+1>len){
                    ind=l;
                    len=r-l+1;
                }
                
                l--;
                r++;
            }
        }
        
        return S.substr(ind, len);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends