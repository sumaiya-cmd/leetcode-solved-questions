//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        // code here
        int i=0,j=0 ;

        
        while(i<S.size() && j<T.size()){
            int no =0;
            
            if(T[j]>='A' && T[j]<='Z'){
                
                if(T[j]!=S[i])
                    return  0;
                    
                else{
                    
                    i++;
                    j++;
                }
            }
                 
            else {
                
                while( j<T.size() &&(T[j]-'0')>=0 && (T[j] - '0')<=9){
                    
                    no = no*10 + (T[j]-'0');
                    j++ ;
                    
                }
            
                i=i+no;
            }        
            
        }
        
        return (i==S.size() && j==T.size()) ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends