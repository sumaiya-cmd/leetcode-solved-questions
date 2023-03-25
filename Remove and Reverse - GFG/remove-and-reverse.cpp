//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        unordered_map<char ,int>m ;
        
        for(int i=0;i<S.size() ;i++)
            m[S[i]]++;
        
        int i =0, j =S.size()-1 , dir =0;
        
        while(i<=j){
            if(dir==0){
                if(m[S[i]] ==1){
                    i++;
                    
                }else{
                    m[S[i]]--;
                    dir=1 ;
                    S[i]='@';
                    i++;
                }
                
            }else{
                
                if(m[S[j]]==1){
                    j--;
                }
                else{
                    m[S[j]]--;
                    dir=0 ;
                    S[j]='@';
                    j--;
                }
            }
        }
        string ans ;
        for(int i=0;i<S.size() ;i++){
            if(S[i]!='@')
                ans.push_back(S[i]);
        }
        
        if(dir==1)
            reverse(ans.begin() ,ans.end());
        return ans ;    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends